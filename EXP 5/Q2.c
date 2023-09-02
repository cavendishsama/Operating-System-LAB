#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/wait.h>

enum { ARRAY_SIZE = 25 };
int segmentId;
const int shareSize = sizeof(int) * (ARRAY_SIZE); 
int *hist;

void calculate_smaple(int end){
    for (int j = 0; j < end; j ++){
        int counter = 0;
        for (int i = 0; i < 12; i ++){
            int random_number = rand() % 100;
            if (random_number >= 49)
                counter ++;
            else
                counter --;
            }
        hist[counter + 12] ++;
    }
}

void printHisogram(int *hist){
    int i,j;
    for(i = 0; i < 25; i ++){
        for (j = 0; j < (int)(hist[i] / 10); j ++)
            printf("*");
        printf("\n");
    }
}
int main(){
    clock_t begin = clock();
    segmentId = shmget(IPC_PRIVATE, shareSize, S_IRUSR | S_IWUSR);
    hist = (int *) shmat(segmentId, NULL, 0);
    srand(time(NULL));
    
    int n = 5000;
    
    int n1 = fork();
    int n2 = fork();
    
    calculate_smaple(n/4);
    while(wait(NULL) != -1);
    
    /* parent process */
    if (n1 != 0 && n2 != 0){
        clock_t end = clock();

        int sum = 0;
        for(int i=0; i<25; i++)
            sum += hist[i];

        printf("Number of samples= %d\n", sum);
        double time_spend = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
        printf("Time= %f\n", time_spend);
        printHisogram(hist);
    }
 
}
