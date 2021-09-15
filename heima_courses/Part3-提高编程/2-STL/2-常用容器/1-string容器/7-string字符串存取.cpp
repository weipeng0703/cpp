/*
string中单个字符存取方式有两种

    char& operator[](int n); //通过[]方式取字符
    char& at(int n); //通过at方法获取字符
*/

#include<iostream>
#include<string>
using namespace std;


void test1()
{
    string str = "hello";

    // cout << "str = " << str << endl;  

    // 1.通过[]访问每个字母 

    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << endl;
    }

    // 2.通过at访问每个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << endl;
    }

    // 修改单个字符
    str[0] = 'x';
    cout << "str = " << str << endl;

    str.at(2) = 'x';
    cout << "str = " << str << endl;
     
}


int main()
{
    test1();


    return 0;
}