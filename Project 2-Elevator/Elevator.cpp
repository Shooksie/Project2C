#include "Elevator.h"


using namespace std;

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
bool elevate::isUp(list<int> List) {
	if (hasRequests(List) == false)
		return false;
	list<int>::iterator itr = List.begin();
	Up = (*itr > level);
	return Up;
}
bool elevate::hasRequests(list<int> List) {
	return(!List.empty());
}
bool elevate::isDown(list<int> List) {
	Down = !isUp(List);
	return Down;
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
		// add destination
		if (destinations.empty())
			destinations.push_back(newP.getDesiredFloor());
		return;
		list<int>::iterator itr;
		for (itr = destinations.begin(); itr != destinations.end(); ++itr) {
			if (*itr == newP.getDesiredFloor()) // destination is already in list
				return;
			destinations.push_back(newP.getDesiredFloor());
		}
	}
}