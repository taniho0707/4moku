#include <iostream>
#include <cstdio>
#include "Field.h"
#include "Judge.h"

using namespace std;

int main(void){
	Field field;
	Judge judge;
	
	cout << "四目並べ!" << endl << endl;
	int ch = '\0';

	while(true){
		cout << "先攻のターンです。ICON='X'" << endl;
		field.show();
		do{
			ch = getchar();
			if(ch < '7' && ch >= '0')
				field.put(Chip::BLACK, ch-'0');
		} while(ch > '6' || ch < '0');
		if(judge.isOver(field) != Chip::NONE){
			cout << "WIN 'X'" << endl;
			break;
		}
		
		cout << "後攻のターンです。ICON='O'" << endl;
		field.show();
		do{
			ch = getchar();
			if(ch < '7' && ch >= '0')
				field.put(Chip::WHITE, ch-'0');
		} while(ch > '6' || ch < '0');
		if(judge.isOver(field) != Chip::NONE){
			cout << "WIN 'O'" << endl;
			break;
		}
	}
	field.show();
	return 0;
}
