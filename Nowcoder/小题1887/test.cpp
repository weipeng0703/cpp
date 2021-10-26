#include <stdio.h>
int fun(int a) { 
    int b=0;     
    static  int c=3;
    b++; 
    c++; 
    return (a+b+c);
}

int main( ) {
    int i=0;
    for(;i<3;i++) 
        printf("%d",fun(2));
    return 0; 
}