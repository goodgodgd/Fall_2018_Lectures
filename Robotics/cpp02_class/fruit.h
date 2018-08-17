#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
#include <string>

using namespace std;

class Fruit
{
// access modifier 'public': accessible by anyone
public:
    // constructor
    Fruit();

    // constructor overloading
    Fruit(std::string _name);

    // desctructor
    ~Fruit();

    // public methods: used by other class/function
    void pollinated();
    void ripen();
    bool isPickable();

// access modifier 'private': accessible only by itself
private:

    // private methods: only used in this class, internal operators
    bool isRipe();
    void increaseSweetness();

    // private member variable (field)
    // normally, member variables are declared in private for encapsulation
    int sweetness;
    std::string name;
};

#endif // FRUIT_H
