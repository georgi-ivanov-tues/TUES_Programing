#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(){
	struct stat st;
	struct passwd *pws;
	
	stat(".", &st);

	pws = getpwuid(st.st_uid);
	
	printf("%s\n", pws->pw_name);
	printf("%s\n", pws->pw_passwd);
	printf("%i\n", st.st_mode);
	printf("%i\n", st.st_mode % S_IREAD);


	return 0;
}

// Never don't give up!!!
