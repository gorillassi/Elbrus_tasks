#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    fd = open("non_existent_file.txt", O_WRONLY);

    if (fd == -1) {
        printf("Значение ошибки errno: %d\n", errno);

        printf("Значение ошибки из sys_errlist[]: %s\n", strerror(errno));

        perror("Ошибка perror");
    }

    return 0;
}