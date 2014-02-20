#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ARRAY_SIZE 100

int compare( const void* a, const void* b){
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

void* sort(void* array){
	int* a = (int*)array;
	int i;
	for(i = 0; i < ARRAY_SIZE/2;i++){
		printf("%d ",a[i]);
	}
	qsort(a, ARRAY_SIZE/2, sizeof(int), compare);
	pthread_exit((void *)a);
}   

int main(){
	int array[ARRAY_SIZE];
	
	int i;
	for(i = 0; i < ARRAY_SIZE;i++){
		array[i] = ARRAY_SIZE - i;
	}
	
	int a[ARRAY_SIZE/2];
	int b[ARRAY_SIZE/2];
	int j = 0;
	for(i = 0; i < ARRAY_SIZE; i++){
		if(i < ARRAY_SIZE/2){
			a[j] = array[i];
			j++;
			if(j >= ARRAY_SIZE/2){
		 		j = 0;
			}
		}else{
			b[j] = array[i];
			j++;
		}
	}	
	pthread_t thread;
	pthread_t thread2;
	pthread_create(&thread, NULL, sort, a);
	//pthread_create(&thread2, NULL, sort, b);
	pthread_join(thread,(void*)a);
	//pthread_join(thread2,(void*)b);
	
	
	for(i = 0; i< 50; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	//for(i = 0; i< 50; i++){
	//	printf("%d ",b[i]);
	//}
	
	
	return 0;
}

// mrazq nishki!
