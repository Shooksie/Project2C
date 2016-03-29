#include "building.h"


void Elevator::addDestination(int floor) {
	list<int>::iterator itr;
	if (destinations.empty()) {
		destinations.push_back(floor);
		return;
	}
	for (itr = destinations.begin(); itr != destinations.end(); itr++) {
		if (floor < *itr) {
			destinations.insert(itr, floor);
			return;
		}
	}
	destinations.push_back(floor);
	return;
}

void Elevator::checkDestinations() {
	list<int>::iterator itr;
	for (itr = destinations.begin(); itr != destinations.end(); itr++) {
		if (*itr == current) {
			destinations.remove(*itr);
		}
	}
}

void Elevator::move() {
	if (!moving && up) {
		moveUp();
		return;
	}
	if (!moving && !up) {
		moveDown();
		return;
	}
	else {
		return;
	}
}