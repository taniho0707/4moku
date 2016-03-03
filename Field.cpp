/**
 * @file 
 */

#include "Field.h"

Field::Field(){
	clear();
}

void Field::clear(){
	for (auto i=0; i<7; i++) {
		for (auto j=0; j<6; j++) {
			f[i][j] = Chip::NONE;
		}
	}
}

bool Field::put(Chip player, uint8_t num_line){
	if(f[num_line][5] != Chip::NONE) return false;
	for(auto i=0; i<6; ++i){
		if(f[num_line][i] != Chip::NONE){
			f[num_line][i] = player;
			return true;
		}
	}
}

Chip Field::get(uint8_t num_line, uint8_t num_depth){
	return f[num_line][num_depth];
}

void Field::show(){
	cout << "[ 0 1 2 3 4 5 6 ]" << endl;
	for(auto i=0; i<6; ++i){
		cout << "| ";
		for(auto j=0; j<7; ++j){
			if(f[j][i] == Chip::WHITE)
				cout << "O ";
			else if(f[j][i] == Chip::BLACK)
				cout << "X ";
			else
				cout << "  ";
		}
		cout << "|" << endl;
	}
	cout << "-----------------" << endl;
}
