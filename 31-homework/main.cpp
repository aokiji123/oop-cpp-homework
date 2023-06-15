#include <iostream>
using namespace std;

class House abstract {};

class PanelHouse : public House
{
public:
    PanelHouse()
    {
        cout << "Panel house built\n";
    }
};

class WoodHouse : public House
{
public:
    WoodHouse()
    {
        cout << "Wooden house built\n";
    }
};

class BrickHouse : public House
{
public:
    BrickHouse()
    {
        cout << "Brick house built\n";
    }
};

class Developer abstract
{
public:
    virtual House* Create() = 0;
};

class PanelDeveloper : public Developer
{
public:
    House* Create() override
    {
        return new PanelHouse;
    }
};

class WoodDeveloper : public Developer
{
public:
    House* Create() override
    {
        return new WoodHouse;
    }
};

class BrickDeveloper : public Developer
{
public:
    House* Create() override
    {
        return new BrickHouse;
    }
};

House* Client(Developer* pDev)
{
    return pDev->Create();
}

int main()
{
    Developer* pDev = new PanelDeveloper();
    House* pHouse = Client(pDev);
    delete pHouse;
    delete pDev;

    pDev = new WoodDeveloper();
    pHouse = Client(pDev);
    delete pHouse;
    delete pDev;

    pDev = new BrickDeveloper();
    pHouse = Client(pDev);
    delete pHouse;
    delete pDev;

    return 0;
}
