#include <iostream>

using namespace std;

int main(){
	char buff[1024];	
	
	while(cin){
		cin.getline(buff,1024,'\n');
		if(!cin)
			break;
			
		cout << "buff: " << buff << endl;
	
	}
	
	return 0;
}
