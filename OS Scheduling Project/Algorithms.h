#ifndef ALGORITHMS_H_INCLUDED
#define ALGORITHMS_H_INCLUDED
#include "Structure.h"
#include "processInputs.h"
#include "ConsoleColor.h"
#define MIN 10000

void FCFS(){
    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->S[process->currentProcess] + process->BT[process->currentProcess];
    process->isProcess[process->currentProcess] = 1;

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
        int isIdle = 0;
        int minAT = MIN;

        for(int i = 0; i < process->size; i++){
            if(process->E[current] >= process->AT[i] && i != current && !process->isProcess[i]){
                if(process->AT[i] < minAT){
                    minAT = process->AT[i];
                    minPos = i;
                }
            }
            if(!process->isProcess[i]){
                isProcess = 0;
            }

        }
        if(!isProcess && minPos == -1){
            for(int i = 0; i < process->size; i++){
                if(minAT > process->AT[i] && i != current && !process->isProcess[i]){
                    minAT = process->AT[i];
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
        process->S[minPos] = currentEnding;
        process->E[minPos] = currentEnding +  process->BT[minPos];
        process->isProcess[minPos] = 1;
        process->currentProcess = minPos;

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

    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n            NAME\t AT \t BT \t S \t E \t WT \t RT \t TAT\n\n");

    for(int i = 0; i < process->size; i++){

        SetColor(i+2);
        process->WT[i] = process->S[i] - process->AT[i];
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];

        printf("            %s \t\t %i \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->BT[i], process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }

    SetColor(LIGHTBLUE);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
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

    printf("\n            ");
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
            SetColor(chart[i]+2);
            printf("%i",chartEnd[i]);
        }
    }
    printf("\n");
    SetColor(LIGHTBLUE);
}

void SJF(){
    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->S[process->currentProcess] + process->BT[process->currentProcess];
    process->isProcess[process->currentProcess] = 1;

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
        int isIdle = 0;
        int minBT = MIN;
        int minAT = MIN;

        for(int i = 0; i < process->size; i++){

            if(process->E[current] >= process->AT[i] && i != current && !process->isProcess[i]){
                if(process->BT[i] < minBT){
                    minBT = process->BT[i];
                    minPos = i;
                }
            }
            if(!process->isProcess[i]){
                isProcess = 0;
            }
        }
        if(!isProcess && minPos == -1){
            for(int i = 0; i < process->size; i++){
                if(minAT > process->AT[i] && i != current && !process->isProcess[i] ){
                    minAT = process->AT[i];
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

        process->S[minPos] = currentEnding;
        process->E[minPos] = currentEnding +  process->BT[minPos];
        process->isProcess[minPos] = 1;
        process->currentProcess = minPos;


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
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n            NAME\t AT \t BT \t S \t E \t WT \t RT \t TAT\n\n");

    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        process->WT[i] = process->S[i] - process->AT[i];
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf("            %s \t\t %i \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->BT[i], process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }

    SetColor(LIGHTCYAN);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
    printf("\n           ");

    for(int i = 0; i < chartSize; i++){


        SetColor(i+1);
        if(i != chartSize-1){
           int space = chartEnd[i+1] - chartEnd[i];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }

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

           printf("%s", process->name[chart[i]]);
        }
    }

    printf("\n            ");

    for(int i = 0; i < chartEndSize; i++){

        SetColor(i+1);
        if(i != chartEndSize-1){

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
    SetColor(LIGHTCYAN);

}

void SRTF(){

    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess];
    process->isFirst[process->currentProcess] = 0;
    int currentEnding = 0;
    int doneCnt = 0;
    int chart[50];
    int chartEnd[50];
    int chartSize = 0;
    int chartEndSize = 0;
    chart[0] = process->currentProcess;
    chartEnd[0] = process->E[process->currentProcess];
    chartSize++;
    chartEndSize++;

    while(1){
        int current = process->currentProcess;

        int minPos = 0;
        int minScore = 1000;

        for(int i = 0; i < process->size; i++){

            if(process->E[current] >= process->AT[i] && !process->isProcess[i] && current != i){

                if(processCopy->BT[current] > processCopy->BT[i] || processCopy->BT[current] == 0){

                    if(processCopy->BT[i] < minScore){
                        minScore = processCopy->BT[i];
                        minPos = i;
                    }
                }
            }
        }

        if(minScore != 1000){
            int pos = minPos;
            process->currentProcess = pos;
            if(process->isFirst[pos]){
                process->S[pos] = process->E[current];
                process->E[pos] = process->S[pos];
                process->isFirst[pos] = 0;
            }else{
                process->E[pos] = process->E[current];
            }


        }


        if(chart[chartSize-1] != current){
            chart[chartSize] = current;
            chartSize++;

            chartEnd[chartEndSize] = process->E[current];
            chartEndSize++;
        }

        if(doneCnt == process->size){
            chartEnd[chartEndSize] = process->E[current];
            chartEndSize++;
            break;
        }

        if(current == process->currentProcess){
            process->E[current]++;
            processCopy->BT[current]--;
            if(processCopy->BT[current] == 0){
                process->isProcess[current] = 1;
                doneCnt++;
            }

        }


    }



    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n            NAME\t AT \t BT \t S \t E \t WT \t RT \t TAT\n\n");

    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        process->WT[i] = process->TAT[i] - process->BT[i];
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf("            %s \t\t %i \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->BT[i], process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }
    SetColor(LIGHTGRAY);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
    printf("\n           ");


    for(int i = 0; i < chartSize; i++){


        if(i != chartSize-1){
           int space = chartEnd[i+1] - chartEnd[i];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
           SetColor(chart[i]+1);
           printf("%s", process->name[chart[i]]);

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
    SetColor(LIGHTGRAY);

}

void PP(){

    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->AT[process->currentProcess];
    process->isFirst[process->currentProcess] = 0;
    int currentEnding = 0;
    int doneCnt = 0;
    int chart[50];
    int chartEnd[50];
    int chartSize = 0;
    int chartEndSize = 0;
    chart[0] = process->currentProcess;
    chartEnd[0] = process->E[process->currentProcess];
    chartSize++;
    chartEndSize++;

    while(1){
        int current = process->currentProcess;


        int minPos = 0;
        int minScore = 1000;

        for(int i = 0; i < process->size; i++){
            if(process->E[current] >= process->AT[i] && !process->isProcess[i] && current != i){

                if(process->P[current] > process->P[i] || processCopy->BT[current] == 0){

                    if(process->P[i] < minScore){
                        minScore = process->P[i];
                        minPos = i;
                    }

                }

            }
        }

        if(minScore != 1000){
            int pos = minPos;
            process->currentProcess = pos;
            if(process->isFirst[pos]){
                process->S[pos] = process->E[current];
                process->E[pos] = process->S[pos];
                process->isFirst[pos] = 0;
            }else{
                process->E[pos] = process->E[current];
            }

        }

        if(chart[chartSize-1] != current){
            chart[chartSize] = current;
            chartSize++;

            chartEnd[chartEndSize] = process->E[current];
            chartEndSize++;
        }

        if(doneCnt == process->size){
            chartEnd[chartEndSize] = process->E[current];
            chartEndSize++;
            break;
        }

        if(current == process->currentProcess){
            process->E[current]++;
            processCopy->BT[current]--;
            if(processCopy->BT[current] == 0){
                process->isProcess[current] = 1;
                doneCnt++;
            }
        }
    }

    float aWT = 0;
    float aRT = 0;
    float aTAT = 0;

    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n            NAME \t AT \t BT \t P \t S \t E \t WT \t RT \t TAT\n\n");

    for(int i = 0; i < process->size; i++){
        SetColor(i+3);
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        process->WT[i] = process->TAT[i] - process->BT[i];
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf("            %s \t\t %i \t %i \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->BT[i],process->P[i], process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }

    SetColor(LIGHTGREEN);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("   \t   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n\n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
    printf("\n           ");

    for(int i = 0; i < chartSize; i++){

        if(i != chartSize-1){
           int space = chartEnd[i+1] - chartEnd[i];
           int adj_space = strlen(process->name[chart[i]]) + 1 + space;
           int space_start = adj_space/2;

           for(int x = 0; x < space_start; x++){
             printf(" ");
           }
           SetColor(chart[i]+3);
           printf("%s", process->name[chart[i]]);

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
           SetColor(chart[i]+3);
           printf("%s", process->name[chart[i]]);
        }



    }

    printf("\n           ");

    for(int i = 0; i < chartEndSize; i++){

        if(i != chartEndSize-1){
            SetColor(chart[i]+3);
            int space = chartEnd[i+1] - chartEnd[i];
            printf("%i",chartEnd[i]);
            if(chartEnd[i] > 9)
                space--;
            int length = strlen(process->name[chart[i]]) + 1 + space;

            for(int x = 0; x < length; x++){
                printf("%c",219);
            }
        }else{
            SetColor(chart[i]+3);
            printf("%i",chartEnd[i]);
        }

    }

    printf("\n");

}

void NPP(){

    process->S[process->currentProcess] = process->AT[process->currentProcess];
    process->E[process->currentProcess] = process->BT[process->currentProcess];
    process->isProcess[process->currentProcess] = 1;


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
        int isIdle = 0;
        int minP = MIN;
        int minAT = MIN;


        for(int i = 0; i < process->size; i++){
            if(process->E[current] >= process->AT[i] && i != current && !process->isProcess[i]){
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
                if(minAT > process->AT[i] && i != current && !process->isProcess[i] ){
                    minAT = process->AT[i];
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

        process->S[minPos] = currentEnding;
        process->E[minPos] = currentEnding +  process->BT[minPos];
        process->isProcess[minPos] = 1;
        process->currentProcess = minPos;



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
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n            NAME \t AT \t BT \t P \t S \t E \t WT \t RT \t TAT\n\n");
    for(int i = 0; i < process->size; i++){

        SetColor(i+1);
        process->WT[i] = process->S[i] - process->AT[i];
        process->RT[i] = process->S[i] - process->AT[i];
        process->TAT[i] = process->E[i] - process->AT[i];
        aWT += (float) process->WT[i];
        aRT += (float) process->RT[i];
        aTAT += (float) process->TAT[i];


        printf("            %s \t\t %i \t %i \t %i \t %i \t %i \t %i \t %i \t %i \n",
               process->name[i], process->AT[i], process->BT[i],process->P[i], process->S[i]
               ,process->E[i],process->WT[i],process->RT[i],process->TAT[i]);
    }
    SetColor(LIGHTRED);
    printf("\n\n           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("   \t   \t   \t   \t   \t   \t   \t   \t %.2f \t %.2f \t %.2f \n\n", aWT/=(process->size) , aRT/=(process->size) ,aTAT/=(process->size) );
    printf("\n           ");


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



#endif // ALGORITHMS_H_INCLUDED
