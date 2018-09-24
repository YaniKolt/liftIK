#include <iostream>
#include "Elevator.h"
#include "Passenger.h"
#include <locale>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
int menu(Elevator& A, vector <Passenger> &listofPass);
Elevator startmenu();
int Passmenu(Elevator& A, vector <Passenger> &listofPass);
void AddPass(Elevator& A, vector <Passenger> &listofPass);
void BubbleSort(vector <Passenger> &listofPass);
void PrintListofPass(vector <Passenger> &listofPass);
void DelPas(vector <Passenger> &listofPass, int k);
void Passin(Elevator& A, vector <Passenger> &listofPass);
void Passout(Elevator& A, vector <Passenger> &listofPass);

int main()
{
	setlocale(LC_ALL, "Rus");
	int exit = 0;
	Elevator A;
	A = startmenu();
	vector <Passenger> listofPass;
	while (exit != 1)
		exit = menu (A, listofPass);
	return 0;
}

Elevator startmenu() {
	cout << "Добро пожаловать в \"Elevator\"" << endl;
	cout << "Давайте создадим лифт" << endl;
	int maxWeight = 0; 
	while ((maxWeight < 50) || (maxWeight > 10000)) {
		cout << "Введите грузоподъёмность лифта" << endl;
		cin >> maxWeight;
	}
	int minFloor = 10;
	while ((minFloor < -10) || (minFloor > 1)) {
		cout << "Введите номер самого нижнего этажа" << endl;
		cin >> minFloor;
	}
	int maxFloor = minFloor;
	while ((maxFloor <= minFloor) || (maxFloor > 150)) {
		cout << "Введите номер верхнего этажа" << endl;
		cin >> maxFloor;
	}
	Elevator A (maxWeight, maxFloor, minFloor);
	cout << "Лифт создан" << endl;
	cout << "Начнём эксплуатацию" << endl;
	return A;
}

int menu (Elevator& A, vector <Passenger> &listofPass) {
	cout<< endl << "****************************************************" << endl;
	cout << "1) Управление пассажирами" << endl;
	cout << "2) Поехали" << endl;
	cout << "3) Добавить событие" << endl;
	cout << "4) Выход" << endl;
	cout << "****************************************************" << endl;
	cout << endl << endl;
	int k = 0;
	while ((k < 1) || (k > 4)) {
		cout << "Введите номер команды" << endl;
		cin >> k;
	}
	if (k == 1)
		Passmenu(A, listofPass);
	if (k == 2) {
		Passin(A, listofPass);
		A.Motion();
		Passout(A, listofPass);
	}
	if (k == 3)
		//ActionMenu();
	if (k == 4)
		return 1;
	return 0;
}

int Passmenu(Elevator& A, vector <Passenger> &listofPass) {
	cout << "1) Добавить пассажира" << endl;
	cout << "2) Удалить пассажира" << endl;
	cout << "3) Вывести на экран список пассажиров" << endl;
	cout << "4) Назад" << endl;
	cout << endl << endl;
	int k = 0;
	while ((k < 1) || (k > 4)) {
		cout << "Введите номер команды" << endl;
		cin >> k;
	}
	if (k == 1)
		AddPass(A, listofPass);
	if (k == 2){
		while ((k < 0) || k > listofPass.size()) {
			cout << "Введите номер пассажира, которого нужно искючить" << endl;
			cin >> k;
		}
	DelPas(listofPass, k-1);
	}
	if (k == 3){
		PrintListofPass(listofPass);
		A.print();
	}
	if (k == 4)
		menu(A, listofPass);
	return 0;
}

