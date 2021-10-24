// 题目 编写类String的构造函数、析构函数和赋值函数，已知类String的原型为
#include<iostream>
#include<assert.h>
#include<string>
using namespace std;

class String 
{  
public:  
    String(const char *str = NULL); // 普通构造函数  
    String(const String &other); // 拷贝构造函数  
    ~ String(void); // 析构函数  
    String &operator =(const String &other); // 赋值函数 

private:  

    char *m_data; // 用于保存字符串  
}; 


// 解答
/*
// 普通构造函数
String::String(const char *str = NULL)
{
    if (str == NULL)
    {
        m_data = new char[1];
        assert(m_data != NULL);

        m_data = '\0';
    }

    else
    {
        int len = sizeof(str);

        m_data = new char[len];
        assert(m_data != NULL);

        
        memcpy(m_data, str, len);

    }
}
// 拷贝构造
String::String(const String &other)
{
    assert(this != &other);

    int len = sizeof(other.m_data);

    m_data = new char[len];

    assert(m_data != NULL);

    memcpy(m_data, other.m_data, len);
}
// 析构函数
String::~String(void)
{
    delete[]  m_data;
    m_data = NULL;

}

// 赋值函数
String & String::operator=(const string &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete[] m_data;
    m_data = NULL;

    int len = sizeof(other.m_data);

    m_data = new char[len];
    assert(m_data != NULL);

    memcpy(m_data, other.m_data, len);

    return *this;

    
}
*/

// 知识点
/*

*/