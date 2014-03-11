// #povrashtam...
#include <iostream>
#include <vector>

using namespace std;

enum Direction{
	NONE = 0, // 0, 0000
	DOWN = 1, // 1, 0001
	RIGHT = 1<<1, // 2, 0010 (1 shiftnato vednaj nalqvao (01 -> 10))
	TOP = 1<<2, // 4, 0100
	LEFT = 1<<3, // 8, 1000
// 0001 - DOWN (ima stena otdolo)
// 1111 - Vsichki posoki
// 1010 - RIGHT i LEFT
};

class Cell{
	unsigned walls_;
	unsigned row_;
	unsigned col_;
public:
		Cell(int row, int col)
		: walls_(DOWN|RIGHT|TOP|LEFT),
		  row_(row),
		  col_(col)
		{}
		
		// 1101									0100
		// 0100									0100
		// 1101 & 0100 = 0100 - true		0000 - false
		bool has_wall(Direction dir) const{
			return dir & walls_;
		}
		
		// 0110 - imame steni na right i top		0110
		// 1000 - iskame da setnet left				0100
		// 1110 - slagame i lqvata stena				0110
		Cell& set_wall(Direction dir){
			walls_ |= dir;
			return *this;
		}
		
		//  0110 - steni
		//  0100 - koq stena da mahnem
		//~ 1011 - otricanie na stenata
		//& 0010 - rezultat mejdu stenite i otricanieto na stenata	 	
		Cell& unset_wall(Direction dir){
			walls_ &= ~dir;
			return *this;
		}
		
		static const int WALL_SIZE = 20;
		
		void draw(ostream& out) const{
			out << (col_+1)*WALL_SIZE << ' '
				 << (row_+1)*WALL_SIZE << ' '
				 << "moveto" << endl;
			out << 5 << ' ' << 5 << ' '
				 << "rlineto" << endl;
		}
};

class Board{
	unsigned height_, width_;
	vector<Cell> cells_;
public:
	Board(unsigned height, unsigned width)
	: height_(height),
	  width_(width)
	{
		for(unsigned row = 0; row < height_; row++){
			for(unsigned col = 0; col < width_; col++){
				cells_.push_back(Cell(row,col));
			}
		}
	}
	
	Cell& get_cell(unsigned row, unsigned col){
		return cells_[row*width_+col];
	}
	
	//const Cell& get_cell(unsigned row, unsigned col){
	//	return cells_[row*width_+col];
	//}
	
	void draw(ostream& out) const{
		out<<"newpath"<< endl;
		for(vector<Cell>::const_iterator it = cells_.begin(); it != cells_.end(); ++it){
			(*it).draw(out);	 
		}
		
		out << "stroke" << endl;
		out << "showpage" << endl;
	}
};

int main(){
/*
	Cell c(0,0);
	cout << "Has wall left ? " << c.has_wall(LEFT) << endl;	
	c.unset_wall(LEFT);
	cout << "Has wall left ? " << c.has_wall(LEFT) << endl;	
	cout << "Has wall right ? " << c.has_wall(RIGHT) << endl;
	c.set_wall(LEFT);
	cout << "Has wall left ? " << c.has_wall(LEFT) << endl;		
	
	Board b(20,20);
	
	Cell& rc = b.get_cell(10,10);	
	rc.unset_wall(DOWN);
	cout << "rc.has_wall(DOWN) = " << rc.has_wall(DOWN) << endl;
	cout << b.get_cell(10,20).has_wall(DOWN) << endl;
	
	//const Board& cb = b;
	
	//Cell& crc = cb.get_cell(10,10);
	//crc.unset_wall(UP);
	
*/
	Board b(20,20);
	b.draw(cout);	
	
	return 0;
}
