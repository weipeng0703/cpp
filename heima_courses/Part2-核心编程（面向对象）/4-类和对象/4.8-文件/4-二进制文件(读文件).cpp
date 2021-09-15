/*
二进制方式读文件主要利用流对象调用成员函数read

函数原型：istream& read(char *buffer,int len);

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
*/
#include<iostream>
#include<string>
// 1.包含头文件
#include<fstream> 
using namespace std;

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test1()
{
    // 2.创建流对象
    ifstream ifs;

    // 3.打开文件，判断文件是否打开成功
    ifs.open("Person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }
    

    // 4.读文件
    Person p;
    ifs.read((char *)&p, sizeof(Person));

    // 5.关闭文件
    ifs.close();

    cout << "姓名为" << p.m_Name << endl;
    cout << "年龄为" << p.m_Age << endl;
}

int main()
{
    test1();

    return 0;
}