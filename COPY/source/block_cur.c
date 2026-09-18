#include "copy.h"

int block_cur(const char *srcfile, int pronum)
{
    int filesize;
    struct stat st;

   
    stat(srcfile, &st);
    filesize = st.st_size;

   
    if (filesize % pronum == 0)
        return filesize / pronum;

    
    return filesize / pronum + 1;
}

