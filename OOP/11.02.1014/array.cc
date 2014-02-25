#include <iostream>

using namespace std;

class ArrayError{};

template<typename T>
class Array{
	int size_;
	T* data_;
public:
	Array(int size)
	: size_(size),
	  data_(new T[size_])
	{}

	int size() const{
		return size_;
	}

	~Array(){
		delete [] data_;
	}
	
	T& operator[](int index){
		if(index < 0 || index >= size_){
			throw ArrayError();
		}
		return data_[index]; // vrushta prepratka na element ot masiva
	}
};

int main (){
	Array<int> al(10);
	for(int i = 0; i < al.size(); ++i){
		al[i] = i*15;
	}

	for(int i = 0; i < al.size(); ++i){
		cout << al[i] << ' ';
	}
	
	cout << endl;

	return 0;
}
