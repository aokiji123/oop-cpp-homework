#pragma once
#include "Continent.h"
#include "Bison.h"
#include "Wolf.h"

class NorthAmerica : public Continent 
{
public:
	Herbivore* createHerbivore() 
	{ 
		return new Bison(); 
	}
	Carnivore* createCarnivore() 
	{ 
		return new Wolf(); 
	}
};