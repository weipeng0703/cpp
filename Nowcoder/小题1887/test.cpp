#include<iostream>
using namespace std;



int main()
{
    char a[2][2] = {{'a','b'},{'c','d'}};
    char (*p)[2] = a;
    cout<<*(*(p+1));
    p++;
    cout<<*(*p+1)<<endl;

    return 0;
}