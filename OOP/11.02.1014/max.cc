#include <iostream>

using namespace std;

template<typename T>
T maxvalue(const T& a, const T& b){
	return (a > b)?a:b;
}

int main(){
	cout << maxvalue<int>(10,15) << endl;
	cout << maxvalue<double>(1.1,0.1) << endl;
	cout << maxvalue<string>("a","z") << endl; // ascii koda na z > ot tozi na a
		
	return 0;
}

// koremche
