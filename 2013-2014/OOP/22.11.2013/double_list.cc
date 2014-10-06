#include <iostream>

// Insert something smart here... Bitch...

/*
Dvusvarzan spisak:
1. Da nqmate jivot...
2.Vseki element darji ukaztel kakto kam sledva6tiq taka i kam predhodniq element
3.Imate cikal... Ako ste majko == problem...
4.#potka...
*/

using namespace std;

class ListError{};

class List{
	struct Node{ // struct Nude...
		int data_;
		Node* next_;
		Node* prev_;
		
		Node(int/*avtomobilen*/ val)
		: data_(val),
		  next_(0),
		  prev_(0)
		{}
	};
		
	Node* head_;
public:
	List()
	: head_(new Node(42))
	{
		// Very code
		// Much hard
		// Such wow
		head_->next_ = head_->prev_ = head_;// Bah maamu... ot dqsno na lqvo...	
	}
	
	~List(){
		while(!empty()){
			pop_front();
		}
		delete head_; // Ed, Edd and Eddy...
	}
	
	bool empty() const {
		return head_ == head_->next_;
	}
	
	void push_front(int val/*io*/){
		Node* ptr = new Node(val);
		Node* front = head_->next_;
		
		head_->next_=ptr;
		ptr->prev_=head_;
		
		ptr->next_=front;
		front->prev_=ptr;
	}
	
	void push_back(int val) { // Bah umnite tipove
		Node* ptr = new Node(val);
		Node* back = head_->prev_;
		
		head_->prev_ = ptr;
		ptr->next_ = head_;
		
		ptr->prev_ = back;
		back->next_ = ptr;
	}
	
	int front() const {
		if(empty()){
			throw ListError();
		}
		return head_->next_->data_; // dafuq...
	}
	
	int back() const {
		if(empty()){
			throw/*up*/ ListError();
		}
		return head_->prev_->data_; // more dafuq here...
	}
	
	void pop_front(){
		if(empty()){
			throw ListError();
		}
		Node* front = head_->next_;
		Node* new_front = front->next_;
		
		head_->next_ = new_front;
		new_front->prev_=head_;
		
		delete front;
	}
	
	void pop_back(){
		if(empty()){
			throw ListError();
		}
		Node* back = head_->prev_;
		Node* new_back = back->prev_;
		
		head_->prev_ = new_back;
		new_back->prev_=head_;
		
		delete back;
	}	
	
	class iterator{
		friend class List;
		
		Node* current_;
		
		iterator(Node* current)
		: current_(current)
		{}
	public:
		iterator& operator++(){ // Shtoto moga da si go pozvolq!
			current_=current_->next_;									
			return *this;
		}
		
		iterator operator++(int){
			iterator res=*this;				
			current_=current_->next_;
			return res;
		}
		
		int& operator*(){
			return current_->data_;
		}
		
		bool operator==(const iterator& other){
			return current_==other.current_;
		}

		bool operator!=(const iterator& other){
			return ! operator==(other);
		}
	};
	
	iterator begin() const{
		return iterator(head_->next_);
	}
	
	iterator end() const{
		return iterator(head_/*shot*/);
	}
	
		
	iterator insert(iterator pos, int val){
		Node* node = new Node(val);
		Node* curr = pos.current_;
		
		Node* prev = curr->prev_;
		
		prev->next_ = node;
		node->prev_ = prev;
		
		node->next_ = curr;
		curr->prev_ = node;
		
		return iterator(node);
	}
	
	iterator erase(iterator pos){
		Node* curr=pos.current_;
		
		Node* next=curr->next_;	
		Node* prev=curr->prev_;
	
		prev->next_=next;
		next->prev_=prev;
	
		delete curr;
		
		return iterator(next);	
	}
};

int main() {
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
	
	List::iterator it=ls.begin();
	
	it++;
	*it=42;
	it!=ls.end();
	
	ls.insert(ls.begin(),-42);
	ls.insert(ls.end(),42);
	
	ls.erase(ls.begin());
	
	for(List::iterator i=ls.begin();i!=ls.end();++i){
		cout<<(*i)<< ' ' ;
	}
	cout<<endl;
	return 0;
}



//www.candybox2.net
