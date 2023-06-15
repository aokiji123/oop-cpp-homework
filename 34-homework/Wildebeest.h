#pragma once
#include "Herbivore.h"
using namespace std;

class Wildebeest : public Herbivore 
{
public:
    Wildebeest()
    {
        Weight = 200;
        Life = true;
    }
    void EatGrass()
    {
        cout << "Wildebeest has ate" << "\n";
        Weight += 5;
    }
    void Die()
    {
        cout << "Wildebeest die" << "\n";
        Life = false;
    }
    string GetName() { return "Wildebeest"; }
    string ToString()
    {
        stringstream str;
        str << boolalpha << "Wildebeest" << "\n"
            << "Weight: " << Weight << "\n"
            << "Alive: " << Life << "\n";
        return str.str();
    }
};