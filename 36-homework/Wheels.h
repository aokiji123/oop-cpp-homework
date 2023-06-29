#pragma once
#include <iostream>
using namespace std;

class Wheels
{
protected:
    float diameter;
	string firm;

public:
    Wheels();
	Wheels(float diameter, string firm);

	void Show();
};

Wheels::Wheels(): diameter(0), firm("") {}

Wheels::Wheels(float diameter, string firm): diameter(diameter), firm(firm) {}

void Wheels::Show()
{
	cout << "Diamemeter: " << diameter << "\"" << "\n" << "Firm: " << firm << "\n";
}