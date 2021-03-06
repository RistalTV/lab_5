//=====================================================================
//==    Этот файл отвечает за то, чтобы выводить разные надписи      ==
//=====================================================================
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "check.h"

void gui_chouse_sel(void);
void logo(void);

void output_str_1(int loc,int cat1){
    setlocale(LC_ALL, "Russian");
    if (loc == 0){
        printf("==                              Покупатель                                    ==\n");
        printf("================================================================================\n");
    }
    char* category[]={"Категории",           //0
                      "Сандвичи",            //1
                      "Картофель и стартеры",//2
                      "Салаты и роллы",      //3
                      "Десерты и выпечка",   //4
                      "Напитки и коктейли",  //5
                      "Кофе, чай",           //6
                      "Соусы",               //7
                      "МакЗавтрак",          //8
                      "Другие продукты"};    //9
    if (loc == 1){
        system("cls");
        printf("==    Покупатель    ==    %-20s    ==                          ==\n",category[cat1]);
        printf("================================================================================\n");
    }
    if (loc == 2){
        logo ();
        printf("==                               Продавец                                     ==\n");
        printf("================================================================================\n");
        gui_chouse_sel();
    }
}

void output_str_2(int number,char name[30],char cost1[4],char cost2[4]){
    setlocale(LC_ALL, "Russian");

    if (cost2[0] == '0'){
        printf("== %-2d) =   %-30s           %-4s  руб.           ==\n",number,name,cost1);
    }
    if (cost2[0] != '0'){
        printf("== %-2d) =   %-30s           %-4s руб. / %-4s руб.==\n",number,name,cost1,cost2);
    }
}

void logo(void){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");
    printf("================================================================================\n");
    printf("=░░▓▓▓▓▓▓░░▓▓▓▓▓▓░░Никто не может сделать это так,░░░░░░░░░░░░░░░░░░░░░░░░░░░░░=\n");
    printf("=░▓▓░░░░░▓▓░░░░░▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░как это делает McDonald's░░░░=\n");
    printf("=░▓▓░░░░░▓▓░░░░░▓▓░░░░░░░▓▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░1979г.░=\n");
    printf("=░▓▓░░░░░▓▓░░░░░▓▓░░▓▓▓░░▓▓░░▓░░▓▓▓▓░░▓▓▓▓░░░░▓▓▓▓░▓▓░░░░▓▓▓▓▓░▓▓░░▓▓▓▓▓░░░░░░░=\n");
    printf("=░▓▓░░░░░▓▓░░░░░▓▓░▓▓░░░░▓▓░░▓░▓▓░░▓▓░▓▓░▓▓░▓▓░░▓▓░▓▓░░░░▓▓░░▓░░▓░▓▓░░░▓▓░░░░░░=\n");
    printf("=░▓▓░░░░░▓▓░░░░░▓▓░▓▓░░░░▓▓░░▓░▓▓░░▓▓░▓▓░▓▓░▓▓░░▓▓░▓▓░░░░▓▓░░▓░░░░░░▓▓░░░░░░░░░=\n");
    printf("=░▓▓░░░░░▓▓░░░░░▓▓░▓▓░░░░▓▓░░▓░▓▓░░▓▓░▓▓░▓▓░▓▓▓▓▓▓░▓▓░░░░▓▓░░▓░░░▓▓░░░▓▓░░░░░░░=\n");
    printf("=░▓▓░░░░░▓▓░░░░░▓▓░░▓▓▓░░▓▓▓▓▓░░▓▓▓▓░░▓▓░▓▓░▓▓░░▓▓░▓▓▓▓▓░▓▓▓▓▓░░░░▓▓▓▓▓░░░░░░░░=\n");
    printf("================================================================================\n");
}

int input_str_2(void){
    int input;

    setlocale(LC_ALL, "Russian");
    printf("================================================================================\n");
    input=checkNoNum();
    printf("================================================================================\n");
    return input;
}

char input_str_1(void){
    char input;

        setlocale(LC_ALL, "Russian");
        printf("================================================================================\n");
        printf("        Введите число: ");
        scanf("%c",&input);
        printf("================================================================================\n");
        return input;}

