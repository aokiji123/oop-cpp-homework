#pragma once
#include "Carnivore.h"

class Continent {
public:
    virtual Herbivore* createHerbivore() = 0;
    virtual Carnivore* createCarnivore() = 0;
};