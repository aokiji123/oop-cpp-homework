#include <iostream>
#include "Animal.h"

int main() {
    IAnimal* ref[4] = { 
        new Cat("Cat", 4, "black"), 
        new Elephant("Elephant", 1000, "Grey"), 
        new Penguin("Penguin", 15, "Blue"), 
        new Duck("Duck", 8, "Grey") 
    };

    for (int i = 0; i < 4; i++) {
        ref[i]->Eat();
        ref[i]->Move();
    }

    ref[0] = new Parrot("Parrot", 1, "Green");
    ref[0]->Eat();
    ref[0]->Move();

    ISwim* p[2] = { new Penguin("Penguin", 15, "Blue"), new Duck("Duck", 8, "Grey") };
    for (int i = 0; i < 2; i++) p[i]->Swim();

    IBird* f[2] = { new Parrot("Parrot", 1, "Green"), new Duck("Duck", 8, "Grey") };
    for (int i = 0; i < 2; i++) f[i]->Fly();
}