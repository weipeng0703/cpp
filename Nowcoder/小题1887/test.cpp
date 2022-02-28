#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std; 


#include <iostream>
#include <string>


class Base
{
    public:
        virtual void print()  //虚函数
        {
            cout<<"Base..."<<endl;
        }
};

class Derive : public Base
{
    public:
        void print()           //虽然没有标注virtual,但是因为和基类中的虚函数函数同名，所以默认虚函数
        {
            cout<<"Derive..."<<endl;
        }
};

void display(Base* p)   //复制兼容原则，基类类型的指针也可以指向派生类。
{
    p->print();
}

int main()
{
    Base a;
    Derive b;
    display(&a);  //调用基类的print函数
    display(&b);   //调用派生类的print函数
    return 0;
}

//动态联编，可以定义基类的指针，指向派生类的时候可以调用其中的虚函数进行操作。