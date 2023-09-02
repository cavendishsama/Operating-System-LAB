#include "./process.h"

/* round robin policy */
void RoundRobin(process PCB[]){
    int q = 1;
    printf("\ntime quantum: ");
    scanf("%d", &q);

    int time = 0;
    i = 0;

    while(total_burst != 0){
        if(PCB[i].rmt >= q){
            j = (i+1)%n;
            while(j != i){
                if(PCB[j].rmt != 0)
                    PCB[j].wt += q;
                j = (j+1)%n;
            }
            PCB[i].rmt -= q;
            total_burst -= q;
            i = (i+1)%n;            
        }else if(PCB[i].rmt > 0 && PCB[i].rmt < q){
            j = (i+1)%n;
            while(j != i){
                if(PCB[j].rmt != 0)
                    PCB[j].wt += PCB[i].rmt;
                j = (j+1)%n;
            }
            total_burst -= PCB[i].rmt;
            PCB[i].rmt = 0;
            i = (i+1)%n; 
        }else if(PCB[i].rmt == 0){
            i = (i+1)%n;
        }
    }

    for(i = 0; i < n; i++)
        PCB[i].tat = PCB[i].wt + PCB[i].bt;
    
    printf("\nRoundRobin:\n");
    print_processes_info(PCB);
}

int main(int argc, char const *argv[]){
    printf("number of processes: ");
    scanf("%d", &n);

    process PCB[n];
    total_burst = 0;

    printf("\nEnter Burst Time:\n");
    for(i = 0; i < n; i++){
        int burst;
        scanf("%d", &burst);
        total_burst += burst;
        PCB[i].pid = i;
        PCB[i].wt = 0;
        PCB[i].tat = 0;
        PCB[i].at = 0;
        PCB[i].priority = 0;
        PCB[i].bt = burst;
        PCB[i].rmt = burst;
    }
    
    RoundRobin(PCB);


    int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + PCB[i].wt;
		total_tat = total_tat + PCB[i].tat;
	}

    printf("Average waiting time = %f", (float)total_wt / (float)n);
	printf("\nAverage turn around time = %f\n", (float)total_tat / (float)n);

    return 0;
}