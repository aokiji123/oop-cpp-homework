#pragma once

class Vehicle
{
protected:
	float FuelConsumptionPerOneKm;
	float Cost;
	float Capacity;
	int NumberOfSeats;

public:
	Vehicle();
	Vehicle(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats);

	virtual void Print() = 0;
	virtual void Init() = 0;

	virtual float FuelConsumption(float Distance) = 0;

	virtual float GetCost() = 0;
	virtual void SetCost(float Cost) = 0;

	virtual float GetCapacity() = 0;
	virtual void SetCapacity(float Capacity) = 0;

	virtual int GetNumberOfSeats() = 0;
	virtual void SetNumberOfSeats(int NumberOfSeats) = 0;
};

Vehicle::Vehicle(): FuelConsumptionPerOneKm(0), Cost(0), Capacity(0), NumberOfSeats(0) {}

Vehicle::Vehicle(float FuelConsumptionPerOneKm, float Cost, float Capacity, int NumberOfSeats): FuelConsumptionPerOneKm(FuelConsumptionPerOneKm), Cost(Cost), Capacity(Capacity), NumberOfSeats(NumberOfSeats) {}