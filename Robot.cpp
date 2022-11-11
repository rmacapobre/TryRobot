#include "Robot.h"

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

Robot::Robot() : 
	row(0), col(0), d(north), isInitialized(false),
	maxRow(5), maxCol(5)
{
}

Robot::Robot(int length, int width) : Robot()	
{
	maxRow = length;
	maxCol = width;
}

bool Robot::Init(string value)
{
	vector<string> v;
	istringstream iss(value);

	// split by comma
	string s;
	while (getline(iss, s, ','))
	{
		v.push_back(s);
	}
	
	if (v.size() == 3)
	{
		string place = "place ";
		string xcoord = v[0].replace(v[0].find(place), place.size(), "");
		string ycoord = v[1];
		string facing = v[2];

		row = atoi(xcoord.c_str());
		col = atoi(ycoord.c_str());
		
		if (facing == "north") d = north;
		else if (facing == "south") d = south;
		else if (facing == "east") d = east;
		else if (facing == "west") d = west;

		if (IsOutside(row, col))
			return false;
		
		isInitialized = true;
		return true;
	}

	return false;
}

string Robot::GetDirection()
{
	string ret;
	switch (d)
	{
		case north: ret = "north"; break;
		case south: ret = "south"; break;
		case west: ret = "west"; break;
		case east: ret = "east"; break;
	}

	return ret;
}

bool Robot::IsOutside(int x, int y)
{
	if (x < 0) return true;
	if (y < 0) return true;

	if (x >= maxRow) return true;
	if (y >= maxCol) return true;

	return false;
}

bool Robot::Move()
{
	if (isInitialized == false) return false;

	int currentRow = row;
	int currentCol = col;

	switch (d)
	{
		case north: currentRow -= 1;  break;
		case south: currentRow += 1;  break;
		case east: currentCol += 1;  break;
		case west: currentCol -= 1;  break;
	}

	if (IsOutside(currentRow, currentCol))
		return false;

	col = currentCol;
	row = currentRow;

	return true;
}

bool Robot::Left()
{
	if (isInitialized == false) return false;

	switch (d)
	{
		case north: d = west;  break;
		case south: d = east;  break;
		case east: d = north;  break;
		case west: d = south;  break;
	}

	return true;
}

bool Robot::Right()
{
	if (isInitialized == false) return false;

	switch (d)
	{
		case north: d = east;  break;
		case south: d = west;  break;
		case east: d = south;  break;
		case west: d = north;  break;
	}

	return true;
}