// MUTEX!

#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 100000
int sum = 0; // MLAKVAI REPA!
pthread_mutex_t lock;


void* halfSum(void* start){
	int *arr = start; // (int *) start
	int i;
	for(i = 0; i < ARRAY_SIZE/2; i++){ // ukazatel - nakazatel!
		pthread_mutex_lock(&lock);	// nishkata vliza v kriti4nata sekciq i lock-va, za da ne moje druga nishka da vleze		
		sum += arr[i]; // kriti4na sekiciq
		pthread_mutex_unlock(&lock);
	}
	
	// return NULL; 
	// retrun..
}

int main(){
	int arr[ARRAY_SIZE];
	int i;
	for(i = 0; i < ARRAY_SIZE; i++){
		arr[i] = 2;
	}
	
	pthread_mutex_init(&lock,NULL); // inecializirame mutex-a
	pthread_t tid1, tid2; // tit...
	
	pthread_create(&tid1, NULL,halfSum,arr);
	pthread_create(&tid2, NULL,halfSum,arr + ARRAY_SIZE/2); // &arr[ARRAY_SIZE/2]

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("%d\n", sum);	
	
	pthread_mutex_destroy(&lock);

	return 0;
}

// Vse oshte mrazq niski!!!
