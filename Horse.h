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
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setRider(string n)
	{
		rider = n;
	}
	string getRider()
	{
		return rider;
	}
	void increaseRacesWon()
	{
		racesWon++;
	}
	int getRacesWon()
	{
		return racesWon;
	}
	int getDistanceTraveled()
	{
		return distanceTraveled;
	}
	void runASecond();
	void sendToGate();
	void displayHorse(int);
};
#endif
