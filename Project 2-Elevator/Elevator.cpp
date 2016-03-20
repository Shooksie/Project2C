#include "Elevator.h"


using namespace std;

void elevate::moveUp(){}
void elevate::moveDown(){}
int elevate::getLevel(){ return NULL; }
int elevate::getNumPeople(){ return NULL; }
bool elevate::isUp(){ return true; }
bool elevate::hasRequests(){ return true; }
bool elevate::isDown(){ return true; }
void elevate::checkPeople(){}
void elevate::ConnectItr(list<Floor> List){
	current_floor = List.begin();
}