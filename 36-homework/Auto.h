#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Auto: public Vehicle
{
public: Auto();
	Auto(int weight, float speed, float FuelConsumptionPerOneHundredKm);

	float FuelConsumption(float time);
	void Show();
};

Auto::Auto(): Vehicle() {}

Auto::Auto(int weight, float speed, float FuelConsumptionPerOneHundredKm): Vehicle(weight, speed, FuelConsumptionPerOneHundredKm) {}

float Auto::FuelConsumption(float time)
{
	return Vehicle::FuelConsumption(time);
}

void Auto::Show()
{
	cout << "Vehicle type: Auto" << "\n";
	Vehicle::Show();
}