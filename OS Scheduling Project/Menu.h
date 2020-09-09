#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Algorithms.h"
#include "IOBurst.h"
#include "processInputs.h"
#include "ConsoleColor.h"

int Menu()
{
    saved_attributes = GetDefaultTextColor();
    int ch = 0;
    SetColor(YELLOW);
    printf("\n\n");
    printf("          * * * * * * * * * * * * * *  OS Scheduling Algorithm  * * * * * * * * * * * * *\n");
    printf("\n\n");
    SetColor(LIGHTBLUE);
    printf("                      0. First Come First Serve       \n\n");
    SetColor(LIGHTCYAN);
    printf("                      1. Shortest Job First           \n\n");
    SetColor(LIGHTGRAY);
    printf("                      2. Shortest Remaining Time First\n\n");
    SetColor(LIGHTGREEN);
    printf("                      3. Preemptive Priority          \n\n");
    SetColor(LIGHTRED);
    printf("                      4. Non-Preemptive Priority      \n\n");
    SetColor(LIGHTBLUE);
    printf("                      5. First Come First Serve IO Burst      \n\n");
    SetColor(LIGHTCYAN);
    printf("                      6. Shortest Job First IO Burst          \n\n");
    SetColor(LIGHTRED);
    printf("                      7. Non-Preemptive Priority IO Burst     \n\n");
    SetColor(LIGHTMAGENTA);
    printf("                      8. Exit                         \n\n");

    SetColor(YELLOW);
    printf("          * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n                    Enter the number of your choice : ");
    scanf("%i",&ch);

    switch(ch){
    case 0:
        //FCFS
        system("cls");
        SetColor(LIGHTBLUE);
        printf("\n\n               * * * * * * * * * First Come First Serve Scheduling * * * * * * * * *\n");
        inputDataFCFS();
        SetColor(LIGHTBLUE);
        system("cls");
        printf("\n\n           * * * * * * * * * First Come First Serve Scheduling * * * * * * * * *\n");
        FCFS();
        SetColor(LIGHTBLUE);
        printf("\n           ----------------------------- press enter ----------------------------");
        getch();
        break;
     case 1:
        //SJF
        system("cls");
        SetColor(LIGHTCYAN);
        printf("\n\n               * * * * * * * * * Shortest Job First Algorithm * * * * * * * * *\n");
        InputDataSJF();
        SetColor(LIGHTCYAN);
        system("cls");
        printf(" \n\n          * * * * * * * * * Shortest Job First Algorithm * * * * * * * * *\n");
        SJF();
        SetColor(LIGHTCYAN);
        printf("\n           ----------------------------- press enter ----------------------------");
        getch();
        break;
     case 2:
        //SRTF
        system("cls");
        SetColor(LIGHTGRAY);
        printf("\n\n               * * * * * * * * * Shortest Remaining Time First Algorithm * * * * * * * * *\n");
        InputDataSRTF();
        SetColor(LIGHTGRAY);
        system("cls");
        printf("\n\n           * * * * * * * * * Shortest Remaining Time First Algorithm * * * * * * * * *\n");
        SRTF();
        SetColor(LIGHTGRAY);
        printf("\n           ----------------------------- press enter ----------------------------");
        getch();
        break;
     case 3:
        //PP
        system("cls");
        SetColor(LIGHTGREEN);
        printf("\n\n               * * * * * * * * * * * Preemptive Priority * * * * * * * * * * *\n");
        InputDataPreemptive();
        SetColor(LIGHTGREEN);
        system("cls");
        printf("\n\n               * * * * * * * * * * * Preemptive Priority * * * * * * * * * * *\n");
        PP();
        SetColor(LIGHTGREEN);
        printf("\n               ----------------------------- press enter ----------------------------");
        getch();
        break;
     case 4:
        //NPP
        system("cls");
        SetColor(LIGHTRED);
        printf("\n\n               * * * * * * * * * * * Non - Preemptive Priority * * * * * * * * * * *\n");
        InputDataNonPreemptive();
        SetColor(LIGHTRED);
        system("cls");
        printf("\n\n               * * * * * * * * * * * Non - Preemptive Priority * * * * * * * * * * *\n");
        NPP();
        SetColor(LIGHTRED);
        printf("\n               ----------------------------- press enter ----------------------------");
        getch();
        break;
     case 5:
         //FCFS IO
        system("cls");
        SetColor(LIGHTBLUE);
        printf("\n\n               * * * * * * * * * First Come First Serve IO Burst Scheduling * * * * * * * * *\n");
        InputFCFS_IO_Burst();
        SetColor(LIGHTBLUE);
        system("cls");
        printf("\n\n           * * * * * * * * * First Come First Serve IO Burst Scheduling * * * * * * * * *\n");
        FCFS_IOBurst();
        SetColor(LIGHTBLUE);
        printf("\n           ----------------------------- press enter ----------------------------");
        getch();
        break;
     case 6:
         // SJF IO
        system("cls");
        SetColor(LIGHTCYAN);
        printf("\n\n               * * * * * * * * * Shortest Job First IO Burst Algorithm * * * * * * * * *\n");
        InputSJF_IO_Burst();
        SetColor(LIGHTCYAN);
        system("cls");
        printf(" \n\n          * * * * * * * * * Shortest Job First IO Burst Algorithm * * * * * * * * *\n");
        SJF_IOBurst();
        SetColor(LIGHTCYAN);
        printf("\n           ----------------------------- press enter ----------------------------");
        getch();
        break;
     case 7:
        //NPP
        system("cls");
        SetColor(LIGHTRED);
        printf("\n\n               * * * * * * * * * * * Non - Preemptive Priority IO Burst * * * * * * * * * * *\n");
        InputPriority_IO_Burst();
        SetColor(LIGHTRED);
        system("cls");
        printf("\n\n               * * * * * * * * * * * Non - Preemptive Priority IO Burst * * * * * * * * * * *\n");
        NPP_IOBurst();
        SetColor(LIGHTRED);
        printf("\n               ----------------------------- press enter ----------------------------");
        getch();
        break;
    case 8:
        //Exit
        return 0;
    }
    return 1;
}


#endif // MENU_H_INCLUDED
