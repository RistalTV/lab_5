#include <stdio.h>
#include <stdlib.h>
#include "output.h"

void endoutputlist(void);
void topseelist(void);

void outputlists(void){
    int i=2;
    char k;
    char * filename = "C:/projects/lab_5/mak.txt";
    FILE* f = fopen(filename, "a+");
    topseelist();
    printf ("1  |-)  ");
    while(k != EOF)
    {
        k = (char)fgetc(f);
        if(k=='/'){break;}
        printf ("%c",k);
        if((k=='\n')&&(k!='/')&&(k!='\0')){
            printf ("%-3d|-)  ",i);
            i++;
        }

    }
    fclose(f);
    endoutputlist ();
}
