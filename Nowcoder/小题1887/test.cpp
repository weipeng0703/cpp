#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;

int main(){
    static char a[3];
    scanf("%s",a);

    printf("%d,%d",a[1],a[2]);

    return 0;
}
