#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;

#include <iostream>
using namespace std;
class A{
  int a1;
protected:
  int a2;
public:
  int a3;
};
class B: public A{
  int b1;
protected:
  int b2;
public:
  int b3;
};
class C:private B{
  int c1;
protected:
  int c2;
public:
  int c3;
};
// int main(){
//   B obb;
//   C obc;
//   cout<<obb.a1;//1
//   cout<<obb.a2;//2
//   cout<<obb.a3;//3
//   cout<<obc.b1;//4
//   cout<<obc.b2;//5
//   cout<<obc.b3;//6
//   cout<<obc.c3;//7
//   return 0;
// }