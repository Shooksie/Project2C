#include "Person.h"

person::person() {

	current_floor = rand() % 10;
	desired_floor = rand() % 10;
	while (current_floor == desired_floor) {
		desired_floor = rand() % 10;
	}
	personID = 0;
}

int person::getID() {
	return personID;
}

void person::setID(int number) {
	personID = number;
}

int person::getCurrentFloor() {
	return current_floor;
}

int person::getDesiredFloor() {
	return desired_floor;
}

bool person::getDirection() {
	if (current_floor < desired_floor)
		return true;
	else
		return false;
}

