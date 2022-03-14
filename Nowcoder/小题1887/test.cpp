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

// class Base { public:  virtual void func() = 0; }; 

class Base {
public:
    virtual void func() = 0; 
};

class Derived : public Base {
public:
    void func() {
        cout << "哈哈" << endl;
    } 
};
int main() {
    Base *b = new Derived();
    b->func(); 
    return 0; 
}
