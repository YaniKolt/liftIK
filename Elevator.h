#pragma once
#include <vector>
#include <iostream>
#include <Windows.h>
using namespace std;

class Elevator
{
	int maxWeight;
	int currentFloor;
	int maxFloor;
	int minFloor;
	vector <int> stop;
	int way; //0-down, 1-up;
	int currentWeigth;
	
	
public:
	Elevator();
	Elevator(int _maxWeight, int _maxFloor, int _minFloor);
	Elevator(const Elevator& other);
	int Get_maxFloor() {return maxFloor;}
	int Get_minFloor() {return minFloor;}
	int Get_currentFloor() { return currentFloor; }
	int Get_way() { return way; }
	Elevator& operator=(const Elevator& other);
	void AddStop(int i);
	void print();
	void Motion();
	void PlusCurrentWeight (int i);
	void MinusCurrentWeight (int i);
	int WeightTest();
private:
	void OpenDoor();
	void CloseDoor();
};



