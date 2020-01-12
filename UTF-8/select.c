//=====================================================================
//==              Этот файл отвечает за логику псевдо GUI            ==
//=====================================================================
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "output.h"
#include "check.h"
#include "deleleminlist.h"
#include "addeleminlist.h"
#include "search.h"
#include "func.h"

    int client(void);
    int seller(void);
    int client_1(int categ);

void select_in(void){
    int i=1;
    do
    {
      switch (gui())
       {
        case 1 : i = seller(); break;
        case 2 : i = client(); break;
        case 0 : i=0;          break;
       }
    }
    while(i!=0);
}

int client(void){
  system("cls"); //system("cls"); in windows
    int categ;
    int i=0;
      do {
       gui_chouse_cat();
       categ = input_str_2 ();
       switch (categ)
        {
         case (0): i = 1; return 1;
         default : i = client_1(categ);if(i==3){return 2;} break;
        }
      }while(i!=1);
   return 0;
}

int client_1(int categ){
    int i=0;
    output_str_1(1,categ);
    printstruts(categ);
    endlist();
    i=input_str_2 ();
    if(i == 0){return 3;}
    if(i != 0){return 2;}
    return 1;
}

int seller(void)
{
    int i=1,gl=0;
  do{
      system("cls"); //system("cls"); in windows
      output_str_1(2,1);
     i=input_str_2 ();
     switch (i) {
        case 0 : return 1;
        case 1 : do{gl=addeleminlist();if(gl==1){i=1;break;}}while(gl!=0);break;
        case 2 : do{gl=deleleminlist();if(gl==1){i=1;break;}}while(gl!=0);break;
        case 3 : outputlists(); gl=input_str_2 ();if ((gl!=1)&&(gl!=0)){i=1;}if ((gl!=1)&&(gl==0)){return 1;}if ((gl==1)&&(gl!=0)){i=0;}break;
        case 4 : do{gl=serarcheleminlist();if(gl==1){i=1;break;}}while(gl!=0);break;
     }
    }while(i!=0);
  return i;
}
