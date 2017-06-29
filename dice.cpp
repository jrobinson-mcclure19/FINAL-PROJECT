#include "dice.h"

Dice::~Dice()
{

}
int Dice::getRoll(int times)
{
	{
		int roll = 0;
		for (size_t i = 0; i < times; i++)
		{
			roll += rand() % sides + 1;
		}

		return roll;

	}

}