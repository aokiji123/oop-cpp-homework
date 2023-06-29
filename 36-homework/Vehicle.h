#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int weight;
	float speed;
	float fuelConsumptionPerOneHundredKm;

public:
    Vehicle();
	Vehicle(int weight, float speed, float fuelConsumptionPerOneHundredKm);

	virtual float FuelConsumption(float time);
	virtual void Show();
};

Vehicle::Vehicle(): weight(0), speed(0), fuelConsumptionPerOneHundredKm(0) {}

Vehicle::Vehicle(int weight, float speed, float fuelConsumptionPerOneHundredKm): weight(weight), speed(speed), fuelConsumptionPerOneHundredKm(fuelConsumptionPerOneHundredKm) {}

float Vehicle::FuelConsumption(float time)
{
	return time *speed * fuelConsumptionPerOneHundredKm;
}

void Vehicle::Show()
{
	cout << "Weight: " << weight << "\n" << "Speed: " << speed << "\n" << "Fuel consumption per 100 km: " << fuelConsumptionPerOneHundredKm << "\n";
}