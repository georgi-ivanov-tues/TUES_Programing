#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
			char *filename = "main2.c"; //ime na fail
			int fd = open("main2.c" , O_RDONLY);
			if(fd < 0){
				char error[200];
				strcpy(error,"open():");
				strcat(error,"main2.c");
				perror(error);
				return -1;
			}
			char buffer[200];
			
			int result = read(fd, buffer, 200);
			if (result < 0){
				char error[200];
				strcpy(error,"read():");
				strcat(error, filename);
				perror(error);
				return -2;
			}
return 0;
}                                                                                



















