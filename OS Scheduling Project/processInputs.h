#ifndef PROCESSINPUTS_H_INCLUDED
#define PROCESSINPUTS_H_INCLUDED
#include "Structure.h"



void inputDataFCFS(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){

        SetColor(i+9);
        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input BT : ");
        scanf("%i",&process->BT[i]);
        printf("\n");


        if(process->AT[i] < minAt){             // Finding the earliest process
            minAt = process->AT[i];
            process->currentProcess = i;
        }
        process->isProcess[i] = 0;
    }
}

void InputDataSJF(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input BT : ");
        scanf("%i",&process->BT[i]);
        printf("\n");


        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void InputDataSRTF(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){

        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input BT : ");
        scanf("%i",&process->BT[i]);
        printf("\n");

        processCopy->BT[i] = process->BT[i];

        process->isProcess[i] = 0;
        process->isFirst[i] = 1;

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void InputDataPreemptive(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");


    int minAt = 10000;

    for(int i = 0; i < process->size; i++){

        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input Priority : ");
        scanf("%i",&process->P[i]);
        printf("\n               Input BT : ");
        scanf("%i",&process->BT[i]);
        printf("\n");

        processCopy->BT[i] = process->BT[i];
        process->isProcess[i] = 0;
        process->isFirst[i] = 1;

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void InputDataNonPreemptive(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");

    int minAt = 10000;

    for(int i = 0; i < process->size; i++){

        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input Priority : ");
        scanf("%i",&process->P[i]);
        printf("\n               Input BT : ");
        scanf("%i",&process->BT[i]);
        printf("\n");

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}


// IO Burst

void InputFCFS_IO_Burst(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");


    int minAt = 10000;

    for(int i = 0; i < process->size; i++){

        SetColor(i+9);
        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input CPU 1 : ");
        scanf("%i",&process->CPU_1[i]);
        printf("\n               Input IO : ");
        scanf("%i",&process->IO[i]);
        printf("\n               Input CPU 2 : ");
        scanf("%i",&process->CPU_2[i]);
        printf("\n");

        processCopy->AT[i] = process->AT[i];

        process->isFirst[i] = 1;
        process->isIODone[i] = 0;


        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }

        process->isProcess[i] = 0;
    }
}

void InputSJF_IO_Burst(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");
    int minAt = 10000;

    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input CPU 1 : ");
        scanf("%i",&process->CPU_1[i]);
        printf("\n               Input IO : ");
        scanf("%i",&process->IO[i]);
        printf("\n               Input CPU 2 : ");
        scanf("%i",&process->CPU_2[i]);
        printf("\n");

        processCopy->AT[i] = process->AT[i];

        process->isFirst[i] = 1;
        process->isIODone[i] = 0;


        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->CPU_1[i] < process->CPU_1[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}

void InputPriority_IO_Burst(){

    printf("\n               how many process? > ");
    scanf("%i", &process->size);
    printf("\n\n ");
    int minAt = 10000;


    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        printf("\n               Input Name : ");
        scanf("%s",&process->name[i]);
        printf("\n               Input AT : ");
        scanf("%i",&process->AT[i]);
        printf("\n               Input Priority : ");
        scanf("%i",&process->P[i]);
        printf("\n               Input CPU 1 : ");
        scanf("%i",&process->CPU_1[i]);
        printf("\n               Input IO : ");
        scanf("%i",&process->IO[i]);
        printf("\n               Input CPU 2 : ");
        scanf("%i",&process->CPU_2[i]);
        printf("\n");

        processCopy->AT[i] = process->AT[i];

        process->isFirst[i] = 1;
        process->isIODone[i] = 0;

        if(process->AT[i] < minAt){
            minAt = process->AT[i];
            process->currentProcess = i;
        }else if (process->AT[i] == minAt){
            if(process->BT[i] < process->BT[process->currentProcess]){
                minAt = process->AT[i];
                process->currentProcess = i;
            }
        }

        process->isProcess[i] = 0;
    }
}


#endif // PROCESSINPUTS_H_INCLUDED
