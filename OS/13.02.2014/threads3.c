#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Invalid...
void* hello(void* array){
	int *array2 = array;

	int i; 
	int sum = 0;
	for(i = 0; i < 10000; i++){
		sum += array2[i];
		//i--;
	}
	long int average = sum / 10000;

	return (void*) average; // bond, vagabond
}

int main(){
	int array[10000];
	int i;
	for(i = 0; i < 10000; i++){
		array[i] = i % 255; // Ot 0 do 254 (stodvestapedeseichetiri)
	}
	
	pthread_t thread;
	pthread_create(&thread, NULL, hello, array);

	void* result = hello(array);
	long int average = (long int) result;
	
	printf("%ld\n", average);
	
	pthread_exit(NULL);
	
	return 0;
}

// Notice me Senpai!
