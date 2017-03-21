/*
Created by William Yang
CS-145 Section 004
02/07/16
*/

#include <iostream>
#include <string> // Used for the banner
#include <cstdlib> // Used for the seedGen function
#include <ctime> // Used for the seedGen function
using namespace std;

/*
-----------------------
Global Variables
-----------------------
The"obj" variables are used to place Xs and Os on the 3x3 tic-tac-toe board
The board has 9 spaces to fill in. So "boardCheck" variable is used to check
whether the board is filled or not. If it is filled up, then the game will
result in a draw.
*/

char obj1 = ' ', obj2 = ' ', obj3 = ' ', obj4 = ' ', obj5 = ' ', obj6 = ' ', obj7 = ' ', obj8 = ' ', obj9 = ' ';
int boardCheck = 0;

// Function Prototypes

/*
-----------------------
Random Seed Generator
-----------------------
This functions is used to allow the computer to randomly choose a spot on
the board every time the game is run.
*/

void seedGen();

/*
-----------------------
Instructions
-----------------------
This function is used to output the directions on how to play Tic-Tac-Toe.
*/

void instructions();

/*
-----------------------
Grid Drawer
-----------------------
This function uses the value of "user" to test whether it is the player
or computer's turn.
It also takes in the coordinates the player/computer wants to place
their symbol and checks whether or not that coordinate is available.
The board is then drawn with spots 1-9, saving the spots where the
player/computer placed their symbol.
*/

void drawGrid(bool user, int choice);

/*
-----------------------
Player Options
-----------------------
This function allows the player to choose the coordinate where the player
would like to place a symbol.
It also checks whether or not the coordinate the player chose is a legal
number.
If not, the player's turn will skipped and the player's symbol will not be
placed on the board.
*/

void playerTurn(bool &user);

/*
-----------------------
Computer Options
-----------------------
This function allows the enemy AI to randomly choose the coordinate where
it would like to place its symbol.
*/

void computerTurn(bool &user);

/*
-----------------------
Victory Check
-----------------------
This function checks to see whether the player or computer won, if their
respective symbols were placed in a row.
If the board is filled up with no rows on the board, then the game will
result in a draw.
*/

void victoryCheck(int &check);

/*
-----------------------
Main Function
-----------------------
This function calls all of the other functions needed to play (in order).
The player and computer will keep on playing until one or the either wins,
or until the game reslts in a draw.
*/
int main()
{
	seedGen(); // gets the computer to choose different spots to place its symbol every time the program is run

	bool player = true; // This is used to determine if it is the player's turn or not
	char play = 'Y';
	int count = 1; // this variable counts the number of turns the player has gone through
	int win = 0; // This variable determines whether the player won or not

	instructions(); //Displays the instructions for the game

					/*
					Tests whether the player still wants to play or not
					*/
	cout << "Type 'Y' to continue, anything else to quit: ";
	cin >> play;
	cin.clear(); // Clears the input (if this code was taken out, then the input would be 
	cin.ignore(256, '\n'); // Stored for all functions and the game would not allow user input
	if (play == 'Y' || play == 'y')
	{
		cout << endl;
	}
	else
	{
		exit(0); // Exits the program
	}

	/*
	This loops until the game results in a draw, loss, or victory, but runs at
	least once
	*/
	do {
		if (player == true)
		{
			cout << "Turn: " << count << endl;
			playerTurn(player);
			count++;
		}
		else
		{
			computerTurn(player);
		}
		victoryCheck(win);
	} while (win == 0);
	/*
	Tests whether the game resulted in a win, loss, or draw
	*/
	if (win == 1)
	{
		cout << "You won the game!\n" << endl;
	}
	else if (win == 2)
	{
		cout << "You lost the game.\n" << endl;
	}
	else
	{
		cout << "The game ended in a draw.\n" << endl;
	}
	system("pause");

	return 0;
}

/*
-----------------------
Functions
-----------------------
*/

void seedGen()
{
	unsigned seed; //random seed generator
	seed = time(0);
	srand(seed);
}