void AddPass(Elevator& A, vector <Passenger> &listofPass) {
	int j=0;
	while ((j != 1)&&(j != 2)) {
		cout << "1) Рандом" << endl;
		cout << "2) Вручную" << endl;
		cin >> j;
	}
	if (j == 1) {
		int w=0;
		while ((w <= 0) || (w > 10)) {
			cout << "Сколько пассажиров хотите добавить (не более 10)" << endl;
			cin >> w;
		}
		for (int i = 0; i < w; i++) {
			string name = "Incognito";
			int weight = rand() % 80 + 50;
			int currentFloor = rand() % ((A.Get_maxFloor() - A.Get_minFloor()) + A.Get_minFloor());
			int neededFloor = rand() % ((A.Get_maxFloor() - A.Get_minFloor()) + A.Get_minFloor());
			Passenger P(name, weight, currentFloor, neededFloor);
			listofPass.push_back(P);
			A.AddStop(currentFloor);
			BubbleSort(listofPass);
		}
		return;
	}
	int k = -1;
	while ((k < 0) || (k > 10)) {
		cout << "Сколько пассажиров хотите добавить (не более 10)" << endl;
		cin >> k;
	}
	for (int i = 0; i < k; i++) {
		string name = "Инкогнито";
		cout << "Введите имя" << endl;
		cin >> name;
		int weight = 0;
		while ((weight <= 0) || (weight > 300)) {
			cout << "Введите вес" << endl;
			cin >> weight;
		}
		int currentFloor=-100;
		while ((currentFloor < A.Get_minFloor()) || (currentFloor > A.Get_maxFloor())) {
			cout << "Введите этаж, на котором он находится" << endl;
			cin >> currentFloor;
		}
		int neededFloor = -100;
		while ((neededFloor < A.Get_minFloor()) || (neededFloor > A.Get_maxFloor())) {
			cout << "Введите нужный этаж" << endl;
			cin >> neededFloor;
		}
		Passenger P(name, weight, currentFloor, neededFloor);
		listofPass.push_back(P);
		A.AddStop(currentFloor);
	}
	BubbleSort(listofPass);
}

void BubbleSort(vector <Passenger> &listofPass) {
	for (int i = 0; i < listofPass.size(); i++) {
		for (int j = 0; j < listofPass.size() - i - 1; j++) {
			if (listofPass[j + 1].Get_currentFloor() < listofPass[j].Get_currentFloor()) {
				Passenger temp = listofPass[j + 1];
				listofPass[j + 1] = listofPass[j];
				listofPass[j] = temp;
			
			}
			if (listofPass[j + 1].Get_currentFloor() == listofPass[j].Get_currentFloor()) {
				if (listofPass[j + 1].Get_name() < listofPass[j].Get_name()) 
					{
						Passenger temp = listofPass[j + 1];
						listofPass[j + 1] = listofPass[j];
						listofPass[j] = temp;
					}
				}
		}
	}
}

void PrintListofPass(vector <Passenger> &listofPass) {
	cout << endl;
	for (int i = 0; i < listofPass.size(); i++) {
		cout << i+1 <<")"<< "\t";
		listofPass[i].Print();
	}
	cout << endl;
}

void DelPas(vector<Passenger> &listofPass, int k) {
	if (k >= 0) {
		for (int i = k; i < listofPass.size()-1; i++) {
			listofPass[i] = listofPass[i + 1];
		}
		listofPass.pop_back();
	}
}

void Passin(Elevator& A, vector <Passenger> &listofPass) {
	for (int i = 0; i < listofPass.size(); i++) {
		if (A.Get_currentFloor() == listofPass[i].Get_currentFloor()) {
			cout << "Пассажир " << listofPass[i].Get_name() << " зашёл в лифт" << endl;
			A.AddStop(listofPass[i].Get_neededFloor());
			listofPass[i].Set_position(1);
			Sleep(2000);
		}
	}
}

void Passout(Elevator& A, vector <Passenger> &listofPass) {
	int i = 0;
	while (i < listofPass.size()) {
		if ((A.Get_currentFloor() == listofPass[i].Get_neededFloor())&&(listofPass[i].Get_position()==1)) {
			cout << "Пассажир " << listofPass[i].Get_name() << " вышел из лифта" << endl;
			DelPas(listofPass, i);
			i = i - 1;
			Sleep(2000);
		}
		i++;
	}
}