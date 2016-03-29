#pragma once
#include <vector>
#include "Elevator.h"

using namespace std;

class Elevator {
public:
	void connect(list<int> list) { elevator = list.begin(); };
	void addDestination(int floor);
	void moveUp() { ++elevator; current= *elevator; checkDestinations(); };
	void moveDown() { --elevator; current = *elevator; checkDestinations(); };
	void checkDestinations();
	void move();
	void setID(int id) { ID = id; };
	int getLevel() { return current; }
private:
	int ID, current, direction;
	list<int>::iterator elevator;
	list<int> destinations;
	building* building;
};

class building {
	friend class elevator;
public:
	void generate();
	void setElevator(int number = 1);
	void setFloors(int floors=10);
	void moveCalls();
	void moveElevators();
private:
	struct call { int floor, goal; bool up; };
	list<call> floorCall;
	list<int> frame;
	vector<Elevator> elevators;
	int elevatorNumber;
	int floorNumbers;
	
};
