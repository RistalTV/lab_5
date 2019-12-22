#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "seller.h"
#include "output.h"

char gui(void);
int client(void);
int seller(void);
void gui_chouse_cat(void);
void logo(void);
char input_str_2(void);
void printstruts(char k);
char input_str_2(void);
void gui_chouse_cat(void);

int select_in(void){
    int i=1;
    int gl=0;
      switch (gui())
       {
        case ('1') : gl = seller(); if(gl == 0){i = 1;}else {i=0;} break;
        case ('2') : gl = client(); if(gl == 0){i = 1;}else {i=0;} break;
        case ('0') : i=0;             break;
        default : i=1;break;
       }
    return i;
}

int client(void){
  system("cls"); //system("cls"); in windows
    char categ;
    int i=0;
    gui_chouse_cat();
    categ=input_str_2 ();
      do {
       switch (categ)
        {
         case ('!'): return 0;
         case ('0'): i=0; break;
         default   : printstruts(categ); i=1; break;
        }
      }while(i!=1);
   return 1;
}

