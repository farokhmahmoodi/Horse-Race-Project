#include "Horse.h"

Horse::Horse()
{
	name = "", rider = "";
	distanceTraveled = 0, racesWon = 0;
	while (cout << "Enter an integer for seed value to calculate max running distance per second" //for randomization
		<< " for a horse:" && !(cin >> seed)) {
		cin.clear(); //clear bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
		cout << "Invalid input for seed value." << endl;
	}
	srand(seed);
	maxRunningDistPerSecond = rand() % 100 + 1;
	cin.ignore();
}

Horse::Horse(string horseName, string riderName)
{
	name = horseName, rider = riderName;
	distanceTraveled = 0, racesWon = 0;
	while (cout << "Enter an integer for seed value to calculate max running distance per second" //for randomization
		<< " for a horse:" && !(cin >> seed)) {
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		cout << "Invalid input for seed value." << endl;
	}
	srand(seed);
	maxRunningDistPerSecond = rand() % 100 + 1;
	cin.ignore();
}

void Horse::runASecond()
{
	while (cout << "Enter an integer for seed value to calculate distance traveled" //for randomization
		<< " for horse " << name << ", ridden by " << rider <<":" && !(cin >> seed)) {
		cin.clear(); 
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
		cout << "Invalid input for seed value." << endl;
	}
	srand(seed);
	distanceTraveled += rand() % maxRunningDistPerSecond;
	cin.ignore();
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
			cout << setw(goalLength - distanceTraveled) << "|" << setw(15)
				<< name << ", ridden by " << rider << endl;
		}
		else if (distanceTraveled > 0)
		{
			cout << setw((goalLength - distanceTraveled) + 1) << "|" << setw(15)
				<< name << ", ridden by " << rider << endl;
		}
	}
	else if (distanceTraveled >= goalLength)
	{
		cout << setw(goalLength + 1) << "|" << setw(1) << ">" << setw(15)
			<< name << ", ridden by " << rider << endl;
	}
}
