#include "Animalworld.h"
#include "Africa.h"
#include "NorthAmerica.h"
#include "Eurasia.h"
using namespace std;

int main()
{
    Continent* eurasia = new Eurasia();
    AnimalWorld biosphere(eurasia);

    for (int i = 0; i < 3; i++) 
	{
        biosphere.AddHerbivore();
        biosphere.AddCarnivore();
    }

    biosphere.MealsHerbivores();
    cout << "\n";
    biosphere.NutritionCarnivores();
    cout << "\n";

    biosphere.Print();

    delete eurasia;

    Continent* africa = new Africa();
    AnimalWorld biosphere2(africa);

    for (int i = 0; i < 3; i++) 
	{
        biosphere2.AddHerbivore();
        biosphere2.AddCarnivore();
    }

    biosphere2.MealsHerbivores();
    cout << "\n";
    biosphere2.NutritionCarnivores();
    cout << "\n";

    biosphere2.Print();

    delete africa;

    Continent* northAmerica = new NorthAmerica();
    AnimalWorld biosphere3(northAmerica);

    for (int i = 0; i < 3; i++) 
	{
        biosphere3.AddHerbivore();
        biosphere3.AddCarnivore();
    }

    biosphere3.MealsHerbivores();
    cout << "\n";
    biosphere3.NutritionCarnivores();
    cout << "\n";

    biosphere3.Print();

    delete northAmerica;
}