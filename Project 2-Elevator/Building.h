#pragma once
#include "Elevator.h"
#include "Person.h"
#include "floor.h"
#include <list>
#include <queue>

using namespace std;

class building {
	friend class elevator;
	struct Floor {
		int floorNo;
		bool elevator=false;
	};
	
	list<Floor> frame;
	queue<int> floorCalls;//Contains all Floor Calls
	int numberFloors;
public:
	building();
	building(int number);
	void setFloor(int floorNumber);
	int getCurFloor();
	void getElevator();
	void getFloorCalls();
	void generate();

};
