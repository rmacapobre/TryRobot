#pragma once

#include <vector>

#include "Robot.h"

class Board
{
public:
	int length;
	int width;

	std::vector<std::vector<int>> v;

	Board();
	Board(int l, int w);
	void Create();
	void Display(Robot& robot);
};


