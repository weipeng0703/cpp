/*
C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:

    void ShowClassName()
    {
        cout << "this is class Name" << endl;
    }

    void ShowPersonName()
    {
        // 此处传入的this指针为空 NULL
        // 使用此处的判断语句增强代码的健壮性
        if (this == NULL)
        {
            return;
        }
        
        cout << "this is Person Age:" << this->m_age << endl;
    }

    int m_age;

};

void test1()
{
    Person *p = NULL;

    p->ShowClassName();

    // p->ShowPersonName();

}
int main()
{
    test1();
    // test2();

    return 0;
}