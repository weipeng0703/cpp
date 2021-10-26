#include <iostream>
using namespace std;

int main() { 
    char *p1="hello";
    char *p2="world";
    char *p3="a piece of cake";
    char *str[]={p1,p2,p3};
    
    printf("%c",*(str[0]+1));

    return 0;
}