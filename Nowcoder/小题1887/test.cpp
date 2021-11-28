#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;


int main() {
 int a(1), b(3), c(2);
 
 while (a < b < c)
 {
  ++a;
  --b;
  --c;
 }
 cout << a << " " << b << " " << c << "\n";
 return 0;
}