#include <stdio.h>
#include <stdlib.h>
#include "seller.h"
#include "сlient.h"

char gui(void);
void client(void);
void seller(void);

void select_in(void){
    int i=1;
    do
     {
      switch (gui())
       {
        case ('1') : seller(); i = 0; break;
        case ('2') : client(); i = 0; break;
        case ('0') : i=0;             break;
        default : i=1;break;
       };
     }
    while (i!=0);
}

char gui(void){
    system("clear"); //system("cls"); in windows
    char input;
    printf("==============================================================================================\n");
    printf("==                                                                                          ==\n");
    printf("==                                        McDonald’s                                        ==\n");
    printf("==                                                                                          ==\n");
    printf("==                                                                                          ==\n");
    printf("==                                                                                          ==\n");
    printf("==                                Выбирите один из вариантов                                ==\n");
    printf("==                                                                                          ==\n");
    printf("==                             1)Сотрудник                                                  ==\n");
    printf("==                             2)Покупатель                                                 ==\n");
    printf("==                                                                                          ==\n");
    printf("==                             0)Выход                                                      ==\n");
    printf("==                                                                                          ==\n");
    printf("==                                                                                          ==\n");
    printf("==                                                                                          ==\n");
    printf("==                                                                                          ==\n");
    printf("==============================================================================================\n");
    printf("==      Введите число: ");scanf("%c",&input);printf("                                                                    ==\n");
    printf("==============================================================================================\n");
    system("clear"); //system("cls"); in windows
    return input;
};