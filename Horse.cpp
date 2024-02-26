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
	if (distanceTraveled < goalLength)
	{
		cout << setw(distanceTraveled) << ">";
		if (distanceTraveled == 0)
		{
			cout << setw(goalLength - distanceTraveled) << "|" << setw(10)
				<< name << ", ridden by " << rider << endl;
		}
		else if (distanceTraveled > 0)
		{
			cout << setw((goalLength - distanceTraveled) + 1) << "|" << setw(10)
				<< name << ", ridden by " << rider << endl;
		}
	}
	else if (distanceTraveled >= goalLength)
	{
		cout << setw(goalLength + 1) << "|" << setw(1) << ">" << setw(9)
			<< name << ", ridden by " << rider << endl;
	}
}
