#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
    key_t key;
    key = ftok("/mnt/c/Users/98912/Desktop/uni/OS LAB/EXP 4/Q1", 'R');
    
    // shmget returns an identifier in shmid
    int shmid = shmget(key, sizeof(int) * 2, 0666|IPC_CREAT);
    
    // shmat to attach to shared memory
    int *nums = (int*) shmat(shmid,(void*)0,0);
    
    printf("Write Data : ");
    scanf("%d", &nums[0]);
    printf("Write Data : ");
    scanf("%d", &nums[1]);
    printf("Write Data : ");
    scanf("%d", &nums[2]);
    printf("Data written in memory: %d, %d, %d\n", nums[0], nums[1], nums[2]);

    //detach from shared memory
    shmdt(nums);
    return 0;
}