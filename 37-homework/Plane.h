#pragma once
#include "Vehicle.h"
using namespace std;

class Plane: public Vehicle
{
public:
	Plane();
	Plane(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats);

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

Plane::Plane() {}

Plane::Plane(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats): Vehicle(FuelConsumptionPerOneKm, Cost, Capacity, NumberOfSeats) {}

void Plane::Print()
{
	cout.precision(10);
	cout << "Type: Plane" << "\n" <<
		"Fuel consumption per 1 Km: " << FuelConsumptionPerOneKm << " l/km" << "\n" <<
		"Cost: " << Cost << "$" << "\n" <<
		"Capacity: " << Capacity << " kg" << "\n" <<
		"Number of seats: " << NumberOfSeats << "\n" << "\n";
}

void Plane::Init()
{
	cout << "Type: Plane" << "\n";
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

float Plane::FuelConsumption(float Distance)
{
	return Distance * FuelConsumptionPerOneKm;
}

float Plane::GetCost()
{
	return Cost;
}

void Plane::SetCost(float Cost)
{
	this->Cost = Cost;
}

float Plane::GetCapacity()
{
	return Capacity;
}

void Plane::SetCapacity(float Capacity)
{
	this->Capacity = Capacity;
}

int Plane::GetNumberOfSeats()
{
	return NumberOfSeats;
}

void Plane::SetNumberOfSeats(int NumberOfSeats)
{
	this->NumberOfSeats = NumberOfSeats;
}