#pragma once
#include <iostream>
using namespace std;

class Engine
{
protected:
    int power;
	int torque;
	int specificFuelConsumption;

public:
    Engine();
	Engine(int power, int torque, int specificFuelConsumption);

	void Show();
};

Engine::Engine(): power(0), torque(0), specificFuelConsumption(0) {}

Engine::Engine(int power, int torque, int specificFuelConsumption): power(power), torque(torque), specificFuelConsumption(specificFuelConsumption) {}

void Engine::Show()
{
	cout << "Power: " << power << " kW" << "\n" << "Torque: " << torque << " N*m" << "\n" << "Specific Fuel Consumption: " << specificFuelConsumption << " kW*h" << "\n";
}