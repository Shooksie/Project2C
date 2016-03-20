#include <iostream>
#include <cstdlib>
#include "Person.h"
#include "Building.h"
#include "floor.h"

using namespace std;

class Elevator {
	friend class floor;
private:
	friend class Building;
	int numPeople, level;
	list<person> people;
	list<floor>::iterator current_floor;
	
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
};
