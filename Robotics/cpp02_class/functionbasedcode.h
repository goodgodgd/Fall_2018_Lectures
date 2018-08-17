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

void functionBasedCode()
{
    cout << endl << "==== Function based code =====" << endl;
    int appleSweetness = 1;
    float appleWeight = 1.f;

    int orangeSweetness = 0;
    float orangeWeight = 0.1f;

    while(!isEatable("apple", appleSweetness, appleWeight))
        ripen("apple", appleSweetness, appleWeight);

    while(!isEatable("orange", orangeSweetness, orangeWeight))
        ripen("orange", orangeSweetness, orangeWeight);
}

#endif // FUNCTIONBASEDCODE_H
