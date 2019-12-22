#include <stdio.h>
#include <stdlib.h>
#include <output.h>
#include <windows.h>
#define MAX_ELLEMENT 200

typedef struct mak{
        int id;
        char cat[1];
        char name[30];
        char cost_higt[4];
        char cost_loW[4];
}makd;

void printstruts(char kat){
    int i=0,i1=0;
    char k;
    int  countStr=0,elemCountStr=0,countElem=0;
    FILE* f = fopen("mak.txt", "a+");
    while(k != EOF)  //Считываем количество строк
    {                                                   //
        k = (char)fgetc(f);                       //Даём символ пер seechar полученный из файла
 //       printf("%c",k);
        if (k == '\n'){countStr++;}               //Ищем '|' и прибавляем к переменной 1
    }
    countStr--;
    makd name[MAX_ELLEMENT];
    fclose(f);
    FILE* fil = fopen("/home/ristal/test1/mak.txt", "a+");
    i=0;
    while (fscanf(fil,"%c",&k) != '"')
     {
      if(countElem != countStr)
       {
        if (k != '|')
         {
            if (k != '\n')
             {
              switch (elemCountStr)
               {
                case (0) : name[countElem].cat[i]       =  k;i++;if(i>=1) {i=0;} break;
                case (1) : name[countElem].name[i]      =  k;i++;if(i>=30){i=0;} break;
                case (2) : name[countElem].cost_loW[i]  =  k;i++;if(i>=4) {i=0;} break;
                case (3) : name[countElem].cost_higt[i] =  k;i++;if(i>=4) {i=0;} name[countElem].id=countElem;break;
               }
             }
         }
        if(k=='|')
           {
            i=0;
            elemCountStr++;
            if (elemCountStr>3)
             {
              elemCountStr=0;
              countElem++;
             }
           }
       }
     }
   fclose(fil);
    for (i=0;i!=countStr;i++){
        if(kat == name->cat[0]){i1++;
            output_str_2(i1,name->name,name->cost_loW,name->cost_higt);
        }
    }
    i1=0;
}
