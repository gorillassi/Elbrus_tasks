#include <stdio.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Имя файла не было передано\n");
        return 1;
    }

    char *name = argv[1];

    struct stat fileStat;

    if(stat(name, &fileStat) == -1){
        printf("Ошибка в stat");
    }

    printf("Информация для файла %s\n", name);
    printf("Тип файла: ");
    if(S_ISREG(fileStat.st_mode))
    {
        printf("обычный файл\n");
    }
    else if (S_ISDIR(fileStat.st_mode)){
        printf("каталог\n");
    }
    else if (S_ISCHR(fileStat.st_mode)){
        printf("символьное устройство\n");
    }
    else if (S_ISBLK(fileStat.st_mode)){
        printf("блочное устройство\n");
    }
    else{
        printf("неизвестно");
    }

    printf("Размер файла: %lld байт", (long long)fileStat.st_size);
    printf("\n");

    return 0;
}