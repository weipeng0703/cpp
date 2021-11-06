#include<iostream>
 using namespace std;

int main()
{
    int a = 0;
    int b=( a = 3 * 5 , a * 4);    

    cout << a << endl;    // 15
    cout << b << endl;    // 60
    return 0;
}