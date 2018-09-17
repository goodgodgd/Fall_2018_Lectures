#include "functionbasedcode.h"
#include "objectbasedcode.h"

void functionBasedCode()
{
    cout << endl << "==== Function based code =====" << endl;
    float appleSweetness = 1.f;
    float orangeSweetness = 0.5f;

    while(!isEatable("apple", appleSweetness))
        appleSweetness = ripenApple(appleSweetness);

    while(!isEatable("orange", orangeSweetness))
        orangeSweetness = ripenOrange(orangeSweetness);
}

void objectBasedCode()
{
    cout << endl << "==== Object based code =====" << endl;
    // 객체를 사용하여 변수 선언이 줄어들고 변수의 이름이 간단해진다.
    Fruit apple("apple", 1.f, 0.3f);
    Fruit orange("orange", 0.5f, 0.5f);

    // 함수 호출 인자도 줄었다.
    while(!apple.isEatable())
        apple.ripen();

    while(!orange.isEatable())
        orange.ripen();
}

int main()
{
    // 동작은 같지만 구현 방법이 전혀 다른 두 함수
    functionBasedCode();

    objectBasedCode();
}


/* Program output

==== Function based code =====
apple is eatable? no
apple's current sweetness=1.3
apple is eatable? no
apple's current sweetness=1.6
apple is eatable? no
apple's current sweetness=1.9
apple is eatable? no
apple's current sweetness=2.2
apple is eatable? yes
orange is eatable? no
orange's current sweetness=1
orange is eatable? no
orange's current sweetness=1.5
orange is eatable? no
orange's current sweetness=2
orange is eatable? no
orange's current sweetness=2.5
orange is eatable? yes

==== Object based code =====
apple is eatable? no
apple's current sweetness=1.3
apple is eatable? no
apple's current sweetness=1.6
apple is eatable? no
apple's current sweetness=1.9
apple is eatable? no
apple's current sweetness=2.2
apple is eatable? yes
orange is eatable? no
orange's current sweetness=1
orange is eatable? no
orange's current sweetness=1.5
orange is eatable? no
orange's current sweetness=2
orange is eatable? no
orange's current sweetness=2.5
orange is eatable? yes

*/
