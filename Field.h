/*
 * 
 */

#pragma once

#include <iostream>
#include <array>
#include <stdint.h>

using namespace std;

enum class Chip : uint8_t{
	BLACK,
	WHITE,
	NONE
};

class Field{
private:
	array<array<Chip, 6>, 7> f;

public:
	Field();

	void clear();
	bool put(Chip player, uint8_t num_line);

	Chip get(uint8_t num_line, uint8_t num_depth);

	void show();
};

