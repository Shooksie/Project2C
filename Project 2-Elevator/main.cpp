#include "Building.h"
#include <iostream>
#include <fstream>

using namespace std;

void main(){
	bool reloop = true;
	while (reloop) {
		list <person> People;

		int possiblePeople = rand() % 100;
		int numberOfPeople = 0;
		int choice;
		cout << "Welcome to the Elevator Simulator!!!!" << endl << "what would you like to do today?" << endl << "1. Simulate the defult elevator case?" << endl << "2. Simulate Custom elevator Case?" << endl << "3. Quit?" << endl << ">>";
		cin >> choice;
		switch (choice) {

		case 1:if(true){
			building Building;
			
			cout << possiblePeople << endl;

			for (int i = 0; i < possiblePeople; i++) {
				Building.generate();
				numberOfPeople++;
			}

			
			break;
		}
		case 2:
			if (true) {
				building Building;
				int floorNumber;
				int typeOfTraffic;
				int NumberElevators;
				cout << "specify the Number of floors" << endl << ">>";
				cin >> floorNumber;
				Building.setFloor(floorNumber);
				cout << "specify the type of traffic?" << endl << "1. low " << endl << "2. medium" << endl << "3. high" << endl << ">>";
				cin >> typeOfTraffic;
				cout << "specify the number of elevators?" << endl << ">>" ;
				cin >> NumberElevators;

				Building.generate(typeOfTraffic, floorNumber);
			}
			break;
		case 3:
			reloop = false;
			break;
		default:
			cout << "Please Enter a valid Option";
			break;
		}
	}
}