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
	
	T& back(){
		if(empty()) {
			throw ListError();
		}
		return tail_->data_;
	}
	
	const T& back() const{
		
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
		//...
	}
	
	~List() {
		while(!empty()) {
			pop_front();
		}
	}
	
	// Iterator
	class iterator {
		friend class List;

		Elem* current_;

		iterator(Elem* current)
		: current_(current)
		{}
		
		public:
		iterator& operator++() {
			current_=current_->next_;
			return *this;
		}
		
		iterator operator++(int) {
			iterator res=*this;
			current_=current_->next_;

			return res;
		}

		int& operator*() {
			return current_->data_;
		}

		bool operator==(const iterator& other) const {
			return current_==other.current_;
		}

		bool operator!=(const iterator& other) const {
			return ! operator==(other);
		}

	};

	iterator begin() const {
		return iterator(head_->next_);
	}

	iterator end() const {
		return iterator(head_);
	}

	iterator insert(iterator pos, int val) {
		Elem* new_elem = new Elem(val);
		Elem* curr = pos.current_;

		Elem* prev=curr->prev_;

		prev->next_=new_elem;
		new_elem->prev_=prev;

		new_elem->next_=curr;
		curr->prev_=new_elem;

		return iterator(new_elem);
	}


	iterator erase(iterator pos) {
		Elem* curr=pos.current_;

		Elem* next=curr->next_;
		Elem* prev=curr->prev_;

		prev->next_=next;
		next->prev_=prev;

		delete curr;

		return iterator(next);
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

	cout << endl;	

	// Iterator...
	int i;
	// ALAHU AKBAR!
	List ls;
	cout << "ls.empty()? " << ls.empty() << endl;
	ls.push_front(1);
	cout << "ls.empty()? " << ls.empty() << endl;
	ls.push_front(0);
	cout << "ls.front(): " << ls.front() << "; "
		<< "ls.back(): " << ls.back() << endl;
	ls.push_back(2);
	cout << "ls.front(): " << ls.front() << "; "
		<< "ls.back(): " << ls.back() << endl;
	ls.pop_front();
	cout << "ls.front(): " << ls.front() << "; "
		<< "ls.back(): " << ls.back() << endl;

	List::iterator it = ls.begin();

	it++;

	*it;
	*it=42;

	it!=ls.end();

	ls.insert(ls.begin(),-42);
	ls.insert(ls.end(),42);

	for(List::iterator i=ls.begin();i!=ls.end();++i) {
		cout << (*i) << ' ';
	}
	cout << endl;

	ls.erase(ls.begin());
	//ls.erase(--ls.end());

	for(List::iterator i=ls.begin();i!=ls.end();++i) {
		cout << (*i) << ' ';
	}
	cout << endl;
	return 0;
}

// Blue Waffle!
