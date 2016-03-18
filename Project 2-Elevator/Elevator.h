#include <iostream>
#include <cstdlib>
#include "Person.h"
#include "Building.h"

using namespace std;

class Elevator {
	friend class Building;
private:
	int numPeople, level;
	list<Person> people;
	list<Floor>:: iterator current_floor;
	
public:
	Elevator();
	void moveUp();
	void moveDown();
	int getLevel();
	int getNumPeople();
	bool isUp();
	bool hasRequests();
	bool isDown();
	void checkPeople();
	void addPerson(Person newP);
};
