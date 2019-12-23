#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "select.h"

void select_in(void);
int client(void);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    select_in();
    return 0;
}
