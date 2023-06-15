#pragma once
#include "Carnivore.h"
using namespace std;

class Lion : public Carnivore 
{
public:
    Lion()
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
                cout << "Lion has ate " << herbivore->GetName() << "\n";
                Power += 25;
                herbivoresEaten++;
                herbivore->Die();
            }
            else 
			{
                cout << "Lion has tried to eat " << herbivore->GetName() << "\n";
                Power -= 25;
            }
        }
    }
    string ToString()
    {
        stringstream str;
        str << boolalpha << "Lion" << "\n"
          << "Power: " << Power << "\n"
          << "Herbivores eaten: " << herbivoresEaten << "\n";
        return str.str();
    }
};