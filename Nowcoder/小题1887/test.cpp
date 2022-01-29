#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std; 

int Fibonacci(int n) {
    if(n <= 0)
        return 0;
    else if(n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    cout << Fibonacci(50) << endl;

    return 0;
}