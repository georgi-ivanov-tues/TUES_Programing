#include <iostream>
#include <string>
#include <list>
#include <sstream>

using namespace std;

int main(){
	string s1 = "hEllo wroda sda sjh 42";
	istringstream in1(s1); // Pravi go potok
	
	double val;
	string token;
	in1 >> token;
	cout << token << endl;
	
	in1 >> token;
	cout << token << endl;
	
	in1 >> val;
	cout << val << endl;
	
	ostringstream out1;
	out1 << token << ' ' << val;
	cout << "out1: " << out1.str() << endl;

}
