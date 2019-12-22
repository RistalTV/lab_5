#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "select.h"

int select_in(void);
int client(void);

int main()
{
    int i=0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do
    {
      i = select_in();
    }
    while(i!=1);
    return 0;
}
