#pragma once
#include "Herbivore.h"
using namespace std;

class Elk : public Herbivore 
{
public:
    Elk()
    {
        Weight = 540;
        Life = true;
    }
    void EatGrass()
    {
        cout << "Elk has ate" << "\n";
        Weight += 5;
    }
    void Die()
    {
        cout << "Elk die" << "\n";
        Life = false;
    }
    string GetName() 
    { 
        return "Elk"; 
    }
    string ToString()
    {
        stringstream str;
        str << boolalpha << "Elk" << "\n"
          << "Weight: " << Weight << "\n"
          << "Alive: " << Life << "\n";
        return str.str();
    }
};