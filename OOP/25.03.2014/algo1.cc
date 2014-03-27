#include <iostream>

using namespace std;

class print_fn{
	
public/*hen dom*/:
	void operator()(int valio){
		cout << "kotki " << valio << endl;
	}
};

int main(){
	print_fn pf;
	
	pf(42);
	
	return 0;
}
