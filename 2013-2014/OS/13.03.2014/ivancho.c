#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#define BRASHNO 1000 // brAshno
int masa[4];
pthread_mutex_t lock;

void* put_pasta_on_table(void* array){
	int *arr = array;
	
	srand(time(NULL));
	int brashno_taken = 1 + rand() % 100;
		
	while(BRASHNO > 0){
		pthread_mutex_lock(&lock);		
		int i;
		for(i = 0; i < 4; i++){
			if(arr[i] == 0){
				//BRASHNO -= brashno_taken;
				usleep(brashno_taken * 1000);
				arr[i] = 1;
				printf("Pasta!\n");
			}else{
				printf("Table full... Wait for Ivancho...\n");
				usleep(1000000);
			}
		}
		pthread_mutex_unlock(&lock);
	}
}

void* take_pasta_from_table(void* array){
	while(1 == 1){
		int *arr = array;
		int empty = 1;
		int i;
		for(i = 0; i < 4; i++){
			printf("%d ",arr[i]);
			if(arr[i] == 1){
				empty = 0;
			}
		}
		printf("\nEmpty = %d\n", empty);
		if(empty == 1){
			printf("Empty :(\n");
			usleep(1000000);
		}else{
			printf("Not empty\n");
		}
	
		if(empty == 0){
			printf("IN\n");
			pthread_mutex_lock(&lock);		
			int i;
			for(i = 0; i < 4; i++){
				printf("%d",i);
				if(arr[i] == 1){
					arr[i] = 0;
					printf("Qdene!\n");
				}
			}
			pthread_mutex_unlock(&lock);
		}
		printf("Try again!\n");
	}
}

int main(){
	int i;
	for(i = 0; i < 4; i++){
		masa[i] = 0;
	}
	
	pthread_mutex_init(&lock,NULL);
	pthread_t ivancho, maika_mu; // tq e slqpa...
	
	pthread_create(&maika_mu, NULL,put_pasta_on_table, &masa);
	pthread_create(&ivancho, NULL,take_pasta_from_table, &masa);
	
	pthread_exit(&ivancho);
	pthread_exit(&maika_mu);
		
	pthread_mutex_destroy(&lock);
	
	return 0;
}
