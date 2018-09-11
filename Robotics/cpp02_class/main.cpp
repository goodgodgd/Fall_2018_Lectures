#include "exampledog.h"
#include "functionbasedcode.h"
#include "objectbasedcode.h"

int main()
{
    // 기본 클래스 사용법
    std::cout << "===== Learn class usage =====" << std::endl;
    ExampleDog dog;
    dog.grow();
    dog.bark();
    dog.grow();
    dog.bark();

    ExampleDog poodle("poodle", 3);
    poodle.grow();
    poodle.bark();
    poodle.grow();
    poodle.bark();

    // 동작은 같지만 구현 방법이 전혀 다른 두 함수
    functionBasedCode();

    objectBasedCode();
}
