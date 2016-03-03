/**
 * @file Judge.cpp
 */

#include "Judge.h"

Judge::Judge(){
	
}

Chip Judge::isOverColumn(Field& f){
	for(auto i=0; i<7; ++i){
		for(auto j=0; j<3; ++j){
			auto tmp_chip = f.get(i, j);
			if(tmp_chip != Chip::NONE){
				auto counter = 1;
				for(auto k=1; k<4; ++k){
					if(f.get(i, j+k) == tmp_chip) ++counter;
					else break;
				}
				if(counter == 4) return tmp_chip;
			}
		}
	}
	return Chip::NONE;
}

Chip Judge::isOverRow(Field& f){
	for(auto i=0; i<6; ++i){
		for(auto j=0; j<4; ++j){
			auto tmp_chip = f.get(j, i);
			if(tmp_chip != Chip::NONE){
				auto counter = 1;
				for(auto k=1; k<4; ++k){
					if(f.get(j+k, i) == tmp_chip) ++counter;
					else break;
				}
				if(counter == 4) return tmp_chip;
			}
		}
	}
	return Chip::NONE;
}

Chip Judge::isOverOblRightup(Field& f){
	for(auto i=3; i>-3; --i){
		auto dif = (abs(2*i-1)*(-1)+7) /2;
		for(auto j=0; j<dif; ++j){
			if(i >= 0){
				auto tmp_chip = f.get(i, j);
				if(tmp_chip != Chip::NONE){
					auto counter = 1;
					for(auto k=1; k<4; ++k){
						if(f.get(i+k, j+k) == tmp_chip) ++counter;
						else break;
					}
					if(counter == 4) return tmp_chip;
				}
			} else {
				auto tmp_chip = f.get(0, j+(abs(i)));
				if(tmp_chip != Chip::NONE){
					auto counter = 1;
					for(auto k=1; k<4; ++k){
						if(f.get(0, j+(abs(i))+k) == tmp_chip)
							++counter;
						else break;
					}
					if(counter == 4) return tmp_chip;
				}
			}
		}
	}
	return Chip::NONE;
}

Chip Judge::isOverOblLeftup(Field& f){
	for(auto i=3; i<9; ++i){
		auto dif = (abs(2*i-11)*(-1)+7) /2;
		for(auto j=0; j<dif; ++j){
			if(i < 7){
				auto tmp_chip = f.get(i, j);
				if(tmp_chip != Chip::NONE){
					auto counter = 1;
					for(auto k=1; k<4; ++k){
						if(f.get(i-k, j+k) == tmp_chip) ++counter;
						else break;
					}
					if(counter == 4) return tmp_chip;
				}
			} else {
				auto tmp_chip = f.get(0, j+(i-6));
				if(tmp_chip != Chip::NONE){
					auto counter = 1;
					for(auto k=1; k<4; ++k){
						if(f.get(0, j+(i-6)+k) == tmp_chip)
							++counter;
						else break;
					}
					if(counter == 4) return tmp_chip;
				}
			}
		}
	}
	return Chip::NONE;
}


Chip Judge::isOver(Field& f){
	Chip ret;
	ret = isOverColumn(f);
	if(ret != Chip::NONE) return ret;
	ret = isOverRow(f);
	if(ret != Chip::NONE) return ret;
	ret = isOverOblRightup(f);
	if(ret != Chip::NONE) return ret;
	ret = isOverOblLeftup(f);
	if(ret != Chip::NONE) return ret;
	return Chip::NONE;
}
