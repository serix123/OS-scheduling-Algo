#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Menu.h"
#include "Structure.h"



int main()
{

    createProcs();

    while(Menu())
    {
        system("cls");
    }

    return 0;
}









