#include <iostream>
#include "Field.h"
#include "Judge.h"

using namespace std;

int main(void){
	Field field;
	Judge judge;
	
	cout << "四目並べ!" << endl << endl;
	field.show();
	if(judge.isOver(field) != Chip::NONE) cout << "Over" << endl;
	field.put(Chip::BLACK, 5);
	field.put(Chip::BLACK, 4);
	field.put(Chip::BLACK, 4);
	field.put(Chip::BLACK, 3);
	field.put(Chip::BLACK, 3);
	field.put(Chip::BLACK, 3);
	field.put(Chip::WHITE, 2);
	field.put(Chip::BLACK, 2);
	field.put(Chip::BLACK, 2);
	field.show();
	if(judge.isOver(field) != Chip::NONE) cout << "Over" << endl;
	field.put(Chip::BLACK, 2);
	field.show();
	if(judge.isOver(field) != Chip::NONE) cout << "Over" << endl;
	return 0;
}
