#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class sum{
	int value_;
public:
	sum()
	: value_(0)
	{}
	
	int value() const{
		return value_;
	}
	
	void operator()(int val){
		value_ += val;
	}
};


class mul{
	int value_;
public:
	mul()
	: value_(1)
	{}
	
	int value() const{
		return value_;
	}
	
	void operator()(int val){
		value_ *= val;
	}
};

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	list<int> l(a,a+10);

	sum s;
	s(42);
	s(43);
	cout << s.value() << endl;

	sum s1 =	for_each(l.begin(), l.end(), sum());
	cout << s1.value() << endl;

	mul s2 =	for_each(l.begin(), l.end(), mul());
	cout << s2.value() << endl;

	return 0;
}
