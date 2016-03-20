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
	list<Floor>::iterator itr;
	for (itr = frame.begin(); itr != frame.end(); itr++) {
		if(itr->elevator){
			return itr->floorNo;
		}
	}
	return NULL;
}

void building::generate() {
	person Person;
	peopleInside.push_front(Person);
	floorCalls.push_back(Person.getCurrentFloor());
	if (Person.getDirection()) {
		floorCallsUp.push_back(Person.getCurrentFloor());
		return;
	}
	else {
		floorCallsDown.push_back(Person.getCurrentFloor());
	}
	return;
}

void building::Connect() {

	elvator.ConnectItr(frame);
}

void building::getFloorCalls() {
	int index = 0;
	while (!floorCalls.empty()) {
		cout << index;
		index++;
		int nextFlor = floorCalls.front();
		//check to see in which direction the elevator is going
		if (elvator.getLevel() < nextFlor) {
			//over here the elevator is going up
			list<int>::iterator itr = floorCallsUp.begin();//iterator is used to check all the floor calls that are going up
			while (elvator.getLevel() <= nextFlor) {
				while (itr != floorCallsUp.end()) {
					//while loop to check all floor calls going down
					if (*itr == elvator.getLevel()) {
						//checks to see if the floor call is on the way of the elevator or not
						list<person>::iterator itr2 = peopleInside.begin();
						while (itr2 != peopleInside.end()) {
							if (*itr == itr2->getCurrentFloor() && itr2->getDirection()) {
								elvator.people.push_back(*itr2);
								peopleInside.erase(itr2);
							}
							itr2++;
						}
						list<person>::iterator itr3 = elvator.people.begin();
						while (itr3 != elvator.people.end()) {
							if (elvator.getLevel() == itr3->getDesiredFloor()) {

								elvator.people.erase(itr3);
							}

							itr3++;
						}
					}
					itr++;
				}
				elvator.current_floor++;
			}

		}
		if (elvator.getLevel() > nextFlor) {
			list<int>::iterator itr = floorCallsDown.begin();//iterator is used to check all the floor calls that are going up
			while (elvator.getLevel() >= nextFlor) {
				while (itr != floorCallsDown.end()) {
					//while loop to check all floor calls going down
					if (*itr == elvator.getLevel()) {
						//checks to see if the floor call is on the way of the elevator or not
						list<person>::iterator itr2 = peopleInside.begin();
						while (itr2 != peopleInside.end()) {
							if (*itr == itr2->getCurrentFloor() && !(itr2->getDirection())) {
								elvator.people.push_back(*itr2);
								peopleInside.erase(itr2);
							}
							itr2++;
						}
						list<person>::iterator itr3 = elvator.people.begin();
						while (itr3 != elvator.people.end()) {
							if (elvator.getLevel() == itr3->getDesiredFloor()) {

								elvator.people.erase(itr3);
							}

							itr3++;
						}
					}
					itr++;
				}
				elvator.current_floor--;
			}
		}
		floorCalls.pop_front();
	}
}


void building::simulate() {
	int index = 0;
	while (index < 1000) {
		getFloorCalls();
		generate();
		index++;
	}

}