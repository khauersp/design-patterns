#include <iostream>
#include <string>
using namespace std;

class lazySingleton
{

private:
    static lazySingleton *uniqueInstance;
    lazySingleton() : created(false) {}

public:
    bool created;
    static lazySingleton *getInstance()
    {
        if (!uniqueInstance)
        {
            uniqueInstance = new lazySingleton();
            uniqueInstance->created = true;
        }
        return uniqueInstance;
    }
};

lazySingleton *lazySingleton::uniqueInstance = nullptr;

class eagerSingleton
{
private:
    static eagerSingleton *uniqueInstance;
    eagerSingleton() { created = true; }

public:
    bool created;
    static eagerSingleton *getInstance()
    {
        return uniqueInstance;
    }
};

eagerSingleton *eagerSingleton::uniqueInstance = new eagerSingleton();

int main()
{
    lazySingleton *single = lazySingleton::getInstance();
    cout << boolalpha;
    cout << single->created << endl;
    lazySingleton *dub = lazySingleton::getInstance();
    single->created = false;
    cout << dub->created << endl; // prints false because it points to the same object as single

    eagerSingleton *single2 = eagerSingleton::getInstance();
    cout << boolalpha;
    cout << single2->created << endl;
}