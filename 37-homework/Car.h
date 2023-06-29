#pragma once
#include "Vehicle.h"
using namespace std;

class Car: public Vehicle
{
public: 
    Car();
	Car(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats);

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

Car::Car() {}

Car::Car(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats): Vehicle(FuelConsumptionPerOneKm, Cost, Capacity, NumberOfSeats) {}

void Car::Print()
{
	cout << "Type: Car" << "\n" <<
		"Fuel consumption per 1 Km: " << FuelConsumptionPerOneKm << " l/km" << "\n" <<
		"Cost: " << Cost << "$" << "\n" <<
		"Capacity: " << Capacity << " kg" << "\n" <<
		"Number of seats: " << NumberOfSeats << "\n" << "\n";
}

void Car::Init()
{
	cout << "Type: Car" << "\n";
	cout << "Enter fuel consumption per 1 Km: ";
	cin >> FuelConsumptionPerOneKm;
	cout << "Enter cost: ";
	cin >> Cost;
	cout << "Enter capacity: ";
	cin >> Capacity;
	cout << "Enter number of seats: ";
	cin >> NumberOfSeats;
	cout << "\n";
}

float Car::FuelConsumption(float Distance)
{
	return Distance * FuelConsumptionPerOneKm;
}

float Car::GetCost()
{
	return Cost;
}

void Car::SetCost(float Cost)
{
	this->Cost = Cost;
}

float Car::GetCapacity()
{
	return Capacity;
}

void Car::SetCapacity(float Capacity)
{
	this->Capacity = Capacity;
}

int Car::GetNumberOfSeats()
{
	return NumberOfSeats;
}

void Car::SetNumberOfSeats(int NumberOfSeats)
{
	this->NumberOfSeats = NumberOfSeats;
}