//=====================================================================
//==    Этот файл отвечает за то, чтобы удалять элементы в файла     ==
//=====================================================================
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
void outputlists1(void);
void del(int chin);

int deleleminlist(void){
    system("cls"); //system("cls"); in windows
    outputlists1();
    int chin = input_str_2();
    if (chin!=0){del(chin);return 3;}
    if (chin==0){return 0;}
    return 0;
}
void outputlists1(void){
    int i=2;
    char k='0';
    int max=cE()+2,max1=max-1;
    char * filename = "C:/projects/lab_5/mak.txt";
    FILE* f = fopen(filename, "a+");
    topdellist();
    printf ("1  |-)  ");
    while(k != EOF)
    {
        k = (char)fgetc(f);
        if(i<max){
        printf ("%c",k);
        if((k=='\n')&&(k!='/')&&(k!='\0')&&(i<=max1)&&(k!=EOF)){
            Sleep(250);
            printf ("%-3d|-)  ",i);
            i++;
        }
        }
    }
    fclose(f);
    endoutputlist1 ();
}

void del(int chin){
    int end=0;
    int countStr = cE();
    char * filename = "C:/projects/lab_5/mak.txt";
    struct mak names[MAX_ELLEMENT];
    int i=0,i1=0,i2=0;
    char k='0';
    int elemCountStr=0,countElem=0;
    char cat1[1],name1[30],cost_higt1[4],cost_loW1[4];
//===================================================================
//===       Перевод значений экхемпляров save в значение 1        ===
//===       Наначаем id в копиях экхемпляра                       ===
//===================================================================
    for(i2=0;i2 < MAX_ELLEMENT;i2++){names[i2].save='1';} i2=1;
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
       if(names[i].id == chin){
           names[i].save = '0';
       }
   }
//=============================================================================
//===     Занесение экземпляров структуры в файл                            ===
//=============================================================================
      FILE* file = fopen (filename,"wb");
      i=0;end=0;i1=0;i2=0;

       while(i!=countStr){
            if(names[i].save=='1')
              {
               cat1[0]=names[i].cat[0];
               for (i1=0;i1<30;i1++){name1[i1]          = names[i].name[i1];}
               for (i1=0;i1<4;i1++){cost_loW1[i1]      = names[i].cost_loW[i1];}
               for (i1=0;i1<4;i1++){cost_higt1[i1]     = names[i].cost_higt[i1];}
               fprintf (file,"%c|%-s|%-s|%-s|\n",cat1[0],name1,cost_loW1,cost_higt1);
               printf ("%c|%-s|%-4s|%-4s|\n",cat1[0],name1,cost_loW1,cost_higt1);
               for (i1=0;i1<30;i1++){name1[i1]          = '\0';}
               for (i1=0;i1<30;i1++){cost_loW1[i1]      = '\0';}
               for (i1=0;i1<30;i1++){cost_higt1[i1]     = '\0';}
               i++;
            }
            if(names[i].save=='0'){i++;}
       }
    fclose (file);
}
