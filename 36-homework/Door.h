#pragma once
#include <iostream>
using namespace std;

class Door
{
protected:
	int height;
	int length;

public:
    Door();
	Door(int height, int length);

	void Show();
};

#include "Door.h"

Door::Door(): height(0), length(0) {}

Door::Door(int height, int length): height(height), length(length) {}

void Door::Show()
{
	cout << "Height: " << height << "\"" << "\n" << "Length: " << length << "\"" << "\n";
}