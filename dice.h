#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef DICE_H
#define DICE_H

// class for the dice
class Dice
{

private:

	int sides;
public:
	// creates 6 sided dice
	Dice(int sides = 6)
	{
		this->sides = sides;
	}
	// deconstructor
	~Dice();
	// frunction that rolls the dice
	int getRoll(int times);

};

#endif // !DICE_H
