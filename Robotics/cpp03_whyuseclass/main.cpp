#include "functionbasedcode.h"
#include "objectbasedcode.h"

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

void objectBasedCode()
{
    cout << endl << "==== Object based code =====" << endl;
    // 객체를 사용하여 변수 선언이 줄어들고 변수의 이름이 간단해진다.
    Fruit apple("apple", 1, 1.f);
    Fruit orange("orange", 0, 0.1f);

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