void instructions()
{
	// Creates a neat title
	string banner; // Creates a banner to seperate the title from the instructions
	banner.assign(60, '=');
	cout << banner << endl;
	cout << "Let's Play Tic-Tac-Toe!" << endl;
	cout << banner << endl << endl;

	// Gives out written instructions
	cout << "Instructions" << endl;
	cout << " -The goal of the game is to draw a row of three symbols\non the 3x3 game board below in order to win" << endl;
	cout << "-Your symbols is \"X\"" << endl;
	cout << "-The computer's symbol will be \"O\"" << endl;
	cout << "-If no one wins, the game will result in a draw" << endl;
	cout << "-To begin the game, enter a coordinate that corresponds to\nthe following diagram\n" << endl;

	// Draws a blank 3x3 game board
	cout << ":_00_:_01_:_02_:\n\n:_10_:_11_:_12_:\n\n:_20_:_21_:_22_:\n" << endl;
	system("pause");
	cout << endl;
}

void drawGrid(bool user, int choice)
{
	int temp = rand() % 9 + 1; //random number
	bool check = user;
	/*
	Goes through this code on the player's turn to place an 'X', or skip the
	player's turn of there is already a symbol in the selected box
	*/
	if (user == true)
	{
		//Box #1
		if (choice == 00 && obj1 == ' ') // Checks if the spot isn't taken
		{
			obj1 = 'X';
			boardCheck += 1;
		}
		else if (choice == 00 && (obj1 == 'O' || obj1 == 'X')) // If the spot is taken, the player's turn is skipped
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #2
		else if (choice == 01 && obj2 == ' ')
		{
			obj2 = 'X';
			boardCheck += 1;
		}
		else if (choice == 01 && (obj2 == 'O' || obj2 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #3
		else if (choice == 02 && obj3 == ' ')
		{
			obj3 = 'X';
			boardCheck += 1;
		}
		else if (choice == 02 && (obj3 == 'O' || obj3 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #4
		else if (choice == 10 && obj4 == ' ')
		{
			obj4 = 'X';
			boardCheck += 1;
		}
		else if (choice == 10 && (obj4 == 'O' || obj4 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #5
		else if (choice == 11 && obj5 == ' ')
		{
			obj5 = 'X';
			boardCheck += 1;
		}
		else if (choice == 11 && (obj5 == 'O' || obj5 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #6
		else if (choice == 12 && obj6 == ' ')
		{
			obj6 = 'X';
			boardCheck += 1;
		}
		else if (choice == 12 && (obj6 == 'O' || obj6 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #7
		else if (choice == 20 && obj7 == ' ')
		{
			obj7 = 'X';
			boardCheck += 1;
		}
		else if (choice == 20 && (obj7 == 'O' || obj7 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #8
		else if (choice == 21 && obj8 == ' ')
		{
			obj8 = 'X';
			boardCheck += 1;
		}
		else if (choice == 21 && (obj8 == 'O' || obj8 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
		//Box #9
		else if (choice == 22 && obj9 == ' ')
		{
			obj9 = 'X';
			boardCheck += 1;
		}
		else if (choice == 22 && (obj9 == 'O' || obj9 == 'X'))
		{
			cout << "This spot was already chosen! Skipping your turn...\n" << endl;
		}
	}
	/*
	Goes through this code on the computer's turn to place an 'O', or loops
	the computer's actions until an 'O' can be placed in an empty box
	*/
	else if (user == false)
	{
		//Box #1
		if (choice == 1 && obj1 == ' ') // Checks if the spot is taken
		{
			obj1 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 1 && (obj1 == 'O' || obj1 == 'X')) // If taken, the drawGrid function will loop
		{
			drawGrid(check, temp);
			return;
		}
		//Box #2
		else if (choice == 2 && obj2 == ' ')
		{
			obj2 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 2 && (obj2 == 'O' || obj2 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
		//Box #3
		else if (choice == 3 && obj3 == ' ')
		{
			obj3 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 3 && (obj3 == 'O' || obj3 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
		//Box #4
		else if (choice == 4 && obj4 == ' ')
		{
			obj4 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 4 && (obj4 == 'O' || obj4 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
		//Box #5
		else if (choice == 5 && obj5 == ' ')
		{
			obj5 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 5 && (obj5 == 'O' || obj5 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
		//Box #6
		else if (choice == 6 && obj6 == ' ')
		{
			obj6 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 6 && (obj6 == 'O' || obj6 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
		//Box #7
		else if (choice == 7 && obj7 == ' ')
		{
			obj7 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 7 && (obj7 == 'O' || obj7 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
		//Box #8
		else if (choice == 8 && obj8 == ' ')
		{
			obj8 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 8 && (obj8 == 'O' || obj8 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
		//Box #9
		else if (choice == 9 && obj9 == ' ')
		{
			obj9 = 'O';
			boardCheck += 1;
			cout << "The computer chose box " << choice << endl << endl;
		}
		else if (choice == 9 && (obj9 == 'O' || obj9 == 'X'))
		{
			drawGrid(check, temp);
			return;
		}
	}
	//Boxes #1-3
	cout << ": " << obj1 << " : " << obj2 << " : " << obj3 << " :\n" << endl;
	//Boxes #4-6
	cout << ": " << obj4 << " : " << obj5 << " : " << obj6 << " :\n" << endl;
	//Boxes #6-9
	cout << ": " << obj7 << " : " << obj8 << " : " << obj9 << " :\n" << endl;
}

void playerTurn(bool &user)
{
	int temp; // Creates a temporary value for the player's selection of a box
	bool check = user; // This variable is the same value as "user"
	cout << "Choose a box: ";
	cin >> temp;
	cout << endl << endl;
	/*
	If the number the player inputted into the system is a number from 1-9,
	the if statement will run
	*/
	if (temp == 00 || temp ==  01 || temp ==02 || temp == 10 || temp == 11 || temp == 12 || temp == 20 || temp == 21 || temp == 22 )
	{
		drawGrid(check, temp);
		user = false; // "user" is referenced back to the main function as "player". It is now the computer's turn
	}
	// If the number is not 1-9, an error message will be output
	else
	{
		cout << "You have entered an illegal number/character. Skipping your turn...\n" << endl;
		system("pause");
		cout << endl;
		user = false; // "user" is referenced back to the main function as "player". It is now the computer's turn
	}

}

void computerTurn(bool &user)
{
	/*
	This temporary value is used so that the computer can make a random
	selection when choosing a box to put a symbol in.
	*/
	int temp = rand() % 9 + 1;
	bool check = user;
	cout << "The computer is choosing...\n" << endl;
	drawGrid(check, temp);
	user = true; // "user" is referenced back to the main function as "player". It is now the player's turn
}

void victoryCheck(int &check)
{
	// Tests for player victory
	if (obj1 == 'X' && obj2 == 'X' && obj3 == 'X')
	{
		check = 1; // "check" is referenced back to "win" in the main function
	}
	else if (obj4 == 'X' && obj5 == 'X' && obj6 == 'X')
	{
		check = 1;
	}
	else if (obj7 == 'X' && obj8 == 'X' && obj9 == 'X')
	{
		check = 1;
	}
	else if (obj1 == 'X' && obj4 == 'X' && obj7 == 'X')
	{
		check = 1;
	}
	else if (obj2 == 'X' && obj5 == 'X' && obj8 == 'X')
	{
		check = 1;
	}
	else if (obj3 == 'X' && obj6 == 'X' && obj9 == 'X')
	{
		check = 1;
	}
	else if (obj1 == 'X' && obj5 == 'X' && obj9 == 'X')
	{
		check = 1;
	}
	else if (obj3 == 'X' && obj5 == 'X' && obj7 == 'X')
	{
		check = 1;
	}
	// Tests for computer victory
	else if (obj1 == 'O' && obj2 == 'O' && obj3 == 'O')
	{
		check = 2;
	}
	else if (obj4 == 'O' && obj5 == 'O' && obj6 == 'O')
	{
		check = 2;
	}
	else if (obj7 == 'O' && obj8 == 'O' && obj9 == 'O')
	{
		check = 2;
	}
	else if (obj1 == 'O' && obj4 == 'O' && obj7 == 'O')
	{
		check = 2;
	}
	else if (obj2 == 'O' && obj5 == 'O' && obj8 == 'O')
	{
		check = 2;
	}
	else if (obj3 == 'O' && obj6 == 'O' && obj9 == 'O')
	{
		check = 2;
	}
	else if (obj1 == 'O' && obj5 == 'O' && obj9 == 'O')
	{
		check = 2;
	}
	else if (obj3 == 'O' && obj5 == 'O' && obj7 == 'O')
	{
		check = 2;
	}
	// Tests for a draw
	else if (boardCheck == 9)
	{
		check = 3;
	}
}
