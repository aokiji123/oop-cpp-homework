#pragma once
#include "Vehicle.h"
using namespace std;

class Ship: public Vehicle
{
public: 
	Ship();
	Ship(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats);

	void Print();
	void Init();

	float FuelConsumption(float Distance);

	float GetCost();
	void SetCost(float Cost);

	float GetCapacity();
	void SetCapacity(float Capacity);

	int GetNumberOfSeats();
	void SetNumberOfSeats(int NumberOfSeats);
};

Ship::Ship() {}

Ship::Ship(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats): Vehicle(FuelConsumptionPerOneKm, Cost, Capacity, NumberOfSeats) {}

void Ship::Print()
{
	cout.precision(10);
	cout << "Type: Ship" << "\n" <<
		"Fuel consumption per 1 Km: " << FuelConsumptionPerOneKm << " l/km" << "\n" <<
		"Cost: " << Cost << "$" << "\n" <<
		"Capacity: " << Capacity << " kg" << "\n" <<
		"Number of seats: " << NumberOfSeats << "\n" << "\n";
}

void Ship::Init()
{
	cout << "Type: Ship" << "\n";
	cout << "Enter fuel consumption per 1 Km >> ";
	cin >> FuelConsumptionPerOneKm;
	cout << "Enter cost >> ";
	cin >> Cost;
	cout << "Enter capacity >> ";
	cin >> Capacity;
	cout << "Enter number of seats >> ";
	cin >> NumberOfSeats;
	cout << "\n";
}

float Ship::FuelConsumption(float Distance)
{
	return Distance * FuelConsumptionPerOneKm;
}

float Ship::GetCost()
{
	return Cost;
}

void Ship::SetCost(float Cost)
{
	this->Cost = Cost;
}

float Ship::GetCapacity()
{
	return Capacity;
}

void Ship::SetCapacity(float Capacity)
{
	this->Capacity = Capacity;
}

int Ship::GetNumberOfSeats()
{
	return NumberOfSeats;
}

void Ship::SetNumberOfSeats(int NumberOfSeats)
{
	this->NumberOfSeats = NumberOfSeats;
}