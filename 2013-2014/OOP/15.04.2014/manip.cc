#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	cout << showbase << 1234 << ' ' << 
			  		 hex << 1234 << ' ' << 
			  		 oct << 1234 << ' ' << 
			  		 dec << 1234 << endl;

	cout << boolalpha << true << ' ' << false << endl;
	cout << noboolalpha << true << ' ' << false << endl;

	cout << '|' << setw(12) << 12 << '|' << endl;
	cout << '|' << setw(12) << 123 << '|' << endl;
	cout << '|' << setw(12) << 1234 << '|' << endl;
	cout << '|' << setw(12) << 12345 << '|' << endl;
	cout << '|' << setw(12) << 123456 << '|' << endl;
				
	return 0;
}

// Sharo ot koq hrana qde ?
// Sharo ailqk li si ve ?

/*
		___             _ 
	  |_  |           (_)
		 | | ___  _ __  _ 
		 | |/ _ \| '_ \| |
	/\__/ / (_) | | | | |
	\____/ \___/|_| |_|_|
		                        /$$
		                       | $$
	  /$$$$$$  /$$$$$$$   /$$$$$$$
	 |____  $$| $$__  $$ /$$__  $$
	  /$$$$$$$| $$  \ $$| $$  | $$
	 /$$__  $$| $$  | $$| $$  | $$
	|  $$$$$$$| $$  | $$|  $$$$$$$
	 \_______/|__/  |__/ \_______/
			                                
	,   .         |     |    |         
	|\  |,---.,---|,---.|    |__/ ,---.
	| \ ||---'|   ||---'|    |  \ |   |
	`  `'`---'`---'`---'`---'`   ``---'
*/
