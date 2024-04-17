#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Имя файла не было передано\n");
        return 1;
    }

    FILE *fp;
    char *name = argv[1];

    if ((fp = fopen(name, "r")) == NULL) {
        printf("Не удалось открыть файл\n");
        return 2;
    }

    pid_t pid;

    switch (pid = fork()) {
        case -1:
            printf("Произошла ошибка!\n");
            break;
        case 0:
            FILE *S1;
            if ((S1 = fopen("S1.txt", "w")) == NULL) {
                printf("Произошла ошибка в открытии файла для записи(1)\n");
                fclose(S1);
            }

            char buffer[BUFFER_SIZE];
            size_t bytesRead;

            while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fp)) > 0){
                fwrite(buffer, 1, bytesRead, S1);
            }

            fclose(S1);
            
            if ((S1 = fopen("S1.txt", "r")) == NULL) {
                printf("Произошла ошибка в открытии файла для чтения(1)\n");
                fclose(S1);
            }
            
            printf("Содержимое файла потомка: \n");
            printf("\n");

            while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, S1)) > 0) {
                fwrite(buffer, 1, bytesRead, stdout);
            }

            printf("\n");
            printf("\n");
            
            fclose(S1);
            break;
        default:
            waitpid(pid, NULL, 0);

            fseek(fp, 0, SEEK_SET);
            
            FILE *S2;
        
            if ((S2 = fopen("S2.txt", "w")) == NULL) {
                printf("Произошла ошибка в открытии файла для записи(2)\n");
                fclose(S2);
            }

            char buffer2[BUFFER_SIZE];
            size_t bytesRead2;

            while ((bytesRead2 = fread(buffer2, 1, BUFFER_SIZE, fp)) > 0){
                fwrite(buffer2, 1, bytesRead2, S2);
            }

            fclose(S2);
            
            fseek(fp, 0, SEEK_SET);

            if ((S2 = fopen("S2.txt", "r")) == NULL) {
                printf("Произошла ошибка в открытии файла для чтения(2)\n");
                fclose(S2);
            }

            printf("Содержимое файла родителя:\n");
            printf("\n");

            while ((bytesRead2 = fread(buffer2, 1, BUFFER_SIZE, S2)) > 0) {
                fwrite(buffer2, 1, bytesRead2, stdout);
            }
            printf("\n");

            fclose(S2);
            break;
    }

    fclose(fp);
    return 0;
}
