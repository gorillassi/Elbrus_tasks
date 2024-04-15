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

    if (mkfifo(FIFO_FILE, 0666) == -1){
        if(errno != EEXIST){
            printf("Не получилось сделать fifo файл\n");
            return 1;
        }
    }

    fifo_fd = open(FIFO_FILE, O_RDWR);
    
    if (fifo_fd == -1)
    {
        printf("Ошибка открытия fifo файла\n");
        return 2;
    }
    
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
    unlink(FIFO_FILE);

    return 0;
}
