#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t pick_up;
pthread_t philosopher[N];
pthread_mutex_t chopsticks[N];
int count[N];

void pickup(int philosopher){
	pthread_mutex_lock(&chopsticks[philosopher]);
	pthread_mutex_lock(&chopsticks[(philosopher+1) % N]);
}

void putdown(int philosopher){
	pthread_mutex_unlock(&chopsticks[philosopher]);
	pthread_mutex_unlock(&chopsticks[(philosopher+1) % N]);
}

void think(int philosopher){
	printf("philosopher %d is thinking\n", philosopher);
	sleep(2);
}

void eat(int philosopher){
	printf("philosopher %d is eating with chopsticks(%d) and chopsticks(%d)\n"
			           , philosopher, philosopher, (philosopher+1) % N);
	sleep(2);
}

void finish(int philosopher){
	printf("philosopher %d finished eating\n", philosopher);
}

void *handle_philosopher (void *i){

	int id = (int)(long) i;

	count[id] = 1;
	while(1){
		
		//think
		think(id);
		
		//pickup
		sem_wait(&pick_up);
		pickup(id);
		sem_post(&pick_up);

		//eat
		eat(id);

		//finish eating
		finish(id);
		
		//putdown
		putdown(id);


		count[id]++;
	}
}

int main(){

	sem_init(&pick_up, 0 , 1);

	for (int i = 0; i < N; ++i)
	{
		if (pthread_mutex_init(&chopsticks[i], NULL))
		{
			printf("Mutex Initialize Failed\n");
			return 0;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		pthread_create(&philosopher[i], NULL, handle_philosopher, (void *)i);
	}
	for (int i = 0; i < N; ++i)
	{
		pthread_join(philosopher[i], NULL);
	}

	return 0;
}
