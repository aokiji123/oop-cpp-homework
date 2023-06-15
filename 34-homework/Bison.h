#pragma once
#include "Herbivore.h"
using namespace std;

class Bison : public Herbivore {
public:
    Bison()
    {
        Weight = 725;
        Life = true;
    }
    void EatGrass()
    {
        cout << "Bison has ate" << "\n";
        Weight += 5;
    }
    void Die()
    {
        cout << "Bison died" << "\n";
        Life = false;
    }
    string GetName() { return "Bison"; }
    string ToString()
    {
        stringstream str;
        str << boolalpha << "Bison" << "\n" << "Weight: " << Weight << "\n" << "Alive: " << Life << "\n";
        return str.str();
    }
};