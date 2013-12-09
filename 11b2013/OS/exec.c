#include<stdio.h>
#include<unistd.h>

int main() {

	int stat;
	
	stat = execl("/bin/ls", "/bin/ls", "-l", NULL);
	
	if(stat == -1){
		perror("exec");
	}

	printf("KOTKA");
	
	return 0;
}
