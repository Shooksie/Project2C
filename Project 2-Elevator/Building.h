#pragma once
#include "Elevator.h"
#include "Person.h"
#include "floor.h"
#include <list>
#include <queue>

class building {
	friend class elevator;
	list<floor> frame;
	queue<int> floorCalls;//Contains all Floor Calls
	queue<int> floorCallsUp;//Conatins all Floor Calls that are Up
	queue<int> floorCallsDown;//Contains All Floors Calls that are going down
	int numberFloors;//Contains the total number of floors
public:
	building();//used for the defult case building
	building(int floorNumber, int);//used for the custom building case
	void setFloor(int floorNumber);//is used to set the floor number and update the floors to work with the new building
	int getCurFloor();//returns where the elevator is currently
	void getElevator();
	void getFloorCalls();
	person generate();
	void moveElevator();

};
