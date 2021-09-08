/*
功能描述：
    查找：查找指定字符串是否存在
    替换：在指定的位置替换字符串

函数原型：
    int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
    int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
    int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
    int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
    int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
    int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
    int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
    int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
    string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
    string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
*/

#include<iostream>
#include<string>
using namespace std;

// 查找
void test1()
{
    string str1 = "abcdefg";

    int pos = str1.find("de");

    int pos1 = str1.find("df");

    cout << pos << endl;

    cout << pos1 << endl;   // 没有的话返回 -1 

    if (pos == -1)
    {
        cout << "未找到该字符串" << endl;
    }
    else
    {
        cout << "找到字符串，且pos=" << pos << endl;
    }

    // rfind
    pos = str1.rfind("de");

    cout << pos << endl;

    // rfind与find的区别，前者是从右往左找，后者是从左往右找
    
    
}

// 替换
void test2()
{
    string str1 = "abcdefg";
    str1.replace(1,3,"1111");   // 替换后的内容只看后面""里的东西，不需要管前面替换的个数
    cout << str1 << endl;

}


int main()
{
    test1();
    test2();

    return 0;
}