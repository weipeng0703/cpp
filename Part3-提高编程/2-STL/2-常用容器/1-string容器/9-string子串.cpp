/*
功能描述：
    从字符串中获取想要的子串
函数原型：
    string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
*/

#include<iostream>
#include<string>
using namespace std;


void test1()
{
    string str = "abcdefg";

    string substr = str.substr(1,3);

    cout << "substr = " << substr << endl;
     
}

void test2()
{
    string email = "hello@sina.com";

    // 从邮件地址中获取用户信息
    int pos = email.find("@");

    string username = email.substr(0,pos);

    cout << "username = " << username << endl;


}


int main()
{
    // test1();
    test2();


    return 0;
}