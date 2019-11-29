#include <stdio.h>
#include <stdlib.h>

struct mak
{
    char name[20];
    struct category{
        char name[30];
        char cost_higt[4];
        char cost_loW[4];
    };

};

void output_str_1(int loc,char cat1[20],char cat2[20]);
void output_str_2(char number[2],int loc1,char name[25],char cost[4]);
char output_str_3(void);
char input_str_2(void);

//----------------------------------------------------------------------------------------------------------//
void client(void)
{
  system("clear"); //system("cls"); in windows


  FILE * ptrFile = fopen( "mak.txt" , "rb" );

    if (ptrFile == NULL){fputs("Ошибка файла", stderr);exit(1);};
    // определяем размер файла
    fseek(ptrFile , 0 , SEEK_END);                          // устанавливаем позицию в конец файла
    unsigned long lSize = ftell(ptrFile);                            // получаем размер в байтах
    rewind (ptrFile);                                       // устанавливаем указатель в конец файла

    char * buffer = (char*) malloc(sizeof(char) * lSize); // выделить память для хранения содержимого файла
    if (buffer == NULL){fputs("Ошибка памяти", stderr);exit(2);};

    size_t result = fread(buffer, 1, lSize, ptrFile);       // считываем файл в буфер
    if (result != lSize){fputs("Ошибка чтения", stderr);exit (3);};

    //содержимое файла теперь находится в буфере
    puts(buffer);
printf("%s",buffer);
    // завершение работы
    fclose (ptrFile);
    free (buffer);
}
//----------------------------------------------------------------------------------------------------------//
