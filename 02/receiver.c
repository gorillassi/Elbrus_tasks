#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>

#define FIFO_FILE "myfifo"

int main() {
    char message[BUFSIZ];
    int fifo_fd;

    fifo_fd = open(FIFO_FILE, O_RDWR);

    do {
        printf("Введите сообщение (exit для выхода): ");
        fgets(message, BUFSIZ, stdin);

        if(write(fifo_fd, message, strlen(message) + 1) == -1){
            printf("Ошибка записи сообщения в fifo файл\n");
            return 3;
        }

        read(fifo_fd, message, BUFSIZ);       
        printf("Принято сообщение: %s\n", message);

    } while (strcmp(message, "exit\n") != 0);

    close(fifo_fd);

    return 0;
}
