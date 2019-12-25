#include <stdio.h>
#include <stdlib.h>
#include <output.h>
#include <windows.h>
#include "addeleminlist.h"
#define MAX_ELLEMENT 200


struct mak{
        int id;
        char cat[1];
        char name[30];
        char cost_higt[4];
        char cost_loW[4];
};
char kate(int kat);
int cE(void);

void printstruts(int kat){
    char * filename = "C:/projects/lab_5/mak.txt";
    int i=0,i1=0,i2=0;
    char k='0';
    char kateg;
    int  countStr=0,elemCountStr=0,countElem=0,end=0;
    kateg=kate(kat);
    FILE* f = fopen(filename, "a+");
    countStr=cE();
    struct mak name[MAX_ELLEMENT];
    fclose(f);
//===================================================================
//===       Затрание мусора находившегося в памяти                ===
//===================================================================
    for(i=0;i!=countStr;i++){                                    //==
        for(i2 = 0; i2 <  1; i2++){name[i].cat[i2]       = '\0';}//==
        for(i2 = 0; i2 < 30; i2++){name[i].name[i2]      = '\0';}//==
        for(i2 = 0; i2 <  4; i2++){name[i].cost_loW[i2]  = '\0';}//==
        for(i2 = 0; i2 <  4; i2++){name[i].cost_higt[i2] = '\0';}//==
    }                                                            //==
//===================================================================
    FILE* fil = fopen(filename, "a+");
    i=0;i1=0;
//===================================================================
//===       Чтение из файла и запись в структуры                  ===
//===================================================================
    while (k != EOF)
     {
      fscanf(fil,"%c",&k);
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
   fclose(fil);
//===================================================================
//===       Вывод на экран с поиском по категориям                ===
//===================================================================
    for (i=0;i!=countStr;i++){
        if(kateg == name[i].cat[0]){
            i1++;
            output_str_2(i1,name[i].name,name[i].cost_loW,name[i].cost_higt);
        }
    }
    i1=0;
}
char kate(int kat){
    switch (kat){
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
    }
    return 0;
}
