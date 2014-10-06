#include <iostream>

using namespace std;

class Point{
	double x_,y_;
public:
	Point(double x=0.0, double y=0.0)
	: x_(x),
	  y_(y)
	{}
	
	double get_x() const{
		return x_;
	}

	double get_y() const{
		return y_;
	}

};

// (x,y)
ostream& operator<<(ostream& out, const Point& p){
	out << '(' << p.get_x() << ',' << p.get_y() << ')';
	return out;
}

// (<double>,<double>)

istream& operator>>(istream& in, Point& p){
	char ch;
	double x,y;
	
	in >> ch;
	
	if(ch != '('){
		in.clear(ios_base::badbit);
		return in;
	}
	
	in >> x;
	in >> ch;
	
	if(ch != ','){
		in.clear(ios_base::badbit);
		return in;
	}
	
	in >> y;
	in >> ch;
	
	if(ch != ')'){
		in.clear(ios_base::badbit);
		return in;
	}
	
	if(in.good()){
		p = Point(x,y); // prisvoqvame novi stoinosti
	}
	
	return in;
}

int main(){
	Point p1(10,20), p2(30,40);

	cout << p1 << p2 << endl;

	while(cin){
		cin >> p1;
		if(!cin){
			cerr << "Java e greshka na prirodata..." << endl;
			break;
		}
		
		cout << p1 << endl;
	}

	return 0;
}
