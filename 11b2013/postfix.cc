// Postfixen zapis 1 2+
// 1 2 3+* => 1 5* => 5
//
// Slagame 4islata v stack, kogato imame operaciq popvame poslednite 2 4isla
// izvur6vacem operaciqta i rezultata slagame otnovo v stack-a

#include <iostream>
#include <string>
#include <list>
#include <sstream> // Za preobrazuvaneto ot string kum int
//#include <potka>

using namespace std;

void post_binary(list<double>& context,
				double (*binary_op)(double, double)){ // Predavame funkciq (ukazatel kam funckiq koqto priema (double, double))
	if(context.size() < 2){
		cout << "tvarde maklo dinozavri... (>= 2)" << endl;
		return;
	}
	
	double val2 = context.back();
	context.pop_back(); // 2-ri kon...
	double val1 = context.back();
	context.pop_back();
	double res = binary_op(val1, val2);
	context.push_back(res);
	
	cout << "result = " << res << endl;
}

double binary_plus(double val1, double val2){ return val1 + val2; }
double binary_minus(double val1, double val2){ return val1 - val2; }
double binary_mult(double val1, double val2){ return val1 * val2; }

void post_double(const string& token, list<double>& context){
	istringstream in(token); // Preobrazuva token v potok za chetene
	double val = 0.0;
	in >> val; // Opitvame se da prochetem double
	if(!in){
		cout << "Not a double..." << endl;
	}else{
		//cout << "(double): " << val << endl;
		context.push_back(val);
	}
}

int main(){
	// Shte chetem...
	string token;
	list<double> context;
	
	while(cin){ // Potoka se preobrazuva v celochislen izraz (0 ako e schupen, drugo ako e ok)
		cin >> token; // Chetem tuk... cin deli vhoda na dumichki (chrez ' ', \t, ...) 
		if(!cin){ // Schupen li e potoka ?
			cout << "Bah toz dinozavar..." << endl;
			break;
		}
		//cout << "token: " << token << endl;
		
		if(token == "+"){
			//post_plus(context);
			post_binary(context, binary_plus);
		}else if(token == "-"){
			post_binary(context, binary_minus);
		}else if(token == "*"){
			post_binary(context, binary_mult);
		}else{
			post_double(token, context);
		}
	}
	
	return 0;
}

// Nebostokrivaktus...
