#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Plane: public Vehicle
{
	public: Plane();
	Plane(int weight, float speed, float fuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};

Plane::Plane(): Vehicle() {}

Plane::Plane(int weight, float speed, float fuelConsumptionPerOneHundredKm): Vehicle(weight, speed, fuelConsumptionPerOneHundredKm) {}

float Plane::FuelConsumption(float time)
{
	return Vehicle::FuelConsumption(time);
}

void Plane::Show()
{
	cout << "Vehicle type: Plane" << "\n";
	Vehicle::Show();
}