#pragma once
#include <ctime>
#include <string>

class person {
private:
	int current_floor;
	int desired_floor;
	int personID;
	bool goingUP;
public:
	person();
	int getID();
	void setID(int number);
	int getCurrentFloor();
	int getDesiredFloor();
	bool getDirection();

};
