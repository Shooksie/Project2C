#pragma once
#pragma warning disable 4430, 3646
#include <iostream>
#include <cstdlib>
#include <list>
#include "Person.h"
#include "Building.h"
#include "floor.h"

using namespace std;

class elevate {
private:
	int numPeople = 0;
	int level = 0;
	
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
};
