#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std; 


int main()
{
    char a[2][3] = {{'a', 'b', 'c'}, {'1', '\0', '2'}};
    printf("%s", a[0]);
    // cout << endl;
    cout << a << endl;
    cout << a[0] << endl;
    cout << a[1] << endl;
    return 0;
}