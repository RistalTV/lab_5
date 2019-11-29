#include <stdio.h>
#include <stdlib.h>

struct mak
{
    char number[2];
    char cat1[20];
    char cat2[20];
    char name[25];
    char cost[3];
};

int save(char * filename, struct mak *st, int n);
int load(char * filename);
void output_str_1(int loc,char cat1[20],char cat2[20]);
void output_str_2(char number[2],int loc1,char name[25],char cost[4]);
char output_str_3(void);
char input_str_2(void);

//----------------------------------------------------------------------------------------------------------//
void client(void)
{
  system("clear"); //system("cls"); in windows
  char * filename = "mak.dat";
      struct mak a12[] = {"1","Напитки","Горячие ","Капучино","123 ",
                          "2","Напитки","Прохладительные ","Капучино","123 ",
                          "3","Напитки","Соки и воды ","Капучино","123 ",
                          "4","Напитки","Напитки и десерты ","Капучино","123 "};
      int n = sizeof(a12) / sizeof(a12[0]);

      save(filename, a12, n);
      load(filename);

 // output_str_1(a12.person,2,a12.cat1,a12.cat2);
  //output_str_2(a12.number,2,a12.name,a12.cost);
  //system("clear"); //system("cls"); in windows
}
//----------------------------------------------------------------------------------------------------------//

// запись в файл массива структур
int save(char * filename, struct mak * st, int n)
{
    FILE * fp;
    char *c;

    // число записываемых байтов
    int size = n * sizeof(struct mak);

    if ((fp = fopen(filename, "wb")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // записываем количество структур
    c = (char *)&n;
    for (int i = 0; i<sizeof(int); i++)
    {
        putc(*c++, fp);
    }

    // посимвольно записываем в файл все структуры
    c = (char *)st;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}

// загрузка из файла массива структур
int load(char * filename)
{
    FILE * fp;
    char *c;
    int m = sizeof(int);
    int n, i;

    // выделяем память для количества данных
    int *pti = (int *)malloc(m);

    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // считываем количество структур
    c = (char *)pti;
    while (m>0)
    {
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //получаем число элементов
    n = *pti;

    // выделяем память для считанного массива структур
    struct mak * ptr = (struct mak *) malloc(n * sizeof(struct mak));
    c = (char *)ptr;
    // после записи считываем посимвольно из файла
    while ((i= getc(fp))!=EOF)
    {
        *c = i;
        c++;
    }

//*
//  перебор загруженных элементов и вывод на консоль
    printf("\n%d people in the file stored\n\n", n);

    for (int k = 0; k<n; k++)
    {
        printf("%-5d %-20s %-20s %-25s %-2s \n", k + 1, (ptr + k)->cat1, (ptr + k)->cat2,(ptr + k)->name,(ptr + k)->cost);
    }
 //*/
    free(pti);
    free(ptr);
    fclose(fp);
    return 0;
}
