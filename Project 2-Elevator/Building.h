#pragma once
#include "Elevator.h"
#include "Person.h"
#include "floor.h"
#include <list>
#include <queue>

class building {
	friend class elevate;
	list<person> peopleInside;
	list<Floor> frame;
	struct call {
		int floorID;
		bool up = true;
	};
	list<call> floorCalls;//Contains all Floor Calls
	int numberFloors;//Contains the total number of floors
public:
	void simulate();
	void Connect();
	building();//used for the defult case building
	building(int floorNumber);//used for the custom building case
	void setFloor(int floorNumber);//is used to set the floor number and update the floors to work with the new building
	void generate();
	void removeCall(int floorNumber, bool up);
	void checkCalls();
	elevate elvator;
	void generate(int traffic, int floors);
};
