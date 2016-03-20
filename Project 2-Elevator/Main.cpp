#include "Person.h"
#include <iostream>
#include <list>
using namespace std;


void main() {

	list <person> People;
	srand(time(NULL));
	int possiblePeople = rand() % 100;
	int numberOfPeople = 0;


	for (int i = 0; i < possiblePeople; i++) {
		bool TrueFalse = ((rand()%100) < 50);
		if (TrueFalse) {
			person newPerson;
			People.push_back(newPerson);
			newPerson.setID(numberOfPeople);
			numberOfPeople++;
			/*
			cout << "Person's ID: " << newPerson.getID() << endl <<
				"Person's Current Floor: " << newPerson.getCurrentFloor() << endl <<
				"Person's Desired Floor: " << newPerson.getDesiredFloor() << endl <<
				"Is the Person Going Up?: " << newPerson.getDirection() << endl << endl;*/
		}
	}
	cout << "There could have been " << possiblePeople << " possible people created." << endl;
	cout << "There were " << numberOfPeople << " created." << endl;
	system("pause");
	return;

	}

