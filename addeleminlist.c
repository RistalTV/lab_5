#include <stdio.h>
#include <stdlib.h>
#include "output.h"



int cE(void);
void topaddlist(void);
void printCat(void);
void loadinfile(int countStr,char cat[1],char name[30],char cost_higt[4],char cost_loW[4]);

struct mak{
        char cat[1];
        char name[30];
        char cost_higt[4];
        char cost_loW[4];
};

int addeleminlist(void){
    int elemCount=cE (),i=1;
    char kat,kat1;
    char cat[1];
    char name[30];
    char cost_higt[4];
    char cost_loW[4];
    do{
        topaddlist();
        printf("==                   На данный момент всего %-4d элементов                    ==\n",elemCount);
        printf("================================================================================\n");
        printf("1)  == Введите код категории(нажмите '!', чтобы увидеть коды категорий):");
        scanf ("%s",&kat);
        if (kat == '!')
         {
          printCat ();
          printf("1)  == Введите код категории(нажмите '!', чтобы увидеть коды категорий):");
          scanf ("%s",&kat);
         }
        else
         {
          cat[0]=kat;
         }
        system ("cls");
        topaddlist();
        printf("1)  == Введите код категории:  %c\n",cat[0]);
        printf("2)  == Введите название элемента: ");scanf ("%30s",name);
        system ("cls");
        topaddlist();
        printf("1)  == Введите код категории:  %c\n",cat[0]);
        printf("2)  == Введите название элемента: %-30s\n",name);
        printf("3)  == Введите меньшую цену элемента: ");scanf ("%4s",cost_loW);
        system ("cls");
        topaddlist();
        printf("1)  == Введите код категории:  %c\n",cat[0]);
        printf("2)  == Введите название элемента: %-30s\n",name);
        printf("3)  == Введите меньшую цену элемента: %-4s руб.\n",cost_loW);
        printf("4)  == Введите большую цену элемента(если есть,если нету то введите '0' или 'n')\n");
        printf("4)  == Введите большую цену элемента: ");scanf ("%4s",cost_higt);
        if ((cost_higt[0] == 'n')||(cost_higt[0] == 'N')){cost_higt[0]='0';}
        system ("cls");
        topaddlist();
        printf("1)  == Введите код категории:  %c\n",cat[0]);
        printf("2)  == Введите название элемента: %-30s\n",name);
        printf("3)  == Введите меньшую цену элемента: %-4s руб.\n",cost_loW);
        printf("4)  == Введите большую цену элемента: %-4s руб.\n",cost_higt);
        printf("================================================================================\n");
        printf("==      Добавить элемент в список((любая клавиша) - да, (0 или n) - нет)?     ==\n");
        printf("================================================================================\n");
        printf("                 Нажмите клавишу для продолжения: ");scanf ("%1s",&kat);
        printf("================================================================================\n");
        if ((kat=='0')&&(kat=='n')&&(kat=='N'))
         {
            printf("================================================================================\n");
            printf("==   Продолжить добавление элементов((любая клавиша) - да, (0 или n) - нет)?  ==\n");
            printf("================================================================================\n");
            printf("                 Нажмите клавишу для продолжения: ");scanf ("%1s",&kat1);
            printf("================================================================================\n");
            if (( kat1 != '0' )||( kat1 != 'n' )||( kat1 != 'N')){ i  =  1; }
            if (( kat1 == '0' )||( kat1 == 'n' )||( kat1 == 'N')){ i  =  0; }
         }
        if ((kat!='0')&&(kat!='n')&&(kat!='N'))
         {
            elemCount=cE ();
            loadinfile(elemCount,cat,name,cost_higt,cost_loW);
            printf("================================================================================\n");
            printf("==   Продолжить добавление элементов((любая клавиша) - да, (0 или n) - нет)?  ==\n");
            printf("================================================================================\n");
            printf("                 Нажмите клавишу для продолжения: ");scanf ("%1s",&kat1);
            printf("================================================================================\n");
            if (( kat1 != '0' )||( kat1 != 'n' )||( kat1 != 'N')){ i  =  1; }
            if (( kat1 == '0' )||( kat1 == 'n' )||( kat1 == 'N')){ i  =  0; }
         }
        elemCount=cE ();
      }while (i!=0);
    return 1;
}

