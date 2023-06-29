#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Truck: public Vehicle
{
public:
    Truck();
	Truck(int weight, float speed, float fuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};

Truck::Truck(): Vehicle() {}

Truck::Truck(int weight, float speed, float fuelConsumptionPerOneHundredKm): Vehicle(weight, speed, fuelConsumptionPerOneHundredKm) {}

float Truck::FuelConsumption(float time)
{
	return Vehicle::FuelConsumption(time);
}

void Truck::Show()
{
	cout << "Vehicle type: Truck" << "\n";
	Vehicle::Show();
}