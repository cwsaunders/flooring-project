//<CSIS112 Lab1 Christian Saunders> -- This program takes flooring input and produces tiling output information. This program may be used to know how
//much tile is necessary for a flooring job.
//CSIS 112-<02>
//<Sources: stack overflow (URL: https://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer)>
//<Programming and Problem Solving with C++>

//Include Statements
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Global declarations
const int boxSize = 20;

//Function prototypes
float testInteger(float);
float getTileNumber(float, float, float, float, int);

int main()
{
	cout << "Christian Saunders -- Lab 1" << endl << endl;

	//Variable declarations
	char programExit; //Used for exiting program
	float rooms; //Number of rooms
	int tileSize; //Input tile size
	float widthFeet; //Input width feet
	float widthInches; //Input width inches
	float lengthFeet; //Input length feet
	float lengthInches; //Input length inches
	float totalTiles = 0; //Total tiles, begins at zero

	//Program logic
	cout << "Enter number of rooms: "; //Prompt
	cin >> rooms;
	testInteger(rooms);
	for (int i = 0; i < rooms; --rooms)
	{
		cout << endl << "Enter size of tile in inches: "; //Prompt
		cin >> tileSize;
		testInteger(tileSize);
		cout << endl << "Enter room width (feet and inches, seperated by a space):"; //Prompt
		cin >> widthFeet;
		while (cin.fail() || widthFeet < 0) //Source: stackoverflow
		{
			cout << "Oops! Wrong entry detected. Try again." << endl;
			cin.clear();
			cin.ignore(256, ' ');
			cin >> widthFeet;
		}
		cin >> widthInches;
		while (cin.fail() || widthInches < 0 || widthInches > 11) //Source: stackoverflow
		{
			cout << "Oops! Wrong entry detected. Try again." << endl;
			cin.clear();
			cin.ignore(256, ' ');
			cin >> widthInches;
		}

		cout << endl << "Enter room length (feet and inches, seperated by a space):"; //Prompt
		cin >> lengthFeet;
		while (cin.fail() || lengthFeet < 0) //Source: stackoverflow
		{
			cout << "Oops! Wrong entry detected. Try again." << endl;
			cin.clear();
			cin.ignore(256, ' ');
			cin >> lengthFeet;
		}
		cin >> lengthInches;
		while (cin.fail() || widthInches < 0 || lengthInches > 11) //Source: stackoverflow
		{
			cout << "Oops! Wrong entry detected. Try again." << endl;
			cin.clear();
			cin.ignore(256, ' ');
			cin >> lengthInches;
		}

		cout << "Tiles required for room: " << ceil(getTileNumber(widthFeet,widthInches,lengthFeet,lengthInches,tileSize)) << endl;
		cout << "Boxes required for room: " << ceil(getTileNumber(widthFeet, widthInches, lengthFeet, lengthInches,tileSize) / boxSize) << endl;
		totalTiles = totalTiles + getTileNumber(widthFeet, widthInches, lengthFeet, lengthInches,tileSize);
	}
	cout << "Total tiles required: " << ceil(totalTiles) << endl;
	cout << "Total boxes required: " << ceil(totalTiles / boxSize) << endl;
	cout << "Total extra tiles: " << ceil(totalTiles/(ceil(totalTiles/boxSize))) << endl; //Tiles divided by boxes
	

	//Closing program statements
	cout << "Enter any key to exist program." << endl;
	cin >> programExit;
	return 0;
}

//Function definitions
float testInteger(float getInt)
{
	while (cin.fail() || getInt < 0) //Source: stackoverflow
	{
		cout << "Oops! Wrong entry detected. Try again." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> getInt;
		return getInt;
	}
}

float getTileNumber(float widthFeet, float widthInches, float lengthFeet, float lengthInches, int tileSize)
{
	float allWidthInches;
	float allLengthInches;
	float initialTiles;

	allWidthInches = (widthFeet * 12 + widthInches);
	allLengthInches = (lengthFeet * 12 + lengthInches);

	initialTiles = (allWidthInches / tileSize) * (allLengthInches / tileSize);
	return initialTiles;
}

