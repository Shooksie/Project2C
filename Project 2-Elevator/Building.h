#include "Elevator.h"
#include "Person.h"
#include <list>
#include <queue>
#include "Resources\Random.h"

class building {
	friend class elevator;
	struct floor {
		int floorNo;
		bool elevator=false;
	};
	list<floor> frame;
	queue<person> floorCalls;//Contains all Floor Calls
	queue<person> floorCallsUp;//Conatins all Floor Calls that are Up
	queue<person> floorCallsDown;//Contains All Floors Calls that are going down
	int numberFloors;
public:
	building();
	void setFloor(int floorNumber);
	int getCurFloor();
	void getElevator();
	void getFloorCalls();
	void generate();

};
