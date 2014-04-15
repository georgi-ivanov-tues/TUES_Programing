#include <iostream>

using namespace std;

int main(){
	cout << 1234 << ' ' << endl;

	cout.setf(ios_base::showbase);

	cout.setf(ios_base::hex, ios_base::basefield);
	cout << 1234 << ' ' << 1234 << endl;
	
	cout.setf(ios_base::oct, ios_base::basefield);
	cout << 1234 << ' ' << 1234 << endl;
	
	cout.setf(ios_base::dec, ios_base::basefield);
	cout << 1234 << ' ' << 1234 << endl;
	
	return 0;
}

/*
       __________________
      /\  ______________ \
     /::\ \ZZZZZZZZZZZZ/\ \
    /:/\.\ \        /:/\:\ \
   /:/Z/\:\ \      /:/Z/\:\ \
  /:/Z/__\:\ \____/:/Z/  \:\ \
 /:/Z/____\:\ \___\/Z/    \:\ \
 \:\ \ZZZZZ\:\ \ZZ/\ \     \:\ \
  \:\ \     \:\ \ \:\ \     \:\ \
   \:\ \     \:\ \_\;\_\_____\;\ \
    \:\ \     \:\_________________\
     \:\ \    /:/ZZZZZZZZZZZZZZZZZ/
      \:\ \  /:/Z/    \:\ \  /:/Z/
       \:\ \/:/Z/      \:\ \/:/Z/
        \:\/:/Z/________\;\/:/Z/
         \::/Z/_______itz__\/Z/
          \/ZZZZZZZZZZZZZZZZZ/
*/
