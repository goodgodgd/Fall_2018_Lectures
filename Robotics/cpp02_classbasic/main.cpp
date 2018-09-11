#include "exampledog.h"

int main()
{
    // 기본 클래스 사용법
    std::cout << "===== Learn class usage =====" << std::endl;
    // 클래스 객체 선언
    ExampleDog dog;
    dog.grow();
    dog.bark();
    dog.grow();
    dog.bark();

    // new를 이용한 클래스 객체 선언 (인자 입력)
    ExampleDog* poodle = new ExampleDog("poodle", 3);
    poodle->grow();
    poodle->bark();
    poodle->grow();
    poodle->bark();
    // delete를 이용한 객체 소멸
    delete poodle;

    return 0;
}
