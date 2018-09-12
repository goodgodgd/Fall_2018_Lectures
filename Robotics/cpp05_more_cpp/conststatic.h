#ifndef CONSTSTATIC_H
#define CONSTSTATIC_H

#include <iostream>
using namespace std;

void count()
{
    // 함수 내부에 선언된 static 변수는 함수가 끝나도 소멸되지 않고
    // 함수 내부에서 변경된 값은 다음 호출시 그대로 유지된다.
    static int value=0;
    cout << "count: " << ++value << endl;
}

class Student
{
public:
    Student()
    {
        cout << ++numStudent << "'th student is created." << endl;
    }

    static void jobToDo()
    {
        cout << "job of student: study ha~~~~~~~~rd" << endl;
    }

    static int numStudent;
};

int Student::numStudent = 0;


void practiceConstStatic()
{
    cout << endl << "===== practiceConstStatic =====" << endl;
    count();
    count();
    count();

    Student kim;
    Student* lee = new Student;
}


#endif // CONSTSTATIC_H
