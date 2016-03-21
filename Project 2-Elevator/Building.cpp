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


int building::getCurFloor() {
	return elvator.getLevel();
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

	elvator.ConnectItr(frame);
}

void building::checkUpcalls(int CurrentFloor){
	//adds all people going up to the elevator
	list<person>::iterator itr2;
	for (itr2 = peopleInside.begin(); itr2 != peopleInside.end(); itr2++) {
		if ((itr2->getCurrentFloor() == CurrentFloor)&& itr2->getDirection()) {
			if (!elvator.isFull()) {
				elvator.addPerson(*itr2);
				peopleInside.erase(itr2);
			}
			else {
				return;
			}

		}
	}
}

void building::checkDwncalls(int currentFloor) {
	list<person>::iterator itr2;
	for (itr2 = peopleInside.begin(); itr2 != peopleInside.end(); itr2++) {
		if ((itr2->getCurrentFloor() == currentFloor) && !itr2->getDirection()) {
			if (!elvator.isFull()) {
				elvator.addPerson(*itr2);
				peopleInside.erase(itr2);
			}
			else {
				return;
			}

		}
	}
}

void building::removeCall(int floorNumber, bool up) {
	list<call>::iterator itr;
	for (itr = floorCalls.begin(); itr != floorCalls.end(); itr++) {
		if ((itr->floorID == floorNumber) && up == itr->up) {
			floorCalls.erase(itr);
		}
	}
}

void building::moveToFloor(call floors) {
	while (elvator.getLevel() != floors.floorID) {
		if (elvator.getLevel() < floors.floorID) {
			while (!elvator.isFull() && !floorCalls.empty()) {
				checkUpcalls(elvator.getLevel());
				elvator.moveUp();
			}
			elvator.moveUp();
		}
		else if (elvator.getLevel() > floors.floorID) {
			{
				while (!elvator.isFull() && !floorCalls.empty()) {
					checkDwncalls(elvator.getLevel());
					elvator.moveDown();
				}
				if (elvator.isFull() && elvator.getLevel() != floors.floorID) {
					while (elvator.getLevel() != floors.floorID) {
						elvator.moveDown();
					}
				}
			}
		}
	}
}

void building::moveNostop(call floors) {
	while (elvator.getLevel() != floors.floorID)
	{
		if (elvator.getLevel() < floors.floorID) {
			elvator.moveUp();
		}
		else if (elvator.getLevel() > floors.floorID) {
			elvator.moveDown();
		}
	}
}

void building::checkCalls() {
	while (!floorCalls.empty()) {
		if (floorCalls.size() == 1) {
			call floors = floorCalls.front();
			floorCalls.pop_front();
			moveNostop(floors);
		}
		else {
			call floors = floorCalls.front();
			floorCalls.pop_front();
			moveToFloor(floors);
		}
	}
	if (floorCalls.empty()) {
		return;
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