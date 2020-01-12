//====================================================================================
//==Этот файл отвечает за то, чтобы фильтровать и выводить элементы файла на консоль==
//====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "output.h"
#include "addeleminlist.h"
#define MAX_ELLEMENT 200

struct mak{
        int  id;
        char save;
        char cat[1];
        char name[30];
        char cost_higt[4];
        char cost_loW[4];
};
void search(char elemser[30]);

int serarcheleminlist(void){
    system("cls"); //system("cls"); in windows
    char elemser[30];
    topsearchlist();
    *elemser=input_str_3 ();
    search (elemser);
    endoutputlist2();
    int chin = input_str_2();
    if (chin!=0){return 3;}
    if (chin==0){return 0;}
    return 0;
}
void search(char elemser[30]){
    int end=0;
    int countStr = cE();
    int max_input=0;
    char * filename = "C:/projects/lab_5/mak.txt";
    struct mak names[MAX_ELLEMENT];
    int i=0,i1=0,i2=0;
    char k='0';
    int elemCountStr=0,countElem=0;
    char cat1[1],name1[30],cost_higt1[4],cost_loW1[4];
//===================================================================
//===       Запоминаем кол-во переданных чисел                    ===
//===================================================================
    for(i=0;i<30;i++){
        if (elemser[i]!='\0'){max_input++;}
    }
//===================================================================
//===       Перевод значений экхемпляров save в значение 0        ===
//===       Назначаем id в копиях экхемпляра                      ===
//===================================================================
    for(i2=0;i2 < MAX_ELLEMENT;i2++){names[i2].save='0';} i2=1;
    for(i =0;i  < MAX_ELLEMENT;i++ ){names[i].id=i2;i2++;} i2=0;i=0;
//===================================================================
//===       Затрание мусора находившегося в памяти                ===
//===================================================================
   for(i=0;i!=MAX_ELLEMENT;i++){                                 //==
       for(i2 = 0; i2 <  1; i2++){names[i].cat[i2]       = '\0';}//==
       for(i2 = 0; i2 < 30; i2++){names[i].name[i2]      = '\0';}//==
       for(i2 = 0; i2 <  4; i2++){names[i].cost_loW[i2]  = '\0';}//==
       for(i2 = 0; i2 <  4; i2++){names[i].cost_higt[i2] = '\0';}//==
   }                                                             //==
//===================================================================
    i=0;i2=0;
//=============================================================================
//===     Считывание из файла значений в экземпляры структуры               ===
//=============================================================================
    FILE* fil = fopen(filename, "a+");
    i=0;
    while (k != EOF)
     {
      fscanf(fil,"%c",&k);
        if(k=='"'){break;}
                if (k != '|')
         {
            if (k != '\n')
             {
              switch (elemCountStr)
               {
                case (0) : names[countElem].cat[i]       =  k;i++;if(i>=1) {i=0;} break;
                case (1) : names[countElem].name[i]      =  k;i++;if(i>=30){i=0;} break;
                case (2) : names[countElem].cost_loW[i]  =  k;i++;if(i>=4) {i=0;} break;
                case (3) : names[countElem].cost_higt[i] =  k;i++;if(i>=4) {i=0;} break;
               }
             }else{end++;}
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
        if (end>countElem){break;}
     }
   fclose(fil);                                                            //==
//=============================================================================
//===     Изменение конкретно указанного экземпляра                         ===
//=============================================================================
   i=0;i2=0;i1=0;
   for (i=0;i<MAX_ELLEMENT;i++){
       for(i2=0;i2<=max_input;i2++){
       if(names[i].name[0]!=elemser[0]){break;}
       if(names[i].name[1]!=elemser[1]){break;}
       if(names[i].name[2]!=elemser[2]){break;}
       if(names[i].name[i2] == elemser[i2]){
           names[i].save = '1';
       }
       }
   }
//=============================================================================
//===     Занесение экземпляров структуры в файл                            ===
//=============================================================================
      i=0;end=0;i1=0;i2=0;

       while(i!=countStr){
            if(names[i].save=='1')
              {
               cat1[0]=names[i].cat[0];
               for (i1=0;i1<30;i1++){name1[i1]          = names[i].name[i1];}
               for (i1=0;i1<4;i1++){cost_loW1[i1]      = names[i].cost_loW[i1];}
               for (i1=0;i1<4;i1++){cost_higt1[i1]     = names[i].cost_higt[i1];}
               printf ("%-3d|%c|%-30s|%-4s руб.|%-4s руб.|\n",names[i].id,cat1[0],name1,cost_loW1,cost_higt1);
               for (i1=0;i1<30;i1++){name1[i1]          = '\0';}
               for (i1=0;i1<30;i1++){cost_loW1[i1]      = '\0';}
               for (i1=0;i1<30;i1++){cost_higt1[i1]     = '\0';}
               i++;
            }
            if(names[i].save=='0'){i++;}
       }
}
