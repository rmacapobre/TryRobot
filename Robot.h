#pragma once

#include <vector>
#include <string>

class Robot
{
public:
	int row;
	int col;
	bool isInitialized;

	int maxRow;
	int maxCol;

	enum direction
	{
		north,
		south,
		east,
		west
	};

	direction d;

	Robot();
	Robot(int length, int width);

	bool Init(std::string value);
	bool IsOutside(int row, int col);
	std::string GetDirection();
	bool Move();
	bool Left();
	bool Right();

};


