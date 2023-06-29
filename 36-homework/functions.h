#pragma once
#include "includes.h"
using namespace std;

int menu()
{
	system("cls");
	int choice;
	cout
		<<
		"---------------------" << "\n" <<
		"What you want to do?" << "\n" <<
		"1. Add a new vehicle" << "\n" <<
		"2. Delete a vehicle" << "\n" <<
		"3. Show all vehicles" << "\n" <<
		"4. Exit" << "\n" <<
		"---------------------" << "\n" <<
		">>> ";
	cin >> choice;
	if (choice < 1 || choice > 4)
	{
		system("cls");
		menu();
	}

	return choice;
}

void add(vector<Vehicle*> &v)
{
	ADD: system("cls");
	int choice;

	cout <<
	"---------------------" << "\n" <<
	"What type of vehicle you want to add?" << "\n" <<
	"1. Plane" << "\n" <<
	"2. Ship" << "\n" <<
	"3. Truck" << "\n" <<
	"4. Bike" << "\n" <<
	"5. Auto" << "\n" <<
	"6. Return" << "\n" <<
	"---------------------" << "\n" <<
	">>> ";

	cin >> choice;

	if (choice < 1 || choice > 6) goto ADD;

	else if (choice == 1)
	{
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		cout << "---------------------" << "\n" << "Enter data of the plane" << "\n" << "---------------------" << "\n";
		cout << "Weight >>> ";
		cin >> weight;
		cout << "Speed >>> ";
		cin >> speed;
		cout << "Fuel consumption per 100 km >>> ";
		cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Plane(weight, speed, FuelConsumptionPerOneHundredKm));
	}
	else if (choice == 2)
	{
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		cout << "---------------------" << "\n" << "Enter data of the ship" << "\n" << "---------------------" << "\n";
		cout << "Weight >>> ";
		cin >> weight;
		cout << "Speed >>> ";
		cin >> speed;
		cout << "Fuel consumption per 100 km >>> ";
		cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Ship(weight, speed, FuelConsumptionPerOneHundredKm));
	}
	else if (choice == 3)
	{
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		cout << "---------------------" << "\n" << "Enter data of the truck" << "\n" << "---------------------" << "\n";
		cout << "Weight >>> ";
		cin >> weight;
		cout << "Speed >>> ";
		cin >> speed;
		cout << "Fuel consumption per 100 km >>> ";
		cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Truck(weight, speed, FuelConsumptionPerOneHundredKm));
	}
	else if (choice == 4)
	{
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;

		system("cls");
		cout << "---------------------" << "\n" << "Enter data of the bike" << "\n" << "---------------------" << "\n";
		cout << "Weight >>> ";
		cin >> weight;
		cout << "Speed >>> ";
		cin >> speed;
		cout << "Fuel consumption per 100 km >>> ";
		cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Bike(weight, speed, FuelConsumptionPerOneHundredKm));
	}
	else if (choice == 5)
	{
		int weight;
		float speed;
		float FuelConsumptionPerOneHundredKm;
		system("cls");
		cout << "---------------------" << "\n" << "Enter data of the auto" << "\n" << "---------------------" << "\n";
		cout << "Weight >>> ";
		cin >> weight;
		cout << "Speed >>> ";
		cin >> speed;
		cout << "Fuel consumption per 100 km >>> ";
		cin >> FuelConsumptionPerOneHundredKm;

		v.push_back(new Auto(weight, speed, FuelConsumptionPerOneHundredKm));
	}
	else return;
}

void del(vector<Vehicle*> &v)
{
	DEL: system("cls");
	int choice;
	cout <<
	"----------------------------------------------------------" << "\n" <<
	"Which element do you want to delete? (Enter a number only)" << "\n" <<
	"----------------------------------------------------------" << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << i + 1 << ". ";
		v[i]->Show();
		cout << "----------------------------------------------------------" << "\n";
	}

	cout << "To return enter 0 >>> ";

	cin >> choice;
	if (choice == 0) return;
	else if (choice < 0 || choice > v.size()) goto DEL;
	else
	{
		v.erase(v.begin() + choice - 1);
		return;
	}
}

void show(vector<Vehicle*> v)
{
	system("cls");
	char symbol;

	cout << "---------------------" << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << i + 1 << ". ";
		v[i]->Show();
		cout << "---------------------" << "\n";
	}

	cout << "To return enter r or R >>> ";

	SYMBOL:
		cin >> symbol;
	if (symbol == 'r' || symbol == 'R') return;
	else goto SYMBOL;
}