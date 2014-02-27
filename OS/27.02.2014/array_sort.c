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
	qsort(array,ARRAY_SIZE/2,sizeof(int),compare);
	return array;
}

int main(){
	int array[ARRAY_SIZE];
	int i;
	for(i = 0; i < ARRAY_SIZE;i++){
		array[i] = ARRAY_SIZE-i;
	}
	
	int array0[ARRAY_SIZE/2];
	int array00[ARRAY_SIZE/2];
	for(i = 0;i < ARRAY_SIZE/2; i++){
		array0[i] = array[i];
	}
	int j = 0;
	for(i = ARRAY_SIZE/2;i < ARRAY_SIZE; i++){
		array00[j] = array[i];
		j++;
	}
	pthread_t thread[2];
	pthread_create(&thread[0],NULL,sort,array0);
	pthread_create(&thread[1],NULL,sort,array00);
	void* array1;
	void* array2;
	pthread_join(thread[0],&array1);
	pthread_join(thread[1],&array2);
	int* array11 = (int *)array1;
	int* array22 = (int *)array2;
	
	int nov_array[ARRAY_SIZE];
	j = 0;
	for(i = 0;i < ARRAY_SIZE/2; i++){
		nov_array[i] = array11[i];
	}
	for(i = ARRAY_SIZE/2;i < ARRAY_SIZE; i++){
		nov_array[i] = array22[j];
		j++;
	}
	
	qsort(nov_array,ARRAY_SIZE,sizeof(int),compare);
	for(i = 0; i < ARRAY_SIZE;i++){
		printf("%d\n",nov_array[i]);
	}
	
	return 0;
}
