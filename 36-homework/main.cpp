#include "includes.h"
#include "functions.h"
using namespace std;

int main()
{
	Car car(4, 4, 15, "Fronway", 40, 4000, 20, 50, 35);
	car.Show();
	Sleep(5000);

	int choice;
	vector<Vehicle*> vehicle(0);
	do {
		choice = menu();
		if (choice == 1) add(vehicle);
		if (choice == 2) del(vehicle);
		if (choice == 3) show(vehicle);
	} while (choice != 4);
}