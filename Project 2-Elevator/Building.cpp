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
			floor temp;
			temp.floorNo = i;
			frame.push_back(temp);
		}
	}
	return;
}


int building::getCurFloor() {
	list<floor>::iterator itr;
	for (itr = frame.begin(); itr != frame.end(); itr++) {
		if(itr->elevator){
			return itr->floorNo;
		}
	}
}
