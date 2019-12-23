#include <stdio.h>
#include <stdlib.h>
#include <output.h>
#include <windows.h>
#define MAX_ELLEMENT 200


struct mak{
        int id;
        char cat[1];
        char name[30];
        char cost_higt[4];
        char cost_loW[4];
};
char kate(int kat);

void printstruts(int kat){
    char * filename = "C:/projects/lab_5/mak.txt";
    int i=0,i1=0;
    char k;
    char kateg;
    int  countStr=0,elemCountStr=0,countElem=0;
    kateg=kate(kat);
    FILE* f = fopen(filename, "a+");
    while(k != EOF)
    {
        k = (char)fgetc(f);
        if (k == '\n')
        {
            countStr++;
        }
    }
    struct mak name[MAX_ELLEMENT];
    fclose(f);
    FILE* fil = fopen(filename, "a+");
    i=0;
    while (k != '/')
     {
      fscanf(fil,"%c",&k);
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
