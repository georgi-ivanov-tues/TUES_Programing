#include <iostream> // Isus be6e tuk...

// Vsqka nadejda tuk ostavete...

/*
Spisuk - Ot vseki element imame ukazatel kam sledva6tiq element
Vseki element ima stoinost
Posledniq element e "zatapen"(toi e 0)
top_ darji ukazatel kam parviq element

push() - dobavqme nov element
		naso4ecame next kam top_
		poso4vame top_ kam noviq element

pop() - vzemame element
		zapomnqme stoinosta mu
		top_ mestim kam sledva6tiq
		vra6tame stoinosta
		izchistvame pametta
		
---------------------

Edinstvenata razlika mejdu "Struct" i "Class" sa pravilata za dostap

---------------------
Razlika mejdu "." i "->"

Node n;
n.next_;
n.pop();

Node p = &n;
p->next_;
p->data_;

---------------------
Dvusvarzan spisak:
1. Da nqmate jivot...
2.Vseki element darji ukaztel kakto kam sledva6tiq taka i kam predhodniq element
3.Imate cikal... Ako ste majko == problem...
4.#potka...
*/

using namespace std;

class StackError{};

class Stack{
	struct Node{
		int data_;
		Node* next_;
		
		Node(int val)
		: data_(val),
		  next_(0)
		{}
	};
	
	Node* top_;	
public:
	Stack()
	: top_(0)
	{}
	
	~Stack(){
		while(!empty()){
			/*carkoven*/pop(); // daiba...
		}
	}
	
	bool empty() const {
		return top_==0;
	}
	
	void push(int val){
		Node* ptr = new Node(val);
		ptr->next_ = top_;
		top_ = ptr;
	}
	
	int pop(){
		if(empty()){
			throw /*tuhla*/ StackError();
		}
		Node* ptr = top_;
		top_ = top_->next_;
		
		int res = ptr->data_;
		delete ptr;
		return res;
	}
};

int main(){
	Stack st;
	st.push(42);
	cout << "st.empty()? = " << st.empty() << endl; 
	cout << "st.pop() = " << st.pop() << endl; 
	// Nedelko sepiqta!
	return 0;
}

// ... i v gaza si q navrete...











// potka...
