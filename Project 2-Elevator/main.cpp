#include "Building.h"
#include <iostream>
#include <fstream>

using namespace std;

void main(){
	bool reloop = true;
	while (reloop) {
		int choice;
		cout << "Welcome to the Elevator Simulator!!!!" << endl << "what would you like to do today?" << endl << "1. Simulate the defult elevator case?" << endl << "2. Simulate Custom elevator Case?" << endl << "3. Quit?" << endl << ">>";
		cin >> choice;
		switch (choice) {

		case 1:
			building Building();
			break;
		case 2:
			if (true) {
				int floorNumber;
				int typeOfTraffic;
				int NumberElevators;
				cout << "specify the Number of floors" << endl;
				cout << "specify the type of traffic?" << endl << "1. low " << endl << "2. medium" << endl << "3. high" << endl;
				cout << "specify the number of elevators?" << endl;
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