#include <iostream>
using namespace std;

class Duck
{
public:
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MallardDuck : public Duck
{
public:
    void quack()
    {
        cout << "Quack" << endl;
    }
    void fly()
    {
        cout << "I'm flying" << endl;
    }
};

class Turkey
{
public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey : public Turkey
{
public:
    void gobble()
    {
        cout << "Gobble gobble!" << endl;
    }
    void fly()
    {
        cout << "I'm flying a short distance!" << endl;
    }
};

class TurkeyAdapter : public Duck
{
    Turkey *turkey;

public:
    TurkeyAdapter(Turkey *turkey)
    {
        this->turkey = turkey;
    }
    void quack()
    {
        turkey->gobble();
    }
    void fly()
    {
        for (int i = 0; i < 5; i++)
        {
            turkey->fly();
        }
    }
};

int main()
{
    MallardDuck *duck = new MallardDuck();
    WildTurkey *turkey = new WildTurkey();
    Duck *turkeyAdapter = new TurkeyAdapter(turkey);

    turkey->gobble();
    turkey->fly();

    duck->fly();
    duck->quack();

    turkeyAdapter->fly();
    turkeyAdapter->quack();
}