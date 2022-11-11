#include "Board.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

Board::Board() : length(5), width(5)
{
}

Board::Board(int l, int w)
{
	length = l;
	width = w;
}

void Board::Create()
{
	for (int i = 0; i < width; i++)
	{
		vector<int> row;
		for (int j = 0; j < length; j++)
		{
			row.push_back(0);
		}
		v.push_back(row);
	}
}

void Board::Display(Robot& robot)
{
	for (int i = 0; i < width; ++i)
	{
		string row;
		for (int j = 0; j < length; ++j)
		{
			string target;
			stringstream ss;
			ss << robot.GetDirection()[0];
			ss >> target;

			row += (i == robot.row && j == robot.col) ? target + " " : "0 ";
		}

		stringstream ss;
		ss << i << ": " << row << endl;
		cout << ss.str();
	}

	cout << "The robot is at (" << robot.row << "," << robot.col << ") facing " << robot.GetDirection() << endl;
}