#pragma once
#pragma warning disable 4430, 3646
#include "Elevator.h"
#include "Person.h"
#include "floor.h"
#include <list>
#include <queue>

class building {
	list<Floor> frame;
	queue<int> floorCalls;//Contains all Floor Calls
	queue<int> floorCallsUp;//Conatins all Floor Calls that are Up
	queue<int> floorCallsDown;//Contains All Floors Calls that are going down
	int numberFloors;//Contains the total number of floors
public:
	void Connect();
	building();//used for the defult case building
	building(int floorNumber);//used for the custom building case
	void setFloor(int floorNumber);//is used to set the floor number and update the floors to work with the new building
	int getCurFloor();//returns where the elevator is currently
	void getElevator();
	void getFloorCalls();
	person generate();
	void moveElevator();
	elevate elvator;
};
