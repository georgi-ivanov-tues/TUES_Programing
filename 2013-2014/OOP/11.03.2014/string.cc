#include <string.h>
#include <iostream>

using namespace std;

class String{
	int capacity_;
	int size_;
	char* buffer_;

	friend ostream& operator<<(ostream&, const String&); // metoda e pritelski za tozi klas => ima dostap do private chlenovete na klasa.

	void ensure_capacity(int cap){
		if(capacity_ >= cap){
			return;
		}
		char* tmp = buffer_;
		capacity_ = cap;
		buffer_ = new char[capacity_]; // uvelichavame capacity_
		strcpy(buffer_, tmp); // kopirame stariq string v noviq
		delete [] tmp;
	}
public:
	explicit String(int capacity) // ne mojem da go izpozvame za neqvno preobrazuvane
	: capacity_(capacity),
	  size_(0),
	  buffer_(new char[capacity_])
	{
		buffer_[0] = '\0';
	}
	
	String(const char* str)
	: capacity_(0),
	  size_(0),
	  buffer_(0)	
	{
		size_ = strlen(str);
		capacity_ = size_ + 1;
		buffer_ = new char[capacity_];
		strcpy(buffer_, str);
	}

	String& operator+=(const String& s){
		ensure_capacity(size_ + s.size_ + 1);
		strcat(buffer_, s.buffer_); // konkatinirame
		return *this;
	}
	
	int size() const{
		return size_;
	}
	
	int length() const{
		size();
	}
	
	int capacity() const{
		return capacity_;
	}
	
	bool empty() const{
		return size_ == 0;
	}
	
	void clear() const{
		//size_ = 0;	
		//capacity_ = size_ + 1;
		//buffer_ = new char[capacity_];
		//buffer_[0] = '\0';
	}
	
	char& operator[](int index){
		return buffer_[index];
	}
	
	char& at(int index){
 		//if()
	}
	
	bool operator==(const String& other){
		return strcmp((*this).buffer_,other.buffer_) == 0;
	}
	
	
	bool operator!=(const String& other){
		return strcmp((*this).buffer_,other.buffer_) != 0;
	}
	
	bool operator<(const String& other){
		return strcmp((*this).buffer_,other.buffer_) == -1;
	}
	
	bool operator>(const String& other){
		return strcmp((*this).buffer_,other.buffer_) == 1;
	}
	
	bool operator<=(const String& other){
		return strcmp((*this).buffer_,other.buffer_) <= -1;
	}
	
	bool operator>=(const String& other){
		return strcmp((*this).buffer_,other.buffer_) >= 1;
	}
	
	~String(){
		delete [] buffer_;
	}
};

ostream& operator<<(ostream& out, const String& s){
	out << s.buffer_;
	return out;
}

// 1 >
// 0 ==
// -1 <

int main(){
	String s1("Hello");
	String s2("World!");
	cout << s1 << endl;
	cout << s2 << endl;

	s1 += s2;
	cout << s1 << endl;

	String s3("Hello");
	s3 += " "; // preobrazuva " "(const char*) v String i izvikva +=
	s3 += s2;
	cout << s3 << endl;
	
	cout << s3[0] << endl;
	
	if(s1 == s3){
		cout << "true" << endl;
	}	
	
	return 0;
}

// Uslovie: http://lubo.elsys-bg.org/wp-content/uploads/2010/03/OOP01-string.pdf
