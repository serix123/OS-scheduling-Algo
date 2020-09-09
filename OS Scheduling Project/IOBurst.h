#ifndef IOBURST_H_INCLUDED
#define IOBURST_H_INCLUDED
#include "Structure.h"
#include "processInputs.h"
#include "ConsoleColor.h"
#define MIN 10000

void FCFS_IOBurst(){

    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess] + process->CPU_1[process->currentProcess];
    processCopy->AT[process->currentProcess] = process->E[process->currentProcess] + process->IO[process->currentProcess];
    process->isIODone[process->currentProcess] = 1;

    int chart[50];
    int chartEnd[50];
    int chartSize = 0;
    int chartEndSize = 0;
    chartEnd[0] = process->AT[process->currentProcess];
    chartEndSize++;

   while(1){
        int current = process->currentProcess;
        int currentEnding = process->E[current];

        int isProcess = 1;
        int minPos = -1;
        int minAT = MIN;
        int isIdle = 0;

        for(int i = 0; i < process->size; i++){
            if(process->E[current] >= processCopy->AT[i] && i != current && !process->isProcess[i]){
                if(processCopy->AT[i] < minAT){
                    minAT = processCopy->AT[i];
                    minPos = i;
                    isProcess = 0;
                }
            }
            if(!process->isProcess[i]){
                isProcess = 0;
            }
        }

        if(!isProcess && minPos == -1){
            for(int i = 0; i < process->size; i++){
                if(minAT > processCopy->AT[i] && i != current && !process->isProcess[i]  ){
                    minAT = processCopy->AT[i];
                    minPos = i;
                }
            }
            currentEnding = minAT;
            isIdle = 1;
        }
        if(isProcess){
            chart[chartSize] = current;
            chartSize++;

            chartEnd[chartEndSize] = process->E[current];
            chartEndSize++;
            break;
        }

        if(!process->isIODone[minPos]){
            process->S[minPos] = currentEnding;
            process->E[minPos] = currentEnding +  process->CPU_1[minPos];
            processCopy->AT[minPos] = process->E[minPos] + process->IO[minPos];
            process->isIODone[minPos] = 1;
            process->currentProcess = minPos;
        }else{
            process->E[minPos] = currentEnding + process->CPU_2[minPos];
            process->isProcess[minPos] = 1;
            process->currentProcess = minPos;
        }


        chart[chartSize] = current;
        chartSize++;

        chartEnd[chartEndSize] = process->E[current];
        chartEndSize++;

        if(isIdle){
            chart[chartSize] = -1;
            chartSize++;
            chartEnd[chartEndSize] = minAT;
            chartEndSize++;
        }
    }


    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;

    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n            NAME \t AT \t CPU,I/O,CPU \t S \t E \t WT \t RT \t TAT\n\n");



    for(int i = 0; i < process->size; i++){

        SetColor(i+2);
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        process->WT[i] = process->TAT[i] - ( process->CPU_1[i] + process->IO[i] + process->CPU_2[i] );
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf("            %s \t\t %i \t %i,%i,%i \t \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->CPU_1[i],process->IO[i],process->CPU_2[i],process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }

    SetColor(LIGHTBLUE);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("   \t   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
    printf("\n            ");

    for(int i = 0; i < chartSize; i++){

        if(i != chartSize-1){
           int space = chartEnd[i+1] - chartEnd[i];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
           SetColor(chart[i]+2);

           if(chart[i] == -1)
             printf("?");
           else
             printf("%s",process->name[chart[i]]);

           for(int x = 0; x < adj_space-space_start-1; x++){
             printf(" ");
           }
        }else{

           int space = chartEnd[i] - chartEnd[i-1];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
           SetColor(chart[i]+2);
           printf("%s", process->name[chart[i]]);
        }

    }

    printf("\n           ");
    for(int i = 0; i < chartEndSize; i++){


        if(i != chartEndSize-1){
            SetColor(chart[i]+2);
            int space = chartEnd[i+1] - chartEnd[i];
            printf("%i",chartEnd[i]);
            if(chartEnd[i] > 9)
                space--;
            int length = strlen(process->name[chart[i]]) + 1 + space;

            for(int x = 0; x < length; x++){
                printf("%c",219);
            }
        }else{

            printf("%i",chartEnd[i]);
        }

    }
    printf("\n");
    SetColor(LIGHTBLUE);


}

void SJF_IOBurst(){
    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess] + process->CPU_1[process->currentProcess];
    processCopy->AT[process->currentProcess] = process->E[process->currentProcess] + process->IO[process->currentProcess];
    process->isIODone[process->currentProcess] = 1;

    int chart[50];
    int chartEnd[50];
    int chartSize = 0;
    int chartEndSize = 0;
    chartEnd[0] = process->AT[process->currentProcess];
    chartEndSize++;

   while(1){
        int current = process->currentProcess;
        int currentEnding = process->E[current];

        int isProcess = 1;
        int minPos = -1;
        int minCPU = MIN;
        int minAT = MIN;
        int isIdle = 0;

        for(int i = 0; i < process->size; i++){
            if(process->E[current] >= processCopy->AT[i] && !process->isProcess[i]){
                if(process->CPU_1[i] < minCPU && !process->isIODone[i]){
                    minCPU = process->CPU_1[i];
                    minPos = i;
                }

                if(process->CPU_2[i] < minCPU && process->isIODone[i]){
                    minCPU = process->CPU_2[i];
                    minPos = i;
                }
            }

            if(!process->isProcess[i]){
                isProcess = 0;
            }

        }


        if(!isProcess && minPos == -1){
            for(int i = 0; i < process->size; i++){
                if(minAT > processCopy->AT[i] && i != current && !process->isProcess[i]){
                    minAT = processCopy->AT[i];
                    minPos = i;
                }
            }
            currentEnding = minAT;
            isIdle = 1;
        }

        if(isProcess){
            chart[chartSize] = current;
            chartSize++;

            chartEnd[chartEndSize] = process->E[current];
            chartEndSize++;
            break;
        }

        if(!process->isIODone[minPos]){
            process->S[minPos] = currentEnding;
            process->E[minPos] = currentEnding +  process->CPU_1[minPos];
            processCopy->AT[minPos] = process->E[minPos] + process->IO[minPos];
            process->isIODone[minPos] = 1;
            process->currentProcess = minPos;
        }else{
            process->E[minPos] = currentEnding + process->CPU_2[minPos];
            process->isProcess[minPos] = 1;
            process->currentProcess = minPos;
        }
        chart[chartSize] = current;
        chartSize++;
        chartEnd[chartEndSize] = process->E[current];
        chartEndSize++;

        if(isIdle){
            chart[chartSize] = -1;
            chartSize++;
            chartEnd[chartEndSize] = minAT;
            chartEndSize++;
        }
    }


    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;

    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n            NAME \t AT \t CPU,I/O,CPU \t S \t E \t WT \t RT \t TAT\n\n");
    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        process->WT[i] = process->TAT[i] - ( process->CPU_1[i] + process->IO[i] + process->CPU_2[i] );
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];

        printf("            %s \t\t %i \t %i,%i,%i \t \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->CPU_1[i],process->IO[i],process->CPU_2[i],process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }
    SetColor(LIGHTCYAN);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("   \t   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
    printf("\n            ");

    for(int i = 0; i < chartSize; i++){

        if(i != chartSize-1){
           int space = chartEnd[i+1] - chartEnd[i];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
            SetColor(chart[i]+1);
           if(chart[i] == -1)
             printf("?");
           else
             printf("%s",process->name[chart[i]]);

           for(int x = 0; x < adj_space-space_start-1; x++){
             printf(" ");
           }
        }else{
           int space = chartEnd[i] - chartEnd[i-1];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
            SetColor(chart[i]+1);
           printf("%s", process->name[chart[i]]);
        }
    }

    printf("\n           ");
    for(int i = 0; i < chartEndSize; i++){

        if(i != chartEndSize-1){
            SetColor(chart[i]+1);
            int space = chartEnd[i+1] - chartEnd[i];
            printf("%i",chartEnd[i]);
            if(chartEnd[i] > 9)
                space--;
            int length = strlen(process->name[chart[i]]) + 1 + space;
            for(int x = 0; x < length; x++){
                printf("%c",219);
            }
        }else{
            SetColor(chart[i]+1);
            printf("%i",chartEnd[i]);
        }

    }

    printf("\n");



}

void NPP_IOBurst(){
    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess] + process->CPU_1[process->currentProcess];
    processCopy->AT[process->currentProcess] = process->E[process->currentProcess] + process->IO[process->currentProcess];
    process->isIODone[process->currentProcess] = 1;

    int chart[50];
    int chartEnd[50];
    int chartSize = 0;
    int chartEndSize = 0;
    chartEnd[0] = process->AT[process->currentProcess];
    chartEndSize++;

   while(1){
        int current = process->currentProcess;
        int currentEnding = process->E[current];
        int color = 0;
        int isProcess = 1;
        int minPos = -1;
        int minP = MIN;
        int isIdle = 0;
        color++;
        SetColor(color);
        for(int i = 0; i < process->size; i++){

            if(process->E[current] >= processCopy->AT[i] && i != current && !process->isProcess[i]){
                if(process->P[i] < minP){
                    minP = process->P[i];
                    minPos = i;
                }
            }

            if(!process->isProcess[i]){
                isProcess = 0;
            }

        }

        if(!isProcess && minPos == -1){
            for(int i = 0; i < process->size; i++){
                if(minP > processCopy->AT[i] && i != current){
                    minP = processCopy->AT[i];
                    minPos = i;
                }
            }
            currentEnding = minP;
            isIdle = 1;
        }
        if(isProcess){
            chart[chartSize] = current;
            chartSize++;

            chartEnd[chartEndSize] = process->E[current];
            chartEndSize++;
            break;
        }

        if(!process->isIODone[minPos]){
            process->S[minPos] = currentEnding;
            process->E[minPos] = currentEnding +  process->CPU_1[minPos];
            processCopy->AT[minPos] = process->E[minPos] + process->IO[minPos];
            process->isIODone[minPos] = 1;
            process->currentProcess = minPos;
            //printf("           XName: %s, S = %i, E = %i\n", process->name[minPos],process->S[minPos],process->E[minPos]);
        }else{
            process->E[minPos] = currentEnding + process->CPU_2[minPos];
            process->isProcess[minPos] = 1;
            process->currentProcess = minPos;
            //printf("           YName: %s, S = %i, E = %i\n", process->name[minPos],process->S[minPos],process->E[minPos]);
        }


        chart[chartSize] = current;
        chartSize++;

        chartEnd[chartEndSize] = process->E[current];
        chartEndSize++;

        if(isIdle){
            chart[chartSize] = -1;
            chartSize++;
            chartEnd[chartEndSize] = minP;
            chartEndSize++;
        }
    }


    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;

    SetColor(LIGHTRED);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n            NAME \t AT \t CPU,I/O,CPU \t P \t S \t E \t WT \t RT \t TAT\n\n");

    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        process->WT[i] = process->TAT[i] - ( process->CPU_1[i] + process->IO[i] + process->CPU_2[i] );
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];



        printf("            %s \t\t %i \t %i,%i,%i \t\t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->CPU_1[i],process->IO[i],process->CPU_2[i],process->P[i],process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }
    SetColor(LIGHTRED);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("   \t   \t   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
    printf("\n            ");
    for(int i = 0; i < chartSize; i++){

        if(i != chartSize-1){
           int space = chartEnd[i+1] - chartEnd[i];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
            SetColor(chart[i]+1);
           if(chart[i] == -1)
             printf("?");
           else
             printf("%s",process->name[chart[i]]);

           for(int x = 0; x < adj_space-space_start-1; x++){
             printf(" ");
           }
        }else{
           int space = chartEnd[i] - chartEnd[i-1];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
           SetColor(chart[i]+1);
           printf("%s", process->name[chart[i]]);
        }
    }

    printf("\n           ");
    for(int i = 0; i < chartEndSize; i++){

        if(i != chartEndSize-1){
            SetColor(chart[i]+1);
            int space = chartEnd[i+1] - chartEnd[i];
            printf("%i",chartEnd[i]);
            if(chartEnd[i] > 9)
                space--;
            int length = strlen(process->name[chart[i]]) + 1 + space;
            for(int x = 0; x < length; x++){
                printf("%c",219);
            }
        }else{
           SetColor(chart[i]+1);
            printf("%i",chartEnd[i]);
        }

    }

    printf("\n");


}


#endif // IOBURST_H_INCLUDED
