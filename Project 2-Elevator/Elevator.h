#pragma once
#include <iostream>
#include <cstdlib>
#include <list>
#include "Person.h"
#include "floor.h"

using namespace std;

class elevate {
private:
	int numPeople = 0;
	int level = 0;
	bool Up, Down;
	
public:
	list<person> people;
	list<Floor>::iterator current_floor;
	void moveUp();
	void moveDown();
	int getLevel();
	int getNumPeople();
	bool isUp();
	bool hasRequests();
	bool isDown();
	void checkPeople();
	void ConnectItr(list<Floor> List);
	bool isFull();
	void addPerson(person newP);
};
