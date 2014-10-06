//#durveta
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

template<typename T>
struct Node {
	T data_;
	Node* left_;
	Node* right_;
	
	Node(const T& val)
	: data_(val/*io*/),
	  left_(0),
	  right_(0) // protiv molci
	{}
	
};

template<typename T>
class Tree {
	Node<T>* root_;
	
	Node<T>* copy_tree(const Node<T>* src){
		Node<T>* dst = 0;
		if(src){
			dst = new Node<T>(src->data_);
			dst->left_ = copy_tree(src->left_); //	hvani taq reKURsiq
			dst->right_ = copy_tree(src->right_);// sporno aktrisa
		}
		return dst;
	}		
	
	void print(const Node<T>* ptr){// prut
		if(ptr) {
			cout << ptr->data_ << endl;
			print(ptr->left_); // pak si hapni malko rekursiq
			print(ptr->right_);
		}
	}
	
	void /*bradva*/ delete_tree(Node<T>* ptr){
		if(ptr){
			delete_tree(ptr->left_);
			delete_tree(ptr->right_);
			delete ptr;
		}
	} // FUCK YOU DOLPHIN
	
public:
	Tree()
	: root_(0)
	{}
	
	~Tree() {
		delete_tree(root_);
	}
	
	bool empty() const{
		return root_ == 0;
	}
	
	void create3(const T& val, const Tree& left, const Tree& right){
		delete_tree(root_); // darvari sme maklo nie

		root_ = new Node<T>(val/*io*/);
		root_->left_ = copy_tree(left.root_);
		root_->right_ = copy_tree(right.root_);
	}

	void print() {
		print(root_);
	}
	
	void parse_input(string str){
		int i;
		for(i = 0; i < str.length(); i++){
			//cout << str[i];		
			if(str[i] == ' '){ //42 43 45 47
				if(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' || str[i-1] == '/'){
					// Suzdavame novo durvo s centur znaka i left i right chisloto
					//create3()
				}
			}
		}
		cout << endl;
	}
	
};

int main(){
	/*
	Tree<int> t;	
	cout << "t.empty()?? = " << t.empty() << endl;

	Tree<int> t1;
	Tree<int> t2;
	t1.create3(1, Tree<int>(), Tree<int>());
	t2.create3(3, Tree<int>(), Tree<int>());		
		
	t.create3(2, t1, t2);	
	cout << "t.empty()?? = " << t.empty() << endl; // En e empty!!
	t.print();
	
	t.create3(2, t1, t2);
	*/
	
	
	Tree<string> t;
	string str;
	cin >> str;

	t.parse_input(str);
	
	return 0;
}

// trici

// Raboti kato pushka, toest ne gurmi. - Chorbi 18.03.2014

/*
	Zadacha:
	5*(3-1)

		(*)
	  /  \
	(5)  (-)
	     /  \
	   (3)  (1)

*/
