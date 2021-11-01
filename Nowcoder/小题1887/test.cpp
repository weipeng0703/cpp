#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

int main()
{
 
    int i = 1;
    // cout << i++ << ++i << endl;  // 1,2
    cout << ++i << i++ << endl;     // 2,2   
    printf("%d,%d\n", ++i, ++i);    //3,3
    printf("%d,%d\n", ++i, i++);    //5,3
    printf("%d,%d\n", i++, i++);    //6,5
    printf("%d,%d\n", i++, ++i);    //8,9
    // system("pause");
    return 0;
}