#include "building.h"

void building::setElevator(int number) {
	for (int i = 0; i < number; i++) {
		Elevator elevator;
		elevator.setID(i);
		elevator.connect(frame);
		elevators.push_back(elevator);
	}
}

void building::setFloors(int floor) {
	floorNumbers = floor;
	for (int i = 0; i < floor; i++) {
		frame.push_front(i);
	}
}

void building::moveCalls() {
	list<call>::iterator itr;

	for (itr = floorCall.begin(); itr != floorCall.end(); itr++) {
		int closest = 0; int diffrence = 100;
		for (int i = 0; i < elevators.size(); i++) {
			if (diffrence > (elevators[i].getLevel()- itr->floor)) {
				closest = i;
				diffrence = elevators[i].getLevel();
			}
		}
		elevators[closest].addDestination(itr->floor);
	}
}

void building::moveElevators() {
	list<call>::iterator itr;
	for (int i = 0; i < elevators.size(); i++) {
		for (itr = floorCall.begin(); itr != floorCall.end(); itr++) {
			if (elevators[i].getLevel() == itr->floor) {
				elevators[i].addDestination(itr->goal);
				floorCall.erase(itr);
			}
		}
	}
	for (int z = 0; z < elevators.size(); z++) {
		elevators[z].move();
	}
}