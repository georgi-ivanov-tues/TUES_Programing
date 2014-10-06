#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int a = 10;

int main(){
	pid_t pid = fork();	
	if(pid == 0){
		printf("Hello from Orphan\n");	
		a = 5;
		printf("a = %d\n",a);
	}else if(pid > 0){
		printf("You are adopted!\n");
		waitpid(pid,NULL,0);
		printf("a = %d\n",a);
	}else{
		printf("kotki...\n");
	}
	
	
	
	return 0;
}

// www.DecaSasNechetenBroiHromozomi.k
