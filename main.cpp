//////////////////////////
// Jalen Robinson-McClure
// June 29th, 2017
// CS 172
// Final Project
///////////////////////////

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "dice.h"

using namespace std;

int main()
{
	// pot to keep track of money
	int originalPot = 50;
	int currentPot;
	int leave;
	// Welcome and instructions on how to play
	int instructions;
	cout << "Hello player and welcome to the dice rolling game called Craps!" << endl;
	cout << "Would you like some instructions on how to play (Enter 1 if you want intstructions. Enter any other number if not)" << endl;
	cin >> instructions;
	cout << endl;
	if (instructions == 1)
	{
		cout << "Here is a quick rundown of the game: " << endl;
		cout << "You roll two six sided dice. what happens next depends on what you roll;" << endl;
		cout << "If your roll a 7 or 11 you win the round automatically, but if you roll a 2, 3, or 12 you lose the round automatically. " << endl;
		cout << "If you do not roll any of the numbers above you, continue rolling until " << endl;
		cout << "you roll the same number you rolled or one of the number above." << endl;
		cout << "In this case your winning depends on how many times you have rolled during that round." << endl;
		cout << "Ok, we are ready to play";
		cout << endl;
		cout << endl;
	}

	// Turns on Game
	int Continue;
	cout << "Are you ready? " << endl;
	cout << "(Enter 1 to play, enter any other key to end.) " << endl;
	cin >> Continue;

	// while loop that contains game
	do
	{

		//displays the money you have and what you have won 
		cout << "You have $" << originalPot << endl;
		cout << endl;


		//vector for rolls 
		vector<int> myRolls;

		srand(time(static_cast<unsigned int>(0)));

		// dice obect rolling 
		Dice roll;
		for (int i = 0; i < 1; i++)
		{

			myRolls.push_back(roll.getRoll(2));

			cout << "The total of your roll is: " << myRolls[i] << endl;
			cout << endl;

		}
		cout << endl;

		cout << myRolls[0] << endl;

		//if Else statement that will be used depending on your first roll;

			// this adds from your pot by 5 because of your roll 
		if (myRolls[0] == 7)
		{
			cout << "You win the round!" << endl;
			currentPot = originalPot += 5;

			cout << "You have won $" << 5 << endl;
			cout << "You now have $" << currentPot << " in your pot" << endl;
		}

		else if (myRolls[0] == 11)
		{
			cout << "You win the round!" << endl;
			currentPot = originalPot += 5;

			cout << "You have won $" << 5 << endl;
			cout << "You now have $" << currentPot << " in your pot" << endl;
		}

		// this subtracts from your pot by 5 because of your roll 
		else if (myRolls[0] == 2)
		{
			cout << "You lose the round!" << endl;
			currentPot = originalPot - 5;
			cout << "You have lost $" << 5 << endl;
			cout << "You now have $" << currentPot << " in your pot" << endl;
		}

		else if (myRolls[0] == 3)
		{
			cout << "You lose the round!" << endl;
			currentPot = originalPot -= 10;

			cout << "You have lost $" << 10 << endl;
			cout << "You now have $" << currentPot << " in your pot" << endl;
		}

		else if (myRolls[0] == 12)
		{
			cout << "You lose the round!" << endl;
			currentPot = originalPot -= 10;

			cout << "You have lost $" << 10 << endl;
			cout << "You now have $" << currentPot << " in your pot" << endl;
		}
		// this adds to your pot the number of times you have rolled in this round
		
		else
		{
			// do while loop tha ends on user or on roll 
			cout << "Do you want to leave with your winnings(Enter 1 to leave. Enter any other number to continue rolling)" << endl;
			cin >> leave;

			do
			{
				cout << "You get to roll again" << endl;
				// continues rolling dice after 1st roll
				for (int i = 0; i < 1; i++)
				{

					myRolls.push_back(roll.getRoll(2));

					cout << "The total of your roll is: " << myRolls[i] << endl;
					cout << endl;

					cout << "Your current rolls are " << endl;
					for (int i = 0; i < myRolls.size(); i++)
					{
						cout << myRolls[i] << " ";
					}
					cout << endl;

					cout << "You have " << myRolls.size() << " sucessful rolls." << endl;
					cout << endl;

				}
				cout << "Do you want to leave with your winnings(Enter 1 to leave. Enter any other number to continue rolling)" << endl;
				cin >> leave;
				cout << endl;

				// do while loop that ends when player quits or when a roll that ends the round occurs
			} while (leave != 1 /*|| myRolls.back != 2 || *myRolls.back != 3 || *myRolls.back != 7 || *myRolls.back != 11 || *myRolls.back != 12 /*|| myRolls.back != myRolls[0]*/);

			currentPot = (originalPot += myRolls.size() * 2);
			cout << "You have won $" << (myRolls.size() * 2) << endl;
			cout << "You now have $" << currentPot << " in your pot" << endl;
		}


		// clears the vector so that the next round starts with no old rolls
		myRolls.clear();
		// used to continue or end the game
		cout << "(Enter 1 to continue play, enter any other key to end.) " << endl;
		cin >> Continue;
		cout << endl;

	} while (Continue == 1);
	// displays if the user runs out of money. 
	cout << endl;
	if (currentPot <= 0)
	{
		cout << "You have ran out of money! Game Over!" << endl;
	}

	else
	{
		// File I/O to save results of the game
		string fileName;
		int save;
		cout << "Would you like to save your progress. (Enter 1 to save. Enter any other number to not)" << endl;
		cin >> save;

		if (save == 1)
		{
			ofstream output;
			output.open("scores.txt");

			cout << "Enter a file name you would like to save under" << endl;
			cin >> fileName;
			cout << endl;

			output << fileName << " " << currentPot;
			cout << fileName << " " << currentPot << endl;

			output.close();

			cout << "Saved" << endl;
		}
	}

	// end of game credits
	cout << endl;
	cout << "Thanks For Playing " << endl;
	system("Pause");
	return 0;
}