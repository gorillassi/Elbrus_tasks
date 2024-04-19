#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FIFO_FILE "myfifo"

int fifo_fd;

int main() {
    char message1[BUFSIZ], message2[BUFSIZ];

    if (mkfifo(FIFO_FILE, 0666) == -1) {
        if (errno != EEXIST) {
            printf("Не получилось сделать fifo файл\n");
            return 1;
        }
    }

    do {
        fifo_fd = open(FIFO_FILE, O_RDONLY);

        if (fifo_fd == -1) {
            printf("Ошибка открытия fifo файла\n");
            return 2;
        }

        if (read(fifo_fd, message1, sizeof(message1)) == -1) {
            printf("Ошибка чтения из fifo файла\n");
        }
        printf("User 1: %s\n", message1);

        close(fifo_fd);

        fifo_fd = open(FIFO_FILE, O_WRONLY);

        if (fifo_fd == -1) {
            printf("Ошибка открытия fifo файла\n");
            return 2;
        }

        printf("Введите сообщение (q для выхода): \n");

        fgets(message2, sizeof(message2), stdin);
        if (write(fifo_fd, message2, strlen(message2) + 1) == -1) {
            printf("Ошибка записи сообщения в fifo файл\n");
            return 3;
        }

        close(fifo_fd);
    } while (strcmp(message2, "q\n") != 0);
    unlink(FIFO_FILE);

    return 0;
}
