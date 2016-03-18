#include "Elevator.h"

using namespace std;

Elevator::Elevator(){
  numPeople = 0;
  level = 0;
  current_floor = frame.begin();
}

void Elevator::moveUp(){
  /* if elevator is on top floor
    throw std::exception("Elevator is currently on highest floor")*/
  ++current_floor;
  level = current_floor->floor_no;
  checkPeople();
}

void Elevator::moveDown(){
  /* if elevator is on bottom floor
    throw std::exception("Elevator is currently on lowest floor")*/
  --current_floor;
  level = current_floor->floor_no;
  checkPeople();
}

int Elevator::getLevel(){
  return level;
}

int Elevator::getNumPeople(){
  return numPeople;
}

bool Elevator::isUp(){
  return !floorCallsUp.empty();
}

bool Elevator::hasRequests(){
  return !floorCalls.empty();
}

bool Elevator::isDown(){
  return !floorCallsDown.empty();
}

void Elevator::checkPeople(){
  for (list<person> iterator iter = people.begin(); iter != people.end(); ++iter){
    if (level == iter->desired_floor){
      people.erase(iter);
    }
  }
}

void Elevator::addPerson(Person newP){
  people.push_back(newP);
}
