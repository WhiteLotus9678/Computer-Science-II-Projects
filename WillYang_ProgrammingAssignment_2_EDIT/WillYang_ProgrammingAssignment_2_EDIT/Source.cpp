/*
William Yang
03/01/2016
CS 145
*/
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes

/*
------------------------------------------------------------------------------
Game Start
------------------------------------------------------------------------------
This function allows the player to set the pile size to a number between 10
and a number n (which the user inputs).
*/

void gameStart(double &a, bool &b);

/*
------------------------------------------------------------------------------
Play
------------------------------------------------------------------------------
This function uses all of the other functions to play Nim. Passes the pile size
and player bool variable into the functions too.
*/

void play(double &a, bool &b);

/*
------------------------------------------------------------------------------
Computer Options
------------------------------------------------------------------------------
When the computer takes its turn, it makes the following legal move:

A) Take off enough marbles to make the size of the remaining pile a power of 2
minus 1 (1, 3, 7, 15, 31 are some examples of the power of 2 minus 1) if the
current pile size is not one of those power of 2 minus 1.

B) When the current pile size is already a power of 2 minus 1, make a random
move taking at least one but at most half of the marbles.
*/

void computerTurn(double &a, bool &b);

/*
------------------------------------------------------------------------------
Player Options
------------------------------------------------------------------------------
When the player takes his/her turn, player can take at least one but at
most half of the marbles from the pile. The function will ask how many
marbles the player wants to remove and verify if it is legal.
*/

void playerTurn(double &a, bool &b);

/*
------------------------------------------------------------------------------
Main Function
------------------------------------------------------------------------------
This Function calls all of the other functions needed to play Nim and gives
values to some variables that will be passed into functions.
*/

int main()
{

	double pileSize = 0; // Sets the pile size to zero
	bool player = false; // This variable determines whether the player goes first or not

	gameStart(pileSize, player); // Sets the pile size and determines which opponent gets to play first
	cout << endl;

	play(pileSize, player); // Plays the rest of the game with the computer and player's turn as well as determing the winning conditions

	system("pause"); // Pauses the game for a moment before the program exits

	return 0;
}

/*
------------------------------------------------------------------------------
Functions
------------------------------------------------------------------------------
*/

void gameStart(double &a, bool &b)
{
	int pileSize; // Sets the pile size
	int temp; // Temporary variable to pick which opponent goes first
	do {
		cout << "Welcome to the game of Nim.\nTo start, please enter a number greater than 10 to serve as\nthe max range of the pile size." << endl;
		cin >> pileSize;

		// Need both of these to functions to correctly unallow invalid inputs
		cin.clear(); // skips similar to "a"
		cin.ignore(99999, '\n'); // skips input similar to "7a"
		cout << endl;
	} while (pileSize <= 10); // Will not exit the loop until the pile size is more than 10

	unsigned seed; //random seed generator
	seed = time(0);
	srand(seed);
	a = rand() % (pileSize - 9) + 10; // A random number between 10 and n (which the user inputs)

	// Chooses which opponent goes first
	temp = rand() % 2; // A random number that is 0 or 1
	if (temp == 0)
	{
		cout << "You get to play first. ";
		b = true;
	}
	else if (temp == 1)
	{
		cout << "The computer gets to play first. ";
		b = false;
	}
	else // Alternative in case of if-else if failure
	{
		cout << "This code doesn't work. ";
		system("pause");
		exit(0); // Exits the program
	}
}

void play(double &a, bool &b)
{
	do {

		//system("pause"); // Use this code if you want to take your time in between turns

		//Computer Turn
		if (b == false)
		{
			cout << endl;
			cout << "The pile size is " << a << endl << endl;
			computerTurn(a, b);

		}
		// Player Turn
		else if (b == true)
		{
			cout << endl;
			cout << "The pile size is " << a << endl << endl;
			playerTurn(a, b);
		}
		// Tests for Bugs
		else
		{
			cout << "This code doesn't work." << endl;
		}
		cout << endl;
	} while (a > 0); // Breaks out of the loop when the pile size is zero

	// Victory Conditions
	if (b == false) // After the player has played and the pileSize went to 0
	{
		cout << "You lost!" << endl;
	}
	else if (b == true)
	{
		cout << "You won!" << endl;
	}
	else
	{
		cout << "The program is glitchy." << endl;
	}
}

void computerTurn(double &a, bool &b)
{
	cout << "It is the computer's turn." << endl;
	int temp = a; // a = pilesize. Needed in case of using the pile size again after using arithmetic
	int take = 0; // number to be subtracted from a (pile size)

	//Find "n" for 2^n-1
	int n = 0;
	int n1 = 0, n2 = 0;
	while (a > 1.999999999)
	{
		a = a / 2;
		n1++;
		if (a != static_cast<int>(a))
		{
			a = a - 0.5;
		}
	}
	a = temp + 1;
	while (a > 1.99999999)
	{
		a = a / 2;
		n2++;
		if (a != static_cast<int>(a))
		{
			a = a - 0.5;
		}
	}
	// This helps solve for n if the pile size is already 2^n-1
	if (n1 < n2)
	{
		n = n2;
	}
	else
	{
		n = n1;
	}
	a = temp; // Makes the pile size the same size as it came into the function again

	// Calculations are made to decide how many marbles the computer should take to make the pileSize = 2^n-1
	if ((a - take) != ((pow(2, n) - 1))) // Goes through this if statement if the pile size is not 2^n-1
	{
		while ((a - take) != ((pow(2, n) - 1)))
		{
			take++;
		}
	}
	else if ((a - take) == ((pow(2, n) - 1))) // Goes through this else-if statement if the pile is already 2^n-1
	{
		take = rand() % static_cast<int>(a) / 2; // Computer takes at least half of the marbles
		if (take == 0) // If the computer takes no marbles, then is is automatically forced to take at least one
		{
			take += 1;
		}
	}
	else // Alternative in case of if-else if failure
	{
		cout << "Code doesn't work" << endl;
	}

	// The computer then takes the amount of marbles away from the pile size
	a = a - take;
	n = take;
	cout << "The computer took away " << take << " marbles. ";
	cout << "So the pile size is now: " << a << endl;
	b = true;
}

void playerTurn(double &a, bool &b)
{
	int take = -1; // Makes sure that the do-while loop goes through at least once

	cout << "It is now the player's turn." << endl;
	do {
		cout << "How many marbles would you like to remove? ";
		cin >> take; // Player decides how many marbles to take
		cin.clear(); // skips similar to "a"
		cin.ignore(99999, '\n'); // skips input similar to "7a"
		// If the number of marbles is less than 10 or invalid, then this reiterates
		if (((take > a / 2) || (take < 0)) && (static_cast<int>(a/2) > 0))
		{
			cout << "Invalid number! Please re-enter a value." << endl;
		}
	} while (((take > a / 2) || (take < 0)) && (static_cast<int>(a / 2) > 0));

	// The marbles are then taken away from the pile size
	a = a - take;
	b = false;
}