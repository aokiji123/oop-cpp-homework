#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Ship: public Vehicle
{
public: 
    Ship();
	Ship(int weight, float speed, float fuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};

Ship::Ship(): Vehicle() {}

Ship::Ship(int weight, float speed, float fuelConsumptionPerOneHundredKm): Vehicle(weight, speed, fuelConsumptionPerOneHundredKm) {}

float Ship::FuelConsumption(float time)
{
	return Vehicle::FuelConsumption(time);
}

void Ship::Show()
{
	cout << "Vehicle type: Ship" << "\n";
	Vehicle::Show();
}