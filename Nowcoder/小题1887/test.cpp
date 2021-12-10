#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;
#include <stdio.h>

int main() {
    int a = 2, b = 1, c = 2;
    if (a < b)
        if (b < 0)
            c = 0;
        else
            c += 1;
    printf("%d", c);
}