#pragma once
#include <iostream>
#include <string>
using namespace std;

class Passenger
{
	string name;
	int weight;
	int currentFloor;
	int neededFloor;
	int position;
public:
	Passenger();
	Passenger(int _neededFloor);
	Passenger(int _currentFloor, int _neededfloor);
	Passenger(string _name, int _currentFloor, int _neededfloor);
	Passenger(string _name, int _weight, int _currentFloor, int _neededfloor);
	int Get_currentFloor() { return currentFloor; }
	int Get_neededFloor() { return neededFloor; }
	int Get_position() { return position; };
	int Get_weight() { return weight; }
	void Set_position(int i);
	string Get_name() { return name; }
	void Print();
};

