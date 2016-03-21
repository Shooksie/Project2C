#pragma once
#include "Elevator.h"
#include "Person.h"
#include "floor.h"
#include <list>
#include <queue>

class building {
	list<person> peopleInside;
	list<Floor> frame;
	struct call {
		int floorID;
		bool up = true;
	};
	list<call> floorCalls;//Contains all Floor Calls
	list<int> floorCallsUp;//Conatins all Floor Calls that are Up
	list<int> floorCallsDown;//Contains All Floors Calls that are going down
	int numberFloors;//Contains the total number of floors
public:
	void simulate();
	void Connect();
	building();//used for the defult case building
	building(int floorNumber);//used for the custom building case
	void setFloor(int floorNumber);//is used to set the floor number and update the floors to work with the new building
	int getCurFloor();//returns where the elevator is currently
	void getFloorCalls();
	void generate();
	void generate(int traffic, int floors);
	void checkUpcalls(int CurrentFloor);
	void checkDwncalls(int currentFloor);
	void removeCall(int floorNumber, bool up);
	void checkCalls();
	elevate elvator;
};
