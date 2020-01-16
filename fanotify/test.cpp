#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/fanotify.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int fan;
    char buf[4096];
    char fdpath[32];
    char path[PATH_MAX + 1];
    ssize_t buflen, linklen;
    struct fanotify_event_metadata *metadata;

    // Init fanotify structure
    fan = fanotify_init(FAN_CLASS_NOTIF, O_RDWR);
    if(fan == -1)
    {
        perror("fanotify_init");
        exit(EXIT_FAILURE);
    }

    int ret = fanotify_mark(fan,
                            FAN_MARK_ADD,
                            //FAN_CREATE | FAN_EVENT_ON_CHILD,
                            FAN_ACCESS | FAN_OPEN | FAN_EVENT_ON_CHILD,

                            AT_FDCWD,
                            "test"
                            );
    if(ret == -1)
    {
        perror("fanotify_mark");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        buflen = read(fan, buf, sizeof(buf));
        metadata = (struct fanotify_event_metadata*)&buf;

        while(FAN_EVENT_OK(metadata, buflen))
        {
            if (metadata->mask & FAN_Q_OVERFLOW)
            {
                printf("Queue overflow!\n");
                continue;
            }

            // Resolve path, using automatically opened fd
            sprintf(fdpath, "/proc/self/fd/%d", metadata->fd);
            linklen = readlink(fdpath, path, sizeof(path) - 1);
            path[linklen] = '\0';
            printf("%s\n", path);

            close(metadata->fd);
            metadata = FAN_EVENT_NEXT(metadata, buflen);
        }
    }
}
