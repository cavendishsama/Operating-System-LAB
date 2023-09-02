#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void printHisogram(int *hist){
    int i,j;
    for(i = 0; i < 25; i ++){
        for (j = 0; j < (int)(hist[i]); j ++){
            printf("*");
        }
    printf("\n");
    }
}

int main(){
    clock_t begin = clock();
    srand(time(NULL));
    int hist [25] = {0};
    int n = 500000;
    
    for (int j = 0; j < n; j ++){
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

    clock_t end = clock();

    printf("Number of samples= %d\n", n);
    double time_spend = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time= %f\n", time_spend);

    // printHisogram(hist);
 
}