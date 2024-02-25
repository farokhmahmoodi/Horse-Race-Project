#ifndef HORSE_H
#define HORSE_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Horse
{

private:
	string name, rider;
	int maxRunningDistPerSecond, distanceTraveled,
		racesWon;

public:
	Horse();
	Horse(string, string);
	void runASecond();
	void sendToGate();
	void displayHorse(int);
};
#endif
