#pragma once
#include "Continent.h"
#include "Elk.h"
#include "Tiger.h"

class Eurasia : public Continent 
{
public:
    Herbivore* createHerbivore() 
    { 
        return new Elk(); 
    }
    Carnivore* createCarnivore() { 
        return new Tiger(); 
    }
};