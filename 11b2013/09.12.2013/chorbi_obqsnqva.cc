/* 
Inline funkciq
	1. Pri inline funkciite kogato viknem funkciq
	   funckqita koqto vikame se kopira na mqstoto kudeto q vikame
	   vmesto kompilatorat da q tursi
	   
	2. Kogato vikame funckiqta mnogo puti stava mnogo bavno ot mnogoto
	   povtarqne
	  
	3. Programista sam si izbira koe e po-dobre v dadeniq slu4ei
*/

#include <iostream>
using namespace std;

class Point{
	double x_,y_;
public:
	Point(double x=0.0, double y=0.0)
	: x_(x),
	  y_(y)
	{}
	
	Point(const Point& other) // Kopirasht konstruktor
	: x_(other.x_),
	  y_(other.y_)
	{
		cout << "Point(Point&)" << endl;
	}
	
	~Point(void){
		cout << "~Point()" << endl; // Samo saubshtavame che obekta umira ;(
	}

	double get_x() const{
		return x_;
	}
	
	double get_y() const; // Deklarirame funckiqta
	
	operator+=(const Point& other){
		// p2 += p3; =>
		// this == &p2;
		// ne mojem da naso4vame this kam drug obekt
		// Point *const this; // raboti kato tova
		// this = &other; // ne e pozvoleno
		x_+=other.x_;
		y_+=other.y_;
		
		return this*;
	}
};

ostream& operator<<(ostream& out, const Point& p){
	out << '(' << p.get_x() << ',' << p.get_y() << endl;
	
	return out; // Vrushtame izhoda
}

/*
double Point::get_y(){ // V tozi slu4ei ne pozlvame inline funckiq!
	return y_;
}
*/

inline double Point::get_y(){ // Polzvame inline
	return y_;
}

Point operator+(const Point& p1, const Point& p2){ // Nqma prepratka za6toto res iz4ezva sled kraq na funkciqta. Razlikata e 4e res e lokalna promenliva, a gore this ne e
	Point res(p1);
	res+=p2;
	return res;
}

int main/*i*/(){
	Point p1;
	p1.get_x();
	//p1.x_; // dosta po-barzo ot gornoto
	p1.get_y();
	
	Point p2(10,20);
	Point p2(30,40);
	p1 = p2 += p3; // Izpalnqva se ot dqsno na lqvo
				   // Kam p2 dobavqme p3
				   // Vrushtame prepratka kam p2, koqto pozlvame v sledvashtiq operator

	cout << p1;
	
	Point p4 = 5; // Namira 4e imame konstruktor i podava 5
	Point p5(5); // Na praktika sa edno i sa6to!
	extend myDick++;
	return 0;
}
