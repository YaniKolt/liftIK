#include "Elevator.h"


Elevator::Elevator()
{
	maxWeight = 1000;
	currentFloor = 1;
	maxFloor = 15;
	minFloor = 1;
	way = 1;
}

Elevator::Elevator(int _maxWeight, int _maxFloor, int _minFloor)
{
	maxWeight = _maxWeight;
	currentFloor = _minFloor;
	maxFloor = _maxFloor;
	minFloor = _minFloor;
	way = 1;
}

Elevator::Elevator(const Elevator& other) {
	maxWeight = other.maxWeight;
	currentFloor = other.currentFloor;
	maxFloor=other.maxFloor;
	minFloor=other.minFloor;
	stop = other.stop;
	way = other.way;
}

Elevator& Elevator::operator=(const Elevator& other) {
	maxWeight = other.maxWeight;
	currentFloor = other.currentFloor;
	maxFloor = other.maxFloor;
	minFloor = other.minFloor;
	return *this;
}

void Elevator::AddStop(int k) {
	if ((k > maxFloor) || (k < minFloor))
		return;
	for (int i = 0; i < stop.size(); i++) {
		if (stop[i] == k)
			return;
	}
	stop.push_back(k);
	for (int i = 0; i < stop.size(); i++) {
		for (int j = 0; j < stop.size() - i - 1; j++) {
			if (stop[j + 1] < stop[j]) {
				int temp = stop[j + 1];
				stop[j + 1] = stop[j];
				stop[j] = temp;
			}
		}
	}
}

void Elevator::print() {
	cout << "����:" << endl;
	cout << "________________________________________"<<endl;
	cout << "����������������\t"<<maxWeight << endl;
	cout << "��������� ����:\t"<<maxFloor << endl;
	cout << "������ ����:\t"<<minFloor << endl;
	cout << "������� ����:\t"<<currentFloor << endl;
	cout << "���������:\t";
	for (int i = 0; i < stop.size(); i++) {
		cout << stop[i] << " ";
	}
	cout<< endl << "__________________________________________"<<endl;
}

/*void Elevator::AddInsideStop(int k) {
	if ((k > maxFloor) || (k < minFloor))
		return;
	for (int i = 0; i < stop.size(); i++) {
		if (insideStop[i] == k)
			return;
	}
	insideStop.push_back(k);
}*/

void Elevator::Motion() {
	if (stop.size() == 0) {
		cout << "��������� ���" << endl;
		return;
	}
	if (currentFloor == stop[0])
		way = 1;
	if (currentFloor == stop[stop.size() - 1])
		way = 0;
	for (int i = 0; i < stop.size(); i++) {
		if (currentFloor == stop[i]) {
			for (int k=i; k < stop.size()-1; k++) {
					stop[k] = stop[k + 1];
			}
			stop.pop_back();

		}
			
	}
	if (stop.size() == 0) {
		cout << "��������� ���" << endl;
		return;
	}
	if (way == 0) {
		//test();
		while (1) {
			for (int i = 0; i < stop.size(); i++) {
				if (currentFloor == stop[i]) {
					cout << "���� " << currentFloor << endl;
					cout << "�������� ������" << endl;
					Sleep(2000);
					return;
				}
			}
			for (int i = 0; i < 10; i++) {
				Sleep(500);
				cout << "v";				
			}
			cout << endl;
			currentFloor--;
			cout << "���� " << currentFloor << endl;
		}
	}
	if (way == 1) {
		//test();
		while (1) {
			for (int i = 0; i < stop.size(); i++) {
				if (currentFloor == stop[i]) {
					cout << "���� " << currentFloor << endl;
					cout << "�������� ������" << endl;
					Sleep(2000);
					return;
				}
			}
			for (int i = 0; i < 10; i++) {
				Sleep(500);
				cout << "^";
			}
			cout << endl;
			currentFloor++;
			cout << "���� " << currentFloor << endl;
		}
	}
	
}