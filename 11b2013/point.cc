#include<iostream>
using namespace std;

class Point{
	double x_,y_;
public:
	Point(double x = 0.0, double y = 0.0)
	:x_(x), 
	 y_(y)
	
	{ //kotka.com
		//x_ = x;
		//y_ = y;
	}
	
	double get_x()const{
		return x_;
	}
	double get_y()const{
		//return y_;
		return this -> y_;
	}
	
	Point& set_x(double x){
		x_ = x;
		return *this;
	}
	
	
	Point& set_y(double y){
		y_ = y;
		return *this;
	}
};

int main(){
	int a = 0;
	
	int b;
	b=0;
	
	const int c = 42;

	Point p1(2.0, 3.0); // x = 2.0, y = 3.0
	Point p2; // x = 0.0, y = 0.0
	
	cout << "p1: " << p1.get_x() << ", " << p1.get_y() << endl;
	cout << "p2: " << p2.get_x() << ", " << p2.get_y() << endl;	
	
	Point p3(3.0); // x = 3.0, y = 0.0 
	cout << "p3: " << p3.get_x() << ", " << p3.get_y() << endl;

	const Point cp(0.0, 0.0);
	cp.get_x();
	
	Point p4;
	p4.set_x(15.0); // XAXA
	p4.set_y(16.0);
	
	(p4.set_x(17.0)).set_y(18.0);
	
	cout << "p4: " << p4.get_x() << ", " << p4.get_y() << endl;
			
	return 0 ;
}


















