#ifndef FUNCTIONBASEDCODE_H
#define FUNCTIONBASEDCODE_H

#include <iostream>
#include <string>
using namespace std;


void ripen(const string name, int& sweetness, float& weight)
{
    sweetness += 1;
    weight += 0.5f;
    cout << name << "'s current sweetness=" << sweetness << ", weight=" << weight << endl;
}

bool isEatable(const string name, int sweetness, float weight)
{
    cout << name << " is eatable? " << ((sweetness > 3 && weight > 2.f) ? "yes" : "no") << endl;
    return (sweetness > 3 && weight > 2.f);
}

#endif // FUNCTIONBASEDCODE_H
