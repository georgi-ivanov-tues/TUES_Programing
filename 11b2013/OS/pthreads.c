#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *print_hello(void *thread_id){
	int result;
	int i;
	int tid = (int) thread_id;
	for (i = 0; i < 1000000; i++){
		result += (double) random();
	}
	printf("Result  %e\n", result);
	pthread_exit((void *) 0);
}

int main(){
	pthread_t threads[5];
	pthread_attr_t attr[5];
	int i;
	
	for(i = 0; i < 5;i++){
		pthread_attr_init(&attr[i]);
		// TO BE CONTINUED
		printf("In main thread :creating thread %d\n", i);
		int rc = pthread_create(&threads[i], NULL, print_hello, (void*) i);
			if (rc){
				printf("ERROR creating thread %d\n", i);
				exit(-1);
			}		
	}
	for(i = 0; i < 5; i++){
		int status = 0;
		int rc = pthread_join(threads[i], (void **) &status);
			if (rc){
				printf("ERROR\n");
				exit(-1);
			}
	}
	printf("AFTER JOIN\n");
	pthread_exit(NULL);
	return 0;

}
