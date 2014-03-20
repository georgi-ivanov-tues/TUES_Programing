#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define TIMES 100
pthread_mutex_t lock;

void* ping(){
	int i;
	for(i = 0; i < TIMES; i++){
		pthread_mutex_lock(&lock);
		printf("ping\n");
		pthread_mutex_unlock(&lock);
		usleep(100000);
	}
}

void* pong(){
	int i;
	for(i = 0; i < TIMES; i++){
		pthread_mutex_lock(&lock);
		printf("pong\n");
		pthread_mutex_unlock(&lock);
		usleep(100000);
	}
}

int main(){
	pthread_mutex_init(&lock,NULL);
   
   pthread_t thread[2];
   pthread_create(&thread[0],NULL,ping,NULL);
   pthread_create(&thread[1],NULL,pong,NULL);
   
   pthread_join(thread[1],NULL);
   pthread_mutex_destroy(&lock);

	return 0;
}

// mrazq nishki!
