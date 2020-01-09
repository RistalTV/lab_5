//=====================================================================
//==Этот файл отвечает за то, чтобы выводить элементы файла в консоль==
//=====================================================================
#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "addeleminlist.h"

void outputlists(void){
    int i=2;
    int max=cE()+2,max1=max-1;
    char k='0';
    char * filename = "C:/projects/lab_5/mak.txt";
    FILE* f = fopen(filename, "a+");
    topseelist();
    printf ("1  |-)  ");

    while(k != EOF)
    {
        k = (char)fgetc(f);
        if(i<max){
        printf ("%c",k);
        if((k=='\n')&&(k!='/')&&(k!='\0')&&(i<=max1)&&(k!=EOF)){
            printf ("%-3d|-)  ",i);
            i++;
        }
        }
    }
    fclose(f);
    endoutputlist ();
}
