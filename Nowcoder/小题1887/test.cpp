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
using namespace std;
void (*function)(float);

void One(float one)
{ 
    cout<<"1"<<endl;    
}
void Two(float two)
{ 
    cout<<"2"<<endl; 
}
void Three(float three)
{ 
    cout<<"3"<<endl; 
}
int main() 
{  
    float i=1,j=2,k=3;
   function = One;
   function(i);
   function= Two;
   function(j);
   function = Three;
   function(k);
}