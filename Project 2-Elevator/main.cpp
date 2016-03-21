#include "Building.h"
#include <iostream>
#include <fstream>

using namespace std;

void main() {
	bool reloop = true;

	cout << "Welcome to the Elevator Simulator!!!!" << endl << endl;
	while (reloop) {
		list <person> People;

		int possiblePeople = rand() % 100;
		int numberOfPeople = 0;
		int choice;
		cout << "What Would You Like to do Today?" << endl << "================================"
			<< endl << "1. Simulate the Default Elevator Case?" << endl << "2. Simulate Custom Elevator Case?" << endl << "3. Quit?" << endl << ">>";
		cin >> choice;
		cout << endl;
		switch (choice) {

		case 1:if (true) {
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

				//error checking
				bool check = true;
				while (check) {
					cout << "Specify the Number of Floors ( 2 to 100 )" << endl << ">>";
					cin >> floorNumber;
					if (floorNumber < 2 || floorNumber > 100)
						cout << endl << "Please Enter a Valid Option" << endl << endl;

					else {
						cout << endl;
						Building.setFloor(floorNumber);
						check = false;
					}
				}

				//error checking
				check = true;
				while (check) {
					cout << "Specify the Type of Traffic ( 1, 2, or 3 )" << endl << "1. Low " << endl << "2. Medium" << endl << "3. High" << endl << ">>";
					cin >> typeOfTraffic;
					if (typeOfTraffic != 1 && typeOfTraffic != 2 && typeOfTraffic != 3)
						cout << endl << "Please Enter a Valid Option" << endl << endl;
					else {
						cout << endl;
						Building.generate(typeOfTraffic, floorNumber);
						check = false;
					}
				}

				//error checking TBD
				cout << "Specify the Number of Elevators?" << endl << ">>";
				cin >> NumberElevators;
				cout << endl;


			}
			break;
		case 3:
			cout << "Goodbye!" << endl;
			reloop = false;
			system("pause");
			break;
		default:
			cout << "Please Enter a Valid Option" << endl << endl;
			break;
		}
	}
}
