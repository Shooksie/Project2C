#pragma once
#include "Elevator.h"
#include "Person.h"
#include "floor.h"
#include <list>
#include <queue>

class building {
	friend class elevator;
	struct floor {
		int floorNo;
		bool elevator=false;
	};
	list<floor> frame;
	queue<int> floorCalls;//Contains all Floor Calls
	queue<int> floorCallsUp;//Conatins all Floor Calls that are Up
	queue<int> floorCallsDown;//Contains All Floors Calls that are going down
	int numberFloors;
public:
	building();
	void setFloor(int floorNumber);
	int getCurFloor();
	void getElevator();
	void getFloorCalls();
	void generate();

};
