/*In this assignment, you will be performing a horse racing simulation. To start with, you will write a Horse class.
The Horse class should have the following member variables:

private name: A string holding the horses name.
private rider: A string holding the rider’s name.
private maxRunningDistPerSecond: An int that holds the maximum distance the horse could run in one second.
private distanceTraveled: How far the horse has gone already.
private racesWon: An int that determines how much races this horse and rider have won

In addition, the class should have the following constructors and member functions:

Constructor: This constructor should accept the horse’s name and rider as arguments.
It should initialize each horse to a random maxRunningDistPerSecond(1-100). DistanceTraveled should be set to 0.

Accessors and mutators: Appropriate accessor and mutator functions should be used as required by the following methods:

runASecond: A method that adds to distanceTraveled an amount from 0-maxRunningDistPerSecond.
This is the method that moves this horse along.

sendToGate: Reset the horse to the start of a race by setting distanceTraveled to 0.

displayHorse(int goalLength): This method should attempt to draw where the horse is along its race.
Should try to graphically display in ascii how far the horse has gone on its way to goalLength.
This should be scaled so it doesn’t overrun the screen.

Some examples:

|---------------> | Pharaoh, ridden by Mark
|--------------------> | Secretariat, ridden by George
|------------> | Calamity Jane, ridden by Mary

So if a horse has “distanceTraveled” of 50 and the goalLength passed is 100, then the > for the horse
should be halfway towards the “goal”. If it is called where the distanceTraveled is greater than the
goalLength (indicating it has finished), this output would be:

|--------------------------------|>John indicating the horse has finished the race.

Demonstrate this class in a program by first prompting the user for the number of horses in the race.
Then create an array of pointers to Horse objects, filling it up as appropriate (an array of pointers,
so you can use the new operator to call the constructors of each one). Then prompt the user for a distance to race.
Since horses can travel in any time interval a max of 100, a good distance of 1000 could be appropriate to test.

In a loop, start the race. In this loop, for each interval of the loop, execute runASecond for each horse.
Then output all the horses toString to show the user the current race status. Then prompt the user if they want to
continue the race. Keep doing this until one of the horses has “won” the race. If there is a tie, break the tie by
distanceTraveled. If there is a tie in distanceTraveled, randomly pick a winner.

Your program should allow multiple races with the same horses. At the end of each race, display the winner and
statistics on how many each horse has won or lost.

You can include extra methods or attributes if you want, but make sure to only make members public if it is absolutely
necessary.

This project will require 3 files.

main.cpp, the main driver program. Horse.h: The header file for the Horse class Horse.cpp: The file defining the
Horse methods Note: If you are using an online compiler like www.cpp.sh (Links to an external site.)Links to an external
site., then you may put the contents of Horse.h at the beginning of the program, followed by the contents of Horse.cpp,
followed by the contents of main.cpp. This way, all code will be in one place.

Your output should look very similar to the following:

How many horses are in the race: 3
Please give me the name of horse 1: Pharaoh
Please give me the rider of rider 1: Mark
Please give me the name of horse 2: Secretariat
Please give me the name of rider 2: George
Please give me the name of horse 3: Calamity Jane
Please give me the name of rider 3: Mary
Please enter the distance of the race: 500

The start!
|>                                           |  Pharaoh, ridden by Mark
|>                                           |  Secretariat, ridden by George
|>                                           |  Calamity Jane, ridden by Mary

Are you ready for the next second(y/n)?:y
|              >                             |  Pharaoh, ridden by Mark
|          >                                 |  Secretariat, ridden by George
|   >                                        |  Calamity Jane, ridden by Mary

Are you ready for the next second(y/n)?:y
|                                >           |  Pharaoh, ridden by Mark
|                     >                      |  Secretariat, ridden by George
|            >                               |  Calamity Jane, ridden by Mary

and so on, until a winner is found, which would end with some output like this:

|                                            |>  Pharaoh, ridden by Mark
|                                 >          |  Secretariat, ridden by George
|                    >                       |  Calamity Jane, ridden by Mary

Pharaoh has won 1/1 races. Secretariat has won 0/1 races. Calamity Jane has won 0/1 races.
Do you wish to continue(y/n)?: Error conditions:

You must check for any invalid entries. For example, when asking for the number of horses, do not accept a
negative answer and re-prompt until an appropriate result is given. Only accept race distances of 100 or greater,
again re-prompting if necessary.*/

#include "Horse.h";

int main()
{
    int numOfHorses, raceDistance;
    string horseName, riderName;

    do
    {
        cout << "How many horses are in the race(greater than or equal to 0): ";
        cin >> numOfHorses;
        if (numOfHorses < 0)
            cout << "Invalid input for number of horses." << endl;
    } while (numOfHorses < 0);
    if (numOfHorses > 0)
    {
        Horse* arr = new Horse[numOfHorses];
        for (int i = 0; i < numOfHorses; i++)
        {
            cout << "Please give me the name of horse " << i + 1 << ": ";
            getline(cin,horseName);
            arr[i].setName(horseName);
            cout << "Please give me the rider of rider " << i + 1 << ": ";
            getline(cin, riderName);
            arr[i].setRider(riderName);
        }
        do
        {
            cout << "Please enter the distance of the race(greater than or equal to 100): ";
            cin >> raceDistance;
            if (raceDistance < 100)
                cout << "Invalid input for race distance." << endl;
        } while (raceDistance < 100);
    }

    return 0;
}
