
#include "Building.h"

using namespace std;

building::building() {
	setFloor(10);
}
void building::setFloor(int floorNumber) {
	frame.clear();
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

person building::generate() {
	person Person;
	return Person;
}

void building::Connect() {

	elvator.ConnectItr(frame);
}