#include "Passenger.h"
Passenger::Passenger()
{
	name = "Инкогнито";
	weight = 60;
	currentFloor = 1;
	neededFloor = 2;
	position = 0;
}
Passenger::Passenger(int _neededFloor) {
	name = "Инкогнито";
	weight = 60;
	currentFloor = 1;
	neededFloor = _neededFloor;
	position = 0;
}
Passenger::Passenger(int _currentFloor, int _neededfloor) {
	name = "Инкогнито";
	weight = 60;
	currentFloor = _currentFloor;
	neededFloor = _neededfloor;
	position = 0;
}
Passenger::Passenger(string _name, int _currentFloor, int _neededfloor) {
	name = _name;
	weight = 60;
	currentFloor = _currentFloor;
	neededFloor = _neededfloor;
	position = 0;
}
Passenger::Passenger(string _name, int _weight, int _currentFloor, int _neededfloor) {
	name = _name;
	weight = _weight;
	currentFloor = _currentFloor;
	neededFloor = _neededfloor;
	position = 0;
}

void Passenger::Print() {
	cout << currentFloor << "\t" << neededFloor << "\t" << weight;
	if (position == 0)
		cout << "\tЖдёт лифт";
	if (position == 1)
		cout << "\t В лифте";
	cout << "\t" << name;
}

void Passenger::Set_position(int k) {
	if ((k == 0) || (k == 1))
		position = k;
}
