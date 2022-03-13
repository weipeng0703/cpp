#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
using namespace std; 

#include<iostream>
using namespace std;
 
#include<iostream>
using namespace std;
class A{
public:
    int _a;
};
class B :virtual public A
{
public:
    int _b;
};
class C :virtual public A
{
public:
    int _c;
};
class D :public B, public C
{
public:
    int _d;
};
//菱形继承和菱形虚继承的对象模型
int main()
{
    D d;
    d.B::_a = 1;
    d.C::_a = 2;
    d._b = 3;
    d._c = 4;
    d._d = 5;
    cout << sizeof(D) << endl;
    return 0;
}