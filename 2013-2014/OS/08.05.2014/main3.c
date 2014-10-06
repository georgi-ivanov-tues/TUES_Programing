#include <stdio.h>
#include <unistd.h>

int main(int argc, char* const argv[]){

	char c;
	int index;
	while((c = getopt(argc, argv, "lRa")) != -1){
		printf("arg %c\n", c);
	}

	for(index = optind; index < argc; index++){
		printf("%s\n", argv[index]);
	}

	return 0;
}
