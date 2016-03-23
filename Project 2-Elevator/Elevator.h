#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include "Person.h"
#include "Building.h"

using namespace std;

class Elevator {
private:
	friend class Building;
	int numPeople, level;
	list<Person> people;
	list<Floor>:: iterator current_floor;
	
public:
	list<person> people;
	list<Floor>::iterator current_floor;
	list<int> destinations;
	void move();
	void moveUp();
	void moveDown();
	int getLevel();
	int getNumPeople();
	bool hasRequests(list<int> List);
	void checkPeople();
	void ConnectItr(list<Floor> List);
	bool isFull();
	void addPerson(person newP);
	void addDestination(int dest);
};
