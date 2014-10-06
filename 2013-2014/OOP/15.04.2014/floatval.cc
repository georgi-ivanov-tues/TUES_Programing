#include <iostream>

using namespace std;

int main(){
	cout << 1234.5678901 << ' ' << 1234.5678901 << endl;
	
	cout.precision(12);
	
	cout.setf(ios_base::scientific, ios_base:: floatfield);
	cout << 1234.5678901 << ' ' << 1234.5678901 << endl;

	cout.setf(ios_base::fixed, ios_base:: floatfield);
	cout << 1234.5678901 << ' ' << 123456789.01 << endl;

	cout.unsetf(ios_base::floatfield);
	cout << 1234.5678901 << ' ' << 123456789.01 << endl;

	// Sando obi4am te <3
	return 0;
}

/*
          .               ,.
            T."-._..---.._,-"/|
            l|"-.  _.v._   (" |
            [l /.'_ \; _~"-.`-t
            Y " _(o} _{o)._ ^.|
            j  T  ,-<v>-.  T  ]
            \  l ( /-^-\ ) !  !
             \. \.  "~"  ./  /c-..,__
               ^r- .._ .- .-"  `- .  ~"--.
                > \.                      \
                ]   ^.                     \
                3  .  ">            .       Y  
   ,.__.--._   _j   \ ~   .         ;       |
  (    ~"-._~"^._\   ^.    ^._      I     . l
   "-._ ___ ~"-,_7    .Z-._   7"   Y      ;  \        _
      /"   "~-(r r  _/_--._~-/    /      /,.--^-._   / Y
      "-._    '"~~~>-._~]>--^---./____,.^~        ^.^  !
          ~--._    '   Y---.                        \./
               ~~--._  l_   )                        \
                     ~-._~~~---._,____..---           \
                         ~----"~       \
                                        \
*/

// Poprincip - da.
