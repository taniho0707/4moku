/*
 * @file Judge.h
 */

#pragma once

#include <cstdlib>
#include "Field.h"


class Judge{
private:
	Chip isOverColumn(Field&);
	Chip isOverRow(Field&);
	Chip isOverOblRightup(Field&);
	Chip isOverOblLeftup(Field&);
	
public:
	Judge();

	Chip isOver(Field&);
	
};
