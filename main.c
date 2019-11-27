#include <stdio.h>
#include <stdlib.h>
#include "seller.h"
#include "сlient.h"

char chouse_gui();
void client();
void seller();

int main()
{
    int i = 1;
    do{
     switch (chouse_gui())
      {
       case ('1') : seller(); i=0;break;
       case ('2') : client(); i=0;break;
       case ('0') : i=0;          break;
       default : chouse_gui();i=0;break;
      };
    }while (i!=0);
    return 0;
}
char chouse_gui()
{
    system("clear"); //system("cls"); in windows
    char input;
    printf("==============================================================================================\n");
    printf("==                                                                                          ==\n");
    printf("==                                        McDonald’s                                        ==\n");
    printf("==                                                                                          ==\n");
    printf("==                                Выбирите один из вариантов                                ==\n");
    printf("==                                                                                          ==\n");
    printf("==                             1)Сотрудник                                                  ==\n");
    printf("==                             2)Покупатель                                                 ==\n");
    printf("==                                                                                          ==\n");
    printf("==                             0)Выход                                                      ==\n");
    printf("==                                                                                          ==\n");
    printf("==============================================================================================\n");
    printf("==      Введите число: ");scanf("%c",&input);printf("                                                                    ==\n");
    printf("==============================================================================================\n");
    system("clear"); //system("cls"); in windows
    return input;
}
