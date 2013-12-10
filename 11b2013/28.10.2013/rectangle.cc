#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

class Point{
	double x_, y_;
public:
	Point(double x = 0.0, double y = 0.0)
		:x_(x), y_(y)
	{}
	double get_x(void) const {return x_;}
	double get_y(void)const Rectangle& rec1 const {return y_;}
	
	Point& set_x(double x){
		x_ = x;
		return *this;
	}
	Point& set_y(double y){
		y_ = y;
		return *this;
	}
	void print() const;
};

class Rectangle{
	Point bl_, ur_;
	
public:
	static double max(double a, double b){
		return a>b ? a:b;
	}
	
	static double min(double a, double b){
		return a<b ? a:b;
	}
	
	double area(Point p1, Point p2) const{
		double a = p2.get_y() - p1.get_y();
		double b = p2.get_x() - p1.get_x();
		return  a*b;
	}
	
	Rectangle intersection (const Rectangle& rec1, const Rectangle& rec1 ) const{
	
	}
};

#endif

#include <stdio.h>

int main(){
	Point p1, p2;
	Point p3, p4;
	Rectangle rec1, rec2, rec3, rec4;
	p1.set_x(5.0);
	p1.set_y(2.0);
    p2.set_x(15.0);
	p2.set_y(7.0);
	
	p3.set_x(12.0);
	p3.set_y(6.0);
    p4.set_x(20.0);
	p4.set_y(8.0);
	
	double result_rec_1 = rec1.area(p1,p2);
	double result_rec_2 = rec2.area(p3,p4);
	rec3.intersection(rec1,rec2);
	//double result_rec_3 = rec3.area(p2,p3);
	//double result_rec_4 = (result_rec_1 + result_rec_2) - result_rec_3;

	printf("%.2f\n",result_rec_4);
	return 0;
}
