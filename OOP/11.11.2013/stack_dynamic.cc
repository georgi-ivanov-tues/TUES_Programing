//Team: DEBA MAGADA!

#include<iostream>

using namespace std;

class StackError{

};

class Stack{
	const static int CHUNK_SIZE=5;
	int top_;
	int capacity_;
	int* data_;
	
	bool has_capacity() const{
		return top_<capacity_;
	}
	
	void resize() {
		cout<<"rezise() called..." << endl;
		capacity_+=CHUNK_SIZE;
		int *new_data = new int [capacity_];
		//Zadelq pamet ot tip int s golemina capacity!
		
		for(int i=0;i<top_;i++){
			new_data[i]=data_[i];
		}
		
		delete [] data_;
		
		data_=new_data;
	}
	
public:
	
	Stack()
	:top_(0),
	 capacity_(CHUNK_SIZE),
	 data_(new int[capacity_])
	 {}
	 
	 ~Stack() {
	 	cout <<"Kotka called to exterminate the world" << endl;
	 	delete [] data_;
	 }
	 
	 Stack(const Stack& other)
	 : top_(other.top_),
	   capacity_(other.capacity_),
	   data_(new int[capacity_])
	 {
 		for(int i = 0;i < top_; i++){
			data_[i]=other.data_[i];
		}
	 }
	 
	 Stack& operator=(const Stack& other){
	 	if(this!=&other){	
		 	delete [] data_;
		 	
		 	top_ = other.top_;
		 	capacity_ = other.capacity_;
		
			data_=new int[capacity_];
			for(int i = 0; /*  .|.  */ i < top_; i++){
				data_[i]=other.data_[i];
			}
		}	
		return *this;
	}
	 
	//int jivot(){
	//	 return 0;
	//}
	 
	 bool empty() const{
	 	return top_ == 0;
	 }
	 
	 void push(int val){
	 	if (!has_capacity()) {
	 		resize();
	 	}
	 	data_[top_++] = val;
	 }
	 
	 int pop() {
	 	if(empty()) {
	 		throw StackError();
	 	}
	 	return data_[--top_];
	 }
	 
};

int main(){
	Stack st;
	cout << "st.empty()? = " << st.empty() << endl;
	st.push(1);
	cout << "st.empty()? = " << st.empty() << endl;
	cout << "EBI SE JONI" <<endl;
	for(int i=0;i<10;i++){
		st.push(i);
	}
	
	while(!st.empty()){
		cout << "st.pop() = " << st.pop() << endl;
	}
	
	// Next class... Like we give a fuck...
	
	for(int i = 0; i < 10; i++){
		st.push(i*10);
	}
	
	Stack st3=st;
	
	/*Stack st2;
	st2 = st;
	while(!st2.empty()){
		cout << "st2.pop() = " << st2.pop() << endl;
	}
	
	int a = 42;
	a=a;
	st=st;
	*/
	return 0;
}



/*C++ hates us...
st.empty()? = 1
st.empty()? = 0
EBI SE JONI
rezise() called...
rezise() called...
st.pop() = 9
100 prais tai Nedelko...
st.pop() = 8
st.pop() = 7
st.pop() = 6
st.pop() = 5
st.pop() = 4
st.pop() = 3
st.pop() = 2
st.pop() = 1
st.pop() = 0
st.pop() = 1
Kotka called to exterminate the world
Kotka called to exterminate the world
*** glibc detected *** ./a.out: double free or corruption (fasttop): 0x09c93050 ***
======= Backtrace: =========
/lib/libc.so.6[0x6acab1]
/usr/lib/libstdc++.so.6(_ZdlPv+0x22)[0x1b0592]
/usr/lib/libstdc++.so.6(_ZdaPv+0x1e)[0x1b05ee]
./a.out[0x8048bd6]
./a.out[0x8048a3a]
/lib/libc.so.6(__libc_start_main+0xe6)[0x654ce6]
./a.out[0x80487c1]
======= Memory map: ========
00101000-001e2000 r-xp 00000000 08:03 28052105   /usr/lib/libstdc++.so.6.0.13
001e2000-001e6000 r--p 000e0000 08:03 28052105   /usr/lib/libstdc++.so.6.0.13
001e6000-001e8000 rw-p 000e4000 08:03 28052105   /usr/lib/libstdc++.so.6.0.13
001e8000-001ee000 rw-p 00000000 00:00 0 
0061c000-0063a000 r-xp 00000000 08:03 22545285   /lib/ld-2.12.so
0063a000-0063b000 r--p 0001d000 08:03 22545285   /lib/ld-2.12.so
0063b000-0063c000 rw-p 0001e000 08:03 22545285   /lib/ld-2.12.so
0063e000-007c7000 r-xp 00000000 08:03 22545288   /lib/libc-2.12.so
007c7000-007c8000 ---p 00189000 08:03 22545288   /lib/libc-2.12.so
007c8000-007ca000 r--p 00189000 08:03 22545288   /lib/libc-2.12.so
007ca000-007cb000 rw-p 0018b000 08:03 22545288   /lib/libc-2.12.so
007cb000-007ce000 rw-p 00000000 00:00 0 
007d0000-007f8000 r-xp 00000000 08:03 22545301   /lib/libm-2.12.so
007f8000-007f9000 r--p 00027000 08:03 22545301   /lib/libm-2.12.so
007f9000-007fa000 rw-p 00028000 08:03 22545301   /lib/libm-2.12.so
00978000-00979000 r-xp 00000000 00:00 0          [vdso]
00cd8000-00cf5000 r-xp 00000000 08:03 22545314   /lib/libgcc_s-4.4.5-20110214.so.1
00cf5000-00cf6000 rw-p 0001d000 08:03 22545314   /lib/libgcc_s-4.4.5-20110214.so.1
08048000-0804a000 r-xp 00000000 09:00 32637264   /home/student11b4/Desktop/11b2013/a.out
0804a000-0804b000 rw-p 00001000 09:00 32637264   /home/student11b4/Desktop/11b2013/a.out
09c93000-09cb4000 rw-p 00000000 00:00 0          [heap]
b7754000-b7757000 rw-p 00000000 00:00 0 
b7776000-b7779000 rw-p 00000000 00:00 0 
bfe49000-bfe5e000 rw-p 00000000 00:00 0          [stack]
Aborted (core dumped)
*/
