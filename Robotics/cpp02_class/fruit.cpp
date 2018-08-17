#include "fruit.h"

Fruit::Fruit()
    : sweetness(0), name("fruit")
{
    // the line above is the same as:
    sweetness = 0;
    name = "fruit";
    cout << "Fruit instance is created" << endl;
}

Fruit::Fruit(std::string _name)
    : sweetness(0), name(_name)
{
    // the line above is the same as:
    sweetness = 0;
    name = _name;
    cout << "Fruit instance is created by name: " << name << endl;
}

Fruit::~Fruit()
{
    cout << name << " instance is destroyed" << endl;
}

void Fruit::pollinated()
{
    cout << "The flower was pollinated" << endl;
    sweetness = 0;
}

void Fruit::ripen()
{
    increaseSweetness();
    cout << name << " is ripening, current sweetness: " << sweetness << endl;
}

bool Fruit::isPickable()
{
    if(isRipe())
    {
        cout << name << " ripened, it is pickable" << endl;
        return true;
    }
    else
    {
        cout << name << " is not ripe, pick it later" << endl;
        return false;
    }
}

bool Fruit::isRipe()
{
    return (sweetness > 3);
}

void Fruit::increaseSweetness()
{
    sweetness++;
}

