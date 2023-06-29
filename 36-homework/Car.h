#pragma once
#include <iostream>
#include "Wheels.h"
#include "Engine.h"
#include "Door.h"
#include "Vehicle.h"
using namespace std;

class Car: protected Wheels, protected Engine, protected Door, protected Vehicle
{
protected: 
    int numberOfDoors;
	int numberOfWheels;

public: 
    Car();
	Car(int numberOfDoors, int numberOfWheels, float diameter, string firm, int power, int torque, int specificFuelConsumption, int height, int length);

	void Show();
};

Car::Car(): numberOfDoors(0), numberOfWheels(0) {}

Car::Car(int numberOfDoors, int numberOfWheels, float diameter, string firm, int power, int torque, int specificFuelConsumption, int height, int length):
	numberOfDoors(numberOfDoors), numberOfWheels(numberOfWheels), Wheels(diameter, firm), Engine(power, torque, specificFuelConsumption), Door(height, length) {}

void Car::Show()
{
	cout << "Wheels: " << "\n" << "Number of wheels: " << numberOfWheels << "\n";
	Wheels::Show();
	cout << "Engine: " << "\n";
	Engine::Show();
	cout << "Doors: " << "\n" << "Number of doors: " << numberOfDoors << "\n";
	Door::Show();
}