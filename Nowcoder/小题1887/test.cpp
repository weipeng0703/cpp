#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;

class HasPtr
{
private:
    std::string *ps_;
public:
    explicit HasPtr(const std::string &s) : ps_(new std::string(s)) {};
    ~HasPtr() {delete ps_;}

};

int main()
{
    HasPtr hp1 = HasPtr("cwp");

    HasPtr hp2 = hp1;
}  
    
              

  


