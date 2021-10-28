#include<iostream>
#include<cstring>
using namespace std;


int main(void)
{
    // char ch[] = "afsg\0dfhs" ;

    char ch[] = "\0" ;
    cout << sizeof(ch) << endl;
    cout << strlen(ch) << endl;

    char ch1 = '\0' ;
    cout << sizeof(ch1) << endl;
    // cout << strlen(ch1) << endl;

    return 0;
}