int cE(void){
    char * filename = "C:/projects/lab_5/mak.txt";
    char k='0';
    int  elemCount=0;
    FILE* f = fopen(filename, "r+");
    while(k != EOF)                                 //Считываем количество строк
    {                                               //
        k = (char)fgetc(f);                         //Даём символ пер seechar полученный из файла
        if (k == '\n'){elemCount++;}                //Ищем '|' и прибавляем к переменной 1
    }
   fclose(f);
   if(elemCount>0){elemCount--;}
    return elemCount;
}

void loadinfile(int countStr,char cat[1],char name[30],char cost_higt[4],char cost_loW[4])
{
    countStr++;
    int end;
    char * filename = "C:/projects/lab_5/mak.txt";
    struct mak names[200];
    int i=0,i1=0,i2=0;
    char k='0';
    int elemCountStr=0,countElem=0;
                            names[countStr].cat[0]       = cat[0];
    for(i = 0; i < 30; i++){names[countStr].name[i]      = name[i];      }
    for(i = 0; i <  4; i++){names[countStr].cost_loW[i]  = cost_loW[i];  }
    for(i = 0; i <  4; i++){names[countStr].cost_higt[i] = cost_higt[i]; }
    FILE* fil = fopen(filename, "a+");
    i=0;
    while (k != '/')
     {
      fscanf(fil,"%c",&k);
      if(countElem != --countStr)
       {
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
   fclose(fil);/*
   FILE* f = fopen(filename, "w");
   for(i1=0;i1<countStr;i1++)
    {
       cat[0]=names[i1].cat[0];                                         //Загружаем
       for(i = 0; i < 30; i++){name[i]      = names[i1].name[i];}       //из экземпляров структур
       for(i = 0; i <  4; i++){cost_loW[i]  = names[i1].cost_loW[i];}   //в массивы
       for(i = 0; i <  4; i++){cost_higt[i] = names[i1].cost_higt[i];}  //
       for(i2=0;i2<countStr;i2++)
         {
           fprintf (f,"%-1s",cat);
           fprintf (f,"|");
           fprintf (f,"%-30s",name);
           fprintf (f,"|");
           fprintf (f,"%-4s",cost_loW);
           fprintf (f,"|");
           fprintf (f,"%-4s",cost_higt);
           fprintf (f,"\n");
         }
       fprintf (f,"/");
    }
   fclose(f);*/
    FILE* file = fopen (filename,"w");
    i=0;end=0;
        for(i=0;((i!=countStr)||(names[i].cat[0]!='\0'));i++){
            switch (elemCountStr) {
              case (0) :
                k = names[i].cat[i1]      ;
                i1++;
                if((i1>=1)||(names[i].cat[i1]=='\0'))
                  {
                    fprintf (file,"|");
                    k='|';
                    i1=0;
                  }
                fprintf (file,"%c",k);break;
              case (1) :
                k = names[i].name[i1]     ;
                i1++;
                if((i1>=30||(names[i].name[i1]=='\0')))
                  {
                    fprintf (file,"|");
                    k='|';
                    i1=0;
                  }
                fprintf (file,"%c",k);
                break;
              case (2) :
                k = names[i].cost_loW[i1] ;
                i1++;
                if((i1>=4||(names[i].cost_loW[i1]=='\0')))
                  {
                    fprintf (file,"|");
                    k='|';
                    i1=0;
                  }
                fprintf (file,"%c",k);
                break;
              case (3) :
                k = names[i].cost_higt[i1];
                i1++;
                if((i1>=4)||(names[i].cost_higt[i1]=='\0'))
                  {
                    fprintf (file,"\n");
                    k='|';
                    i1=0;
                  }
                fprintf (file,"%c",k);
                break;
            }
            if(k=='|')
               {
                i1=0;
                elemCountStr++;
                if (elemCountStr>3)
                 {
                  elemCountStr=0;
                  i++;
                 }
               }
        }
    fclose (file);
}
