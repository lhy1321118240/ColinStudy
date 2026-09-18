#include "copy.h"

int create(const char *srcfile, const char *destfile, int pronum, int blocksize)
{
    pid_t pid;
    int i;

    for (i = 0; i < pronum; i++) {
        pid = fork();
        if (pid == 0) {
            char offset[32];
            char bsize[32];
            sprintf(offset, "%d", i * blocksize);
            sprintf(bsize, "%d", blocksize);
            execl("./mod/Copy", "Copy", srcfile, destfile, offset, bsize, NULL);

        } else if (pid > 0) {
            continue;
        } else {
            perror("fork error");
            exit(-1);
        }
    }

    return 0;
}

