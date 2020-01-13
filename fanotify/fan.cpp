#include "fan.h"
/*
 *第一个程序是fanotify用于其他事件的示例
 以文件描述负的形式传递对象信息，这个程序将
 作为命令行参数传递的装入点标记为等待FAN_OPEN_PERM和FAN_CLOSE_WRITE类型的
 的事件。当发生权限事件，将会给出FAN_FOLLOW响应
 * */
int main(int argc, char *argv[])
{
    char buf;
    int fd, poll_num;
    nfds_t nfds;
    struct pollfd fds[2];

    /* Check mount point is supplied */

    if (argc != 2) {
        fprintf(stderr, "Usage: %s MOUNT\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Press enter key to terminate.\n");

    /* Create the file descriptor for accessing the fanotify API */

    fd = fanotify_init(FAN_CLOEXEC | FAN_CLASS_CONTENT | FAN_NONBLOCK,
                       O_RDONLY | O_LARGEFILE);
    if (fd == -1) {
        perror("fanotify_init");
        exit(EXIT_FAILURE);
    }

    /* Mark the mount for:
       - permission events before opening files
       - notification events after closing a write-enabled
       file descriptor */
    //给一个文件添加fanotify标志，有删除标志，修改标志，添加标志
    //FAN_MARK_ADD:隐藏事件将被添加到这个标志隐藏
    //这个隐藏不能是空的
    //FAN_MARK_REMOVE:删除这些隐藏标志
    //FAN_MARK_MOUNT:标志由路径决定的挂载点，这个挂载点包含被标志的路径
    //FAN_OPEN_PERM:创建一个事件，当打开一个有允许打开一个文件的权限的时候
    //一个fanotify的fd可以使用FAN_CLASS_PRE_CONTENT/FAN_CLASS_CONTENT被创建
    //FAN_CLOSE  一个文件被关闭(FAN_CLOSE_WRITE|FAN_CLOSE_NOWRITE)
    if (fanotify_mark(fd, FAN_MARK_ADD | FAN_MARK_MOUNT,
                      FAN_OPEN_PERM | FAN_CLOSE_WRITE, AT_FDCWD,
                      argv[1]) == -1) {
        perror("fanotify_mark");
        exit(EXIT_FAILURE);
    }

    /* Prepare for polling */

    nfds = 2;

    /* Console input */

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    /* Fanotify input */

    fds[1].fd = fd;
    fds[1].events = POLLIN;

    /* This is the loop to wait for incoming events */

    printf("Listening for events.\n");

    while (1) {
        poll_num = poll(fds, nfds, -1);
        if (poll_num == -1) {
            if (errno == EINTR)     /* Interrupted by a signal */
                continue;           /* Restart poll() */

            perror("poll");         /* Unexpected error */
            exit(EXIT_FAILURE);
        }

        if (poll_num > 0) {
            if (fds[0].revents & POLLIN) {

                /* Console input is available: empty stdin and quit */

                while (read(STDIN_FILENO, &buf, 1) > 0 && buf != '\n')
                    continue;
                break;
            }

            if (fds[1].revents & POLLIN) {

                /* Fanotify events are available */
                handle_events(fd);
            }
        }
    }

    printf("Listening for events stopped.\n");
    exit(EXIT_SUCCESS);
}