char input_str_3(void){
    char input[30];

        setlocale(LC_ALL, "Russian");
        printf("================================================================================\n");
        printf("  Введите имя элемента, которого хотите найти: ");
        scanf("%s",input);
        printf("================================================================================\n");
        return *input;
}

int gui(void){
    system("cls"); //system("cls"); in windows
    int input;
    logo();
    printf("==                             McDonald?s                                     ==\n");
    printf("==                      Выбирите один из вариантов                            ==\n");
    printf("==                    1)Сотрудник                                             ==\n");
    printf("==                    2)Покупатель                                            ==\n");
    printf("==                    0)Выход                                                 ==\n");
    input=input_str_2();
    return input;
}

void gui_chouse_cat(void){
    system("cls"); //system("cls"); in windows
    logo();
    output_str_1(0,1);
    printf("==                       Выбирете нужную категорию                            ==\n");
    printf("==  1)Сандвичи                6)Кофе, чай                                     ==\n");
    printf("==  2)Картофель и стартеры    7)Соусы                                         ==\n");
    printf("==  3)Салаты и роллы          8)МакЗавтрак                                    ==\n");
    printf("==  4)Десерты и выпечка       9)Другие продукты                               ==\n");
    printf("==  5)Напитки и коктейли      0)Вернуться к выбору пользователя               ==\n");
}

void endlist(void){
    printf("================================================================================\n");
    printf("==              Введите 0, чтобы вернуться к выбору пользователя              ==\n");
    printf("==               Введите любое значение чтобы выбрать категорию               ==\n");
}

void topseelist(void){
    system ("cls");
    printf ("================================================================================\n");
    printf ("==                         Просмотр файла                                     ==\n");
    printf ("================================================================================\n");
}

void topdellist(void){
    system ("cls");
    printf ("================================================================================\n");
    printf ("==                         Удаление строки                                    ==\n");
    printf ("================================================================================\n");
}

void topsearchlist(void){
    system ("cls");
    printf ("================================================================================\n");
    printf ("==                         Поиск элемента                                     ==\n");
    printf ("================================================================================\n");
}

void topaddlist(void){
    system ("cls");
    printf ("================================================================================\n");
    printf ("==--->--->--->--->--->--->---=>Запись в файл<=---<---<---<---<---<---<---<----==\n");
    printf ("================================================================================\n");
}

void printCat(void){
    printf("================================================================================\n");
    printf("==  1)Сандвичи                6)Кофе, чай                                     ==\n");
    printf("==  2)Картофель и стартеры    7)Соусы                                         ==\n");
    printf("==  3)Салаты и роллы          8)МакЗавтрак                                    ==\n");
    printf("==  4)Десерты и выпечка       9)Другие продукты                               ==\n");
    printf("==  5)Напитки и коктейли                                                      ==\n");
    printf("================================================================================\n");
}

void endoutputlist(void){
    printf("\n================================================================================\n");
    printf("==          Введите любое значение , чтобы выйти из просмотра                 ==\n");
    printf("==          Введите 0, чтобы выйти к меню выбора пользователя                 ==\n");
    printf("==                 Введите 1, чтобы выйти из программы                        ==\n");
}

void endoutputlist1(void){
    printf("\n================================================================================\n");
    printf("==            Введите номер стоки, которую хотите удалить                     ==\n");
    printf("==          Введите 0, чтобы выйти к меню выбора пользователя                 ==\n");
    printf("\n================================================================================\n");
}

void endoutputlist2(void){
    printf("\n================================================================================\n");
    printf("==            Введите Любое значение для продолжения поиска                   ==\n");
    printf("==          Введите 0, чтобы выйти к меню выбора пользователя                 ==\n");
}

void gui_chouse_sel(void){
    printf("==                       Выбирете нужную категорию                            ==\n");
    printf("==  0)Вернуться к выбору пользователя                                         ==\n");
    printf("==  1)Добавить элементы в список                                              ==\n");
    printf("==  2)Удалить элементы из списка                                              ==\n");
    printf("==  3)Вывести список                                                          ==\n");
    printf("==  4)Поиск элемента                                                          ==\n");
}

void warningNoNom(void){
    printf("\n================================================================================\n");
    printf("==                    Ошибка неправильного ввода значения                     ==\n");
    printf("==                   Введите верное значение ввода значение                   ==\n");
    printf("\n================================================================================\n");
}
