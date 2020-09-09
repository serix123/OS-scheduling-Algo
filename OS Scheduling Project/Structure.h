#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#define SIZE 30

typedef struct PROCESS
{
    char name[SIZE][SIZE];
    int AT[SIZE];
    int BT[SIZE];
    int P[SIZE];
    int S[SIZE];
    int E[SIZE];
    int WT[SIZE];
    int RT[SIZE];
    int TAT[SIZE];
    int isProcess[SIZE];
    int isFirst[SIZE];

    int CPU_1[SIZE];
    int IO[SIZE];
    int CPU_2[SIZE];
    int isIODone[SIZE];

    int TQ;
    int size;
    int currentProcess;
}Process;
Process* new_process()
{
    Process *P = (Process*)malloc(sizeof(Process));
    return P;
}

Process* process;
Process *processCopy;

void createProcs(){         //create processes w/ copy
    process = new_process();
    processCopy = new_process();
}

#endif // STRUCTURE_H_INCLUDED
