// ToyRobot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <conio.h>
#include <algorithm>

#include "Robot.h"
#include "Board.h"

using namespace std;

void ShowCommands()
{
	cout << "Commands available: " << endl;
	cout << "1. The place command allows the player to initialize the robot's location and direction on a board.\n" << endl;
	cout << "\tplace x,y,direction" << endl;
	cout << "\tex: place 2,2,east\n" << endl;
	cout << "\twhere x and y are coordinates" << endl;
	cout << "\tand direction refers to north, south, east, west\n" << endl;
	cout << "2. The move command instructs the robot to move 1 square in the direction it is facing." << endl;
	cout << "3. The left command instructs the robot to rotate 90° counterclockwise." << endl;
	cout << "4. The right command instructs the robot to rotate 90° clockwise." << endl;
	cout << "5. The report command outputs the robot's current location on the tabletop and the direction it is facing." << endl;
	cout << "6. The clear command to clear the screen." << endl;
	cout << "7. The exit command exits the game." << endl;

}

int main()
{
	// Initilize a board
	Board board;
	board.Create();

	Robot robot(board.length, board.width);

	cout << "Welcome to Toy Robot" << endl;
	ShowCommands();
	
	string command;
	while (true)
	{
		cout << "Command: ";
		getline(cin, command);

		cout << "You have entered: " << command << endl;

		// Convert to lowercase
		transform(command.begin(), command.end(), command.begin(),
			[](unsigned char c) { return tolower(c); });
		
		if (command.find("place", 0) == 0)
		{
			bool ok = robot.Init(command);
			if (ok == false)
			{
				cout << "You have entered an incorrect location and\\or direction.\n" << endl;				
				continue;
			}
			board.Display(robot);
		}
		else if (command == "exit")
		{
			// Exit
			break;
		}

		if (robot.isInitialized == false)
		{
			cout << "Call place command to set the robot on the board before calling other commands.\n" << endl;
			continue;
		}

		if (command.find("move", 0) == 0)
		{
			bool ok = robot.Move();
			if (ok == false)
			{
				cout << "The robot is about to fall off the board. Change direction.\n" << endl;
			}
			else
			{
				board.Display(robot);
			}
		}
		else if (command.find("left", 0) == 0)
		{
			robot.Left();
			board.Display(robot);
			
		}
		else if (command.find("right", 0) == 0)
		{
			bool ok = robot.Right();			
			board.Display(robot);
		}
		else if (command.find("report", 0) == 0)
		{
			board.Display(robot);
		}
		else if (command == "clear")
		{
			system("cls");
		}
	}

	cout << "You have exited the game. See ya .. " << endl;
	_getch();
}

