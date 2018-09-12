#ifndef STLVECTOR_H
#define STLVECTOR_H

// vector를 쓰기위해서는 <vector>를 인클루드 해야 한다.
#include <vector>
#include <iostream>

// vector는 배열을 쉽게 쓸수 있게 해주는 C++ 표준 라이브러리다. (STL)
// vector는 배열의 크기를 조절할 수 있고 메모리 관리도
// 자동으로 처리하므로 기본 배열을 쓰는 것보다 쓰기 쉽고 안전하다.
void vectorPractice()
{
    // 비어있는 int-type vector 생성
    std::vector<int> integersA;
    // 기본 배열 길이를 5로 설정
    std::vector<int> integersB(5);

    // 배열 사이즈 확인
    std::cout << "check size A=" << integersA.size() << std::endl;
    std::cout << "check size B=" << integersB.size() << std::endl;

    // 배열 사이즈 변경
    integersA.resize(10);
    std::cout << "after resizing: size A=" << integersA.size() << std::endl;

    // 배열의 모든 원소 없애기
    integersA.clear();
    std::cout << "after clear: size A=" << integersA.size() << std::endl;

    // 배열에 원소 추가하기
    for(int i=0; i<10; i++)
        integersA.push_back(i*i);

    // 배열 원소 확인하기
    std::cout << "vector values:";
    for(int i=0; i<integersA.size(); i++)
        std::cout << " (" << i << ") " << integersA[i];
    std::cout << std::endl;

    // C++11 이상을 쓰는 경우 이런것도 가능하다.
    // 단 몇번째 원소인지 명시적으로 확인할 수는 없다.
    std::cout << "vector values: ";
    for(int elem: integersA)
        std::cout << elem << " ";
    std::cout << std::endl;
}

#endif // STLVECTOR_H
