#include <iostream>
using namespace std;

class ListError{};

template<typename T>
class List {
	struct Elem {
		T data_;
		Elem* next_;
		
		Elem(T val) : data_(val), next_(0)
		{}
	};

	Elem* head_;
	Elem* tail_;
public:
	
	List()
	: head_(0),
	  tail_(0)
	{}
	
	bool empty() const {
		return head_==0;
	}

	void push_front(T val) {
		Elem* new_elem = new Elem(val);
		new_elem->next_ = head_;
		head_ = new_elem;
	}
	
	void push_back(T val){
		Elem* new_elem = new Elem(val);
		new_elem->next_ = tail_;
		tail_ = new_elem;
	}

	T front() const {
		if(empty()) {
			throw ListError();
		}
		return head_->data_;
	}
	
	void pop_front() {
		if(empty()) {
			throw ListError();
		}
		
		Elem* old_head = head_;
		head_ = head_->next_;
		delete old_head;
	}
	
	void pop_back(){
		if(empty()) {
			throw ListError();
		}
		
	}

	const T& back() const{
		
	}
	
	T& back(){
		if(empty()) {
			throw ListError();
		}
		return tail_->data_;
	}
	
	~List() {
		while(!empty()) {
			pop_front();
		}
	}
};


int main() {
	List<int> l1;
	cout << l1.empty() << endl;
	l1.push_front(42);
	cout << l1.empty() << endl;
	cout << l1.front() << endl;
	l1.push_front(43);
	cout << l1.front() << endl;
	l1.pop_front();
	cout << l1.front() << endl;	
	
	l1.push_back(50);	
	l1.push_back(51);
	cout << l1.back() << endl;
	
	return 0;
}

/*

За разлика от примера вашият клас трябва да поддържа указатели както към началото head_, така и към края (последният елемент) на списъка tail_.
Класът трябва да поддържа следните операции:
1) добавяне на елементи в началото и в края на списъка. Методи
void push_front()
void push_back()
2) изтриване на елементи в началото и в края на списъка. Методи
void pop_front()
void pop_back()
3) Четене на стойността на елемент в началото и в края на списъка. Методи
const T& front() const;
T& front();
const T& back() const;
T& back();
4) Копиращ конструктор и оператор за присвояване.
5) Деструктор.

*/
