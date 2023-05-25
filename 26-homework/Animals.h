#pragma once
using namespace std;

class Animal {
public:
    virtual void Speak() = 0;
};

class Frog : public Animal {
public:
    void Speak() { cout << "Kwa" << endl; }
};

class Dog : public Animal {
public:
    void Speak() { cout << "Gaw" << endl; }
};

class Cat : public Animal {
public:
    void Speak() { cout << "Meow" << endl; }
    void Scratch(bool isHomeworkDone) {
        if (isHomeworkDone) cout << "The cat doesn't scratch" << endl;
        else cout << "The cat scratches" << endl;
    }
    void Purr() { cout << "The cat purrs" << endl; }
};