#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;

void swap_in(int *a, int *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int main()
{
    int m = 2112340000, n = 2100001234;
    swap_in(&m, &n);

    cout << m << endl;
    cout << n << endl;

    return 0;
}