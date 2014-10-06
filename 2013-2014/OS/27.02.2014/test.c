#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* xaxa(void* xaxa){
	printf("xaxa\n");
}

int main(){
	pthread_t thread;

	pthread_create(&thread,NULL,xaxa,NULL);
	
	pthread_exit(NULL);

	return 0;
}
