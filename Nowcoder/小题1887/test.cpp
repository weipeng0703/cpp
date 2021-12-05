#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;
#include <stdio.h>

class B{
};
B func(const B& rhs){
  return rhs;
}
int main(int argc, char **argv){
  B b1, b2;
  b2 = func(b1);  //10
}