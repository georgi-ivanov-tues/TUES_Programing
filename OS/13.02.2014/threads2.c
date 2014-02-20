#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* hello(void* arg){ // nachaen adres
	printf("Hello\n");
	return 0;
}

// zapetqvame promenlivata...

int main(){
	int a = 0;
	int *p = &a; // Mrazq pointeri!
		
	// Pointeri kam funckiq, daiba...
	//int (*f)(int) = &hello; // - Kakav ti e tipa ? 
								     // - Int*, moje bi ?
	
	pthread_t thread;
	pthread_t thread2;
	pthread_create(&thread, NULL, hello, NULL);
	pthread_create(&thread2, NULL, hello, NULL);
	
	// epal

	hello(NULL); // tli puti hello
	pthread_exit(NULL);
	
	return 0;
}

// Come to the C side, we have pointers...
