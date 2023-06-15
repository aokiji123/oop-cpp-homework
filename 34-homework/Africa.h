#pragma once
#include "Continent.h"
#include "Wildebeest.h"
#include "Lion.h"

class Africa : public Continent {
public:
    Herbivore* createHerbivore() { return new Wildebeest(); }
    Carnivore* createCarnivore() { return new Lion(); }
};