#pragma once
#include "Carnivore.h"
using namespace std;

class Tiger : public Carnivore 
{
public:
    Tiger()
    {
        Power = 750;
        herbivoresEaten = 0;
    }
    void Eat(Herbivore* herbivore)
    {
        if (herbivore->IsAlive()) 
		{
            if (Power >= herbivore->GetWeight()) 
			{
                cout << "Tiger has ate " << herbivore->GetName() << "\n";
                Power += 50;
                herbivoresEaten++;
                herbivore->Die();
            }
            else 
			{
                cout << "Tiger has tried to eat " << herbivore->GetName() << "\n";
                Power -= 50;
            }
        }
    }
    string ToString()
    {
        stringstream str;
        str << boolalpha << "Tiger" << "\n"
          << "Power: " << Power << "\n"
          << "Herbivores eaten: " << herbivoresEaten << "\n";
        return str.str();
    }
};