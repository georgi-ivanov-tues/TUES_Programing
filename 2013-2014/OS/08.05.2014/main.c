#include <dirent.h>
#include <stdio.h>
#include <errno.h>

int main(){
	DIR *dir = opendir("../"); // kogato iskame celq pat slagame "/etc"
	
	if(dir == NULL){
		perror("ls: ");
		return -1;
	}
	
	struct dirent *dt;
	
	while((dt = readdir(dir)) != NULL){	
		printf("%s\n", dt->d_name);
	}
		
	if(errno != 0){
		perror("error on: ");
		return -2;
	}
		
	closedir(dir);
	
	return 0;
}

// Segmentation fault <3

//-Koe ti e lubimoto chislo?
//-EBADF !!!
