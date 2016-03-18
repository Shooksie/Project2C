#include <iostream>
#include <string>
#include <cstdlib>
#include "Person.h"

using namespace std;


class elevator {
private:
	int currentNo, level;
	person numberOfPeople[10];
public:
	void MoveUp();
	void MoveDown();
	int getCurrent();

};
