#include <iostream>
#include <string>
using namespace std;

class Beverage
{
public:
    string description;
    Beverage() : description("Unknown Beverage") {}
    virtual string getDescription()
    {
        return description;
    }
    virtual double cost() = 0; // Making cost() a pure virtual function
};

class CondimentDecorator : public Beverage
{
public:
    virtual string getDescription() = 0; // Making getDescription() a pure virtual function
};

class Espresso : public Beverage
{
public:
    Espresso()
    {
        description = "Espresso";
    }
    double cost()
    {
        return 1.99;
    }
};

class Mocha : public CondimentDecorator
{
public:
    Beverage *beverage;
    Mocha(Beverage *beverage_in)
    {
        beverage = beverage_in;
    }
    string getDescription()
    {
        return beverage->getDescription() + ", Mocha";
    }
    double cost()
    {
        return 0.2 + beverage->cost();
    }
};

int main()
{
    Beverage *bev = new Espresso();
    cout << bev->getDescription() << endl;
    bev = new Mocha(bev);
    cout << bev->getDescription() << endl;
    cout << bev->cost() << endl;
    return 0;
}
