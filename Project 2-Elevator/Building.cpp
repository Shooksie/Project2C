#include "Building.h"

using namespace std;

building::building() {
	setFloor(10);
}

building::building(int floorNumber) {
	setFloor(floorNumber);

}

void building::setFloor(int floorNumber) {
	frame.clear();//clearscurrent frame
	if (floorNumber < 0) {
		return;
	}
	else {
		numberFloors = floorNumber;
		for (int i = 0; i < floorNumber; i++)
		{
			Floor temp;
			temp.floorNo = i;
			frame.push_back(temp);
		}
	}
	return;
}

void building::generate() {
	person Person;
	peopleInside.push_front(Person);
	call person;
	person.floorID = Person.getCurrentFloor();
	person.up = Person.getDirection();
	floorCalls.push_back(person);
	return;
}

void building::Connect() {

	elvator.current_floor = frame.begin();
}


void building::removeCall(int floorNumber, bool up) {
	list<call>::iterator itr;
	for (itr = floorCalls.begin(); itr != floorCalls.end(); itr++) {
		if ((itr->floorID == floorNumber) && up == itr->up) {
			floorCalls.erase(itr);
		}
	}
}



void building::simulate(){
	int index = 0;
	while (index < 10) {
		checkCalls();
		generate();
		index++;
	}

}


void building::checkCalls() {
	while (!floorCalls.empty()) {
		call floors = floorCalls.front();
		floorCalls.pop_front();
		elvator.addDestination(floors.floorID);
		moveCalls();
		elvator.move();
		}
	if (floorCalls.empty()) {
		return;
	}
}


void building::moveCalls() {
	if (!floorCalls.empty()) {
		int destination = elvator.destinations.front();
		elvator.getLevel();
		list<call>::iterator itr;
		for (itr = floorCalls.begin(); itr != floorCalls.end(); itr++) {
			if (destination > elvator.getLevel()) {
				if (itr->floorID < destination && itr->up && itr->floorID >= elvator.getLevel()) {
					elvator.addDestination(itr->floorID);
					floorCalls.erase(itr);
				}
			}
			if (destination < elvator.getLevel()) {
				if (itr->floorID > destination && !itr->up && itr->floorID <= elvator.getLevel()) {
					elvator.addDestination(itr->floorID);
					floorCalls.erase(itr);
				}
			}
		}
	}
	return;
}