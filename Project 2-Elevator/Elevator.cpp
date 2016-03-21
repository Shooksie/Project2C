#include "Elevator.h"


using namespace std;

void elevate::moveUp(){
	++current_floor;
	level++;
	checkPeople();
}
void elevate::moveDown(){
	--current_floor;
	level--;
	checkPeople();
}
int elevate::getLevel(){ 
	return level;
}
int elevate::getNumPeople(){ 
	return numPeople;
}
bool elevate::isUp(list<int> List){ 
	if (hasRequests(List) == false)
		return false;
	list<int>::iterator itr = List.begin();
	Up = (*itr > level);
	return Up;
}
bool elevate::hasRequests(list<int> List){
	return(!List.empty());
}
bool elevate::isDown(list<int> List){
	Down = !isUp(List);
	return Down;
}
void elevate::checkPeople(){
	list<person>::iterator itr;
	for (itr = people.begin(); itr != people.end(); ++itr){
		if (itr->getDesiredFloor() == level){
			people.erase(itr);
			numPeople--;
		}
	}
}
void elevate::ConnectItr(list<Floor> List){
	current_floor = List.begin();
}

bool elevate::isFull(){
	return (numPeople == 10);
}

void elevate::addPerson(person newP){
	if (!isFull()){
		people.pushback(newP);
		numPeople++;
		return;
	}
}

void elevate::removePerson(person leaving){
	list<person>::iterator itr;
	for (itr = people.begin(); itr != people.end(); ++itr){
		if (itr->getID() == leaving.getID()){
			people.erase(itr);
			numPeople--;
		}
	}
}
