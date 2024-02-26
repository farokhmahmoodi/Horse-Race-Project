#include "Horse.h"

Horse::Horse()
{
	name = "", rider = "";
	distanceTraveled = 0, racesWon = 0;
	unsigned seed;
	seed = time(0);
	srand(seed);
	maxRunningDistPerSecond = rand() % 100 + 1;
}

Horse::Horse(string horseName, string riderName)
{
	name = horseName, rider = riderName;
	distanceTraveled = 0, racesWon = 0;
	unsigned seed;
	seed = time(0);
	srand(seed);
	maxRunningDistPerSecond = rand() % 100 + 1;
}

void Horse::runASecond()
{
	unsigned seed;
	seed = time(0);
	srand(seed);
	distanceTraveled += rand() % maxRunningDistPerSecond;
}

void Horse::sendToGate()
{
	distanceTraveled = 0;
}

void Horse::displayHorse(int goalLength)
{
	cout << "|";
	for (int i = 0; i <= distanceTraveled; i++)
	{
		if (i == distanceTraveled)
			cout << ">";
		else
			cout << "-";
	}
	cout << setw(goalLength - distanceTraveled) << "|" << endl;
}
