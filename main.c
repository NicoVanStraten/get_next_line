#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main() {
    int fd = open("file1", O_RDONLY);
    int fd2 = open("file2", O_RDONLY);

    char *file_return;

    while (file_return != NULL)
    {
        file_return = get_next_line(fd);
        if (file_return != NULL)
        {
            printf("%s", file_return);
            free(file_return);   
        }
    }
}