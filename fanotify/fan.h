#ifndef _FAN_H_
#define _FAN_H_
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fanotify.h>
#include <unistd.h>

/* Read all available fanotify events from the file descriptor 'fd' */

static void
handle_events(int fd)
{
    //获取描述符事件信息的结构体
    const struct fanotify_event_metadata *metadata;
    struct fanotify_event_metadata buf[4096];
    ssize_t len;
    char path[PATH_MAX];
    ssize_t path_len;
    char procfd_path[PATH_MAX];
    //事件响应的信息的结构体
    //其中包含了fanotify的描述fd符字段
    //response用来表明访问文件相关权限是否被允许
    struct fanotify_response response;

    /* Loop while events can be read from fanotify file descriptor */

    for (;;) {
        /* Read some events */

        len = read(fd, (void *) &buf, sizeof(buf));
        if (len == -1 && errno != EAGAIN) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        /* Check if end of available data reached */

        if (len <= 0)
            break;

        /* Point to the first event in the buffer */
    
        metadata = buf;

        /* Loop over all events in the buffer */
        //此宏检查缓冲区元的剩余长度len
        //根据元数据结构的长度和事件长度
        //检测缓冲区中第一个元数据结构的字段
        while (FAN_EVENT_OK(metadata, len)) {

            /* Check that run-time and compile-time structures match */
            //检测运行时和编译的时结构体是否匹配
            if (metadata->vers != FANOTIFY_METADATA_VERSION) {
                fprintf(stderr,
                        "Mismatch of fanotify metadata version.\n");
                exit(EXIT_FAILURE);
            }

            /* metadata->fd contains either FAN_NOFD, indicating a
               queue overflow, or a file descriptor (a nonnegative
               integer). Here, we simply ignore queue overflow. */
            if (metadata->fd >= 0) {
                /* Handle open permission event */
                if (metadata->mask & FAN_OPEN_PERM) {
                    printf("FAN_OPEN_PERM: ");

                    /* Allow file to be opened */

                    response.fd = metadata->fd;
                    response.response = FAN_ALLOW;
                    write(fd, &response,
                          sizeof(struct fanotify_response));
                }

                /* Handle closing of writable file event */

                if (metadata->mask & FAN_CLOSE_WRITE)
                    printf("FAN_CLOSE_WRITE: ");
                /* Retrieve and print pathname of the accessed file */
                snprintf(procfd_path, sizeof(procfd_path),
                         "/proc/self/fd/%d", metadata->fd);
                //找出符号链接所指向的位置
                path_len = readlink(procfd_path, path,
                                    sizeof(path) - 1);
                if (path_len == -1) {
                    perror("readlink");
                    exit(EXIT_FAILURE);
                }

                path[path_len] = '\0';
                printf("File %s\n", path);

                /* Close the file descriptor of the event */

                close(metadata->fd);
            }
            /* Advance to next event */

            metadata = FAN_EVENT_NEXT(metadata, len);
        }
    }
}
#endif
