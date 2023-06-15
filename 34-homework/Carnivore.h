#pragma once
#include "Herbivore.h"

class Carnivore {
protected:
    double Power;
    int herbivoresEaten;

public:
    virtual void Eat(Herbivore* herbivore) = 0;
    virtual std::string ToString() = 0;
};