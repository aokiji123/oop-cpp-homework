#pragma once
#include "Carnivore.h"
using namespace std;

class Wolf : public Carnivore 
{
public:
    Wolf()
    {
        Power = 600;
        herbivoresEaten = 0;
    }
    void Eat(Herbivore* herbivore)
    {
        if (herbivore->IsAlive()) 
		{
            if (Power >= herbivore->GetWeight()) 
			{
                cout << "Wolf has ate " << herbivore->GetName() << "\n";
                Power += 20;
                herbivoresEaten++;
                herbivore->Die();
            }
            else 
			{
                cout << "Wolf has tried eat " << herbivore->GetName() << "\n";
                Power -= 20;
            }
        }
    }
    string ToString()
    {
        stringstream str;
        str << boolalpha << "Wolf" << "\n"
          << "Power: " << Power << "\n"
          << "Herbivores eaten: " << herbivoresEaten << "\n";
        return str.str();
    }
};