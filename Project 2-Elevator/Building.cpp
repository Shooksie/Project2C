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
	person Person(numberFloors);
	peopleInside.push_front(Person);
	call person;
	person.floorID = Person.getCurrentFloor();
	person.up = Person.getDirection();
	floorCalls.push_back(person);
	if (Person.getDirection()) {
		floorCallsUp.push_back(Person.getCurrentFloor());
		return;
	}
	else {
		floorCallsDown.push_back(Person.getCurrentFloor());
	}
	return;
}

void building::generate(int traffic, int floors) {
	switch (traffic) {

	case 1: if (true) {
		if (floors <= 10) {
			bool TrueFalse = ((rand() % 100) < 25);
			if (TrueFalse) {
				generate();
			}
		}
		else if (floors <= 50) {
			bool TrueFalse = ((rand() % 200) < 50);
			if (TrueFalse) {
				generate();
			}

		}
		else if (floors <= 100) {
			bool TrueFalse = ((rand() % 1000) < 250);
			if (TrueFalse) {
				generate();
			}
		}
	}
			break;
	case 2:if (true) {
		if (floors <= 10) {
			bool TrueFalse = ((rand() % 100) < 50);
			if (TrueFalse) {
				generate();
			}
		}
		else if (floors <= 50) {
			bool TrueFalse = ((rand() % 200) < 100);
			if (TrueFalse) {
				generate();
			}

		}
		else if (floors <= 100) {
			bool TrueFalse = ((rand() % 1000) < 500);
			if (TrueFalse) {
				generate();
			}
		}
	}
		   break;
	case 3:if (true) {
		if (floors <= 10) {
			bool TrueFalse = ((rand() % 100) < 75);
			if (TrueFalse) {
				generate();
			}
		}
		else if (floors <= 50) {
			bool TrueFalse = ((rand() % 200) < 150);
			if (TrueFalse) {
				generate();
			}

		}
		else if (floors <= 100) {
			bool TrueFalse = ((rand() % 1000) < 750);
			if (TrueFalse) {
				generate();
			}
		}
	}
		   break;
	case 4:
		cout << "Invalid Number" << endl;
	}
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

void building::checkCalls() {
	while (!floorCalls.empty()) {
		if (floorCalls.size() == 1) {
			call floors = floorCalls.front();
			floorCalls.pop_front();
			while (elvator.getLevel() != floors.floorID)
			{
				if (elvator.getLevel() < floors.floorID) {
					elvator.moveUp();
				}
				else if(elvator.getLevel() > floors.floorID){
					elvator.moveDown();
				}
			}
		}
		else {
			call floors = floorCalls.front();
			floorCalls.pop_front();
			while (elvator.getLevel() != floors.floorID) {
				if (elvator.getLevel() < floors.floorID) {
					while (!elvator.isFull() && !floorCalls.empty()) {
						checkUpcalls(elvator.getLevel());
						elvator.moveUp();
					}
					elvator.moveUp();
				}
				else {
					while (!elvator.isFull() && !floorCalls.empty()) {
						checkDwncalls(elvator.getLevel());
						elvator.moveDown();
					}
					elvator.moveDown();
				}
			}
		}
	}
}
/*
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

*/
void building::simulate() {
	int index = 0;
	while (index < 1000) {
		checkCalls();
		generate();
		index++;
	}

}