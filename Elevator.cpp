#include "Elevator.h"


Elevator::Elevator()
{
	maxWeight = 1000;
	currentFloor = 1;
	maxFloor = 15;
	minFloor = 1;
	way = 1;
	currentWeigth = 0;
}

Elevator::Elevator(int _maxWeight, int _maxFloor, int _minFloor)
{
	maxWeight = _maxWeight;
	currentFloor = _minFloor;
	maxFloor = _maxFloor;
	minFloor = _minFloor;
	way = 1;
	currentWeigth = 0;
}

Elevator::Elevator(const Elevator& other) {
	maxWeight = other.maxWeight;
	currentFloor = other.currentFloor;
	maxFloor=other.maxFloor;
	minFloor=other.minFloor;
	stop = other.stop;
	way = other.way;
	currentWeigth = other.currentWeigth;
}

Elevator& Elevator::operator=(const Elevator& other) {
	maxWeight = other.maxWeight;
	currentFloor = other.currentFloor;
	maxFloor = other.maxFloor;
	minFloor = other.minFloor;
	stop = other.stop;
	way = other.way;
	currentWeigth = other.currentWeigth;
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
	cout << "Лифт:" << endl;
	cout << "________________________________________"<<endl;
	cout << "Грузоподъёмность\t"<<maxWeight << endl;
	cout << "Текущий вес:\t\t" << currentWeigth<<endl;
	cout << "Последний этаж:\t\t"<<maxFloor << endl;
	cout << "Первый этаж:\t\t"<<minFloor << endl;
	cout << "Текущий этаж:\t\t"<<currentFloor << endl;
	cout << "Остановки:\t";
	for (int i = 0; i < stop.size(); i++) {
		cout << stop[i] << " ";
	}
	cout<< endl << "__________________________________________"<<endl;
}


void Elevator::Motion() {
	if (stop.size() == 0) {
		cout << "Остановок нет" << endl;
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
		cout << "Остановок нет" << endl;
		return;
	}
	if (WeightTest() == 1) {
		cout << "Перегруз, необходимо исключить кого-то из пассажиров, находящихся в лифте" << endl;
		return;
	}
	CloseDoor();
	while (1) {
		for (int i = 0; i < stop.size(); i++) {
			if (currentFloor == stop[i]) {
				OpenDoor();
				return;
			}
		}
		if (way==0)
			cout << currentFloor << "         " << currentFloor - 1 << endl;
		if (way == 1)
			cout << currentFloor << "         " << currentFloor + 1 << endl;
		for (int i = 0; i < 10; i++) {
			if (way == 0)
				cout << "v";
			if (way == 1)
				cout << "^";
			Sleep(500);				
		}
		cout << endl;
		if (way==0)
			currentFloor--;
		if (way == 1)
			currentFloor++;
	}
	
}

void Elevator::PlusCurrentWeight (int i) {
	currentWeigth += i;
}
void Elevator::MinusCurrentWeight(int i) {
	currentWeigth -= i;
}

int Elevator::WeightTest() {
	if (maxWeight < currentWeigth) {
		return 1;
	}
	return 0;
}

void Elevator::OpenDoor() {
	cout <<endl<< "Этаж " << currentFloor << endl;
	cout << "Открытие дверей" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "<";
		Sleep(250);
	}
	cout << endl << endl;
}
void Elevator::CloseDoor() {
	cout << endl << "Осторожно, двери закрываются" << endl;
	for (int i = 0; i < 10; i++) {
		cout << ">";
		Sleep(250);
	}
	cout << endl << endl;
}
