#include "Elevator.h"


using namespace std;

void elevate::move() {
	while (!destinations.empty()) {
		if (level < destinations.front())
			moveUp();
		if (level > destinations.front())
			moveDown();
	}
}

void elevate::moveUp() {
	++current_floor;
	level++;
	list<int>::iterator itr;
	for (itr = destinations.begin(); itr != destinations.end(); ++itr) {
		if (*itr == level)
			checkPeople();
	}
}
void elevate::moveDown() {
	--current_floor;
	level--;
	list<int>::iterator itr;
	for (itr = destinations.begin(); itr != destinations.end(); ++itr) {
		if (*itr == level)
			checkPeople();
	}
}
int elevate::getLevel() {
	return level;
}
int elevate::getNumPeople() {
	return numPeople;
}

bool elevate::hasRequests(list<int> List) {
	return(!List.empty());
}

void elevate::checkPeople() {
	// person leaves elevator
	list<person>::iterator itr1;
	for (itr1 = people.begin(); itr1 != people.end(); ++itr1) {
		if (itr1->getDesiredFloor() == level) {
			people.erase(itr1);
			numPeople--;
		}
	}
	// remove destination
	list<int>::iterator itr2;
	for (itr2 = destinations.begin(); itr2 != destinations.end(); ++itr2) {
		if (*itr2 == level)
			destinations.erase(itr2);
	}
}
void elevate::ConnectItr(list<Floor> List) {
	current_floor = List.begin();
}

bool elevate::isFull() {
	return (numPeople == 10);
}

void elevate::addPerson(person newP) {
	if (!isFull()) {
		// add person
		people.push_back(newP);
		numPeople++;
		addDestination(newP.getDesiredFloor());
		return;
	}
}

void elevate::addDestination(int dest) {
	if (destinations.empty()) {
		destinations.push_back(dest);
		return;
	}
	list<int>::iterator itr;
	for (itr = destinations.begin(); itr != destinations.end(); ++itr) {
		if (*itr == dest)
			return;
	}
	for (itr = destinations.end(); itr != destinations.begin(); --itr) {
		if (*itr < dest) {
			itr++;
			destinations.insert(itr, dest);
			return;
		}
	}
}
