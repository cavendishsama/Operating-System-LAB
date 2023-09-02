#include <stdio.h>
#include <stdlib.h>

int n;           // number of processes
int i, j;        // used for iterations
int total_burst; // total cpu burst of processes

typedef struct process{
    int pid;
    int priority;
    int at; // arrival time
    int bt; // burst time
    int rmt; // remaining time
    int wt; // waiting time
    int tat; // turnaround time
} process;

/* compare two processes  by arrival time */
int compare_arrival(const void* process1, const void* process2){
    process* p1 = (process*) process1;
    process* p2 = (process*) process2;
    return p2->at < p1->at;
}

/* compare two processes  by priority */
int compare_priority(const void* process1, const void* process2){
    process* p1 = (process*) process1;
    process* p2 = (process*) process2;
    return p1->priority > p2->priority;
}

/* compare two processes  by remaining time */
int compare_RemainigTime(const void* process1, const void* process2){
    process* p1 = (process*) process1;
    process* p2 = (process*) process2;
    return p1->rmt > p2->rmt;
}

/* print all processes info */
void print_processes_info(process PCB[]){
    printf("\n%s%9s%10s%7s%6s%12s", "pid", "arrival", "priority", "burst", "wait", "turnarround");
    for(i = 0; i < n; i++)
        printf("\n%d%8d%10d%8d%7d%8d\n", 
        PCB[i].pid, PCB[i].at, PCB[i].priority, PCB[i].bt, PCB[i].wt, PCB[i].tat);
    printf("\n");
}