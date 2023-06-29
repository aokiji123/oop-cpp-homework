#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Bike: public Vehicle
{
public: Bike();
	Bike(int weight, float speed, float fuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};

Bike::Bike(): Vehicle() {}

Bike::Bike(int weight, float speed, float fuelConsumptionPerOneHundredKm): Vehicle(weight, speed, fuelConsumptionPerOneHundredKm) {}

float Bike::FuelConsumption(float time)
{
	return Vehicle::FuelConsumption(time);
}

void Bike::Show()
{
	cout << "Vehicle type: Bike" << "\n";
	Vehicle::Show();
}