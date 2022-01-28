/*
如下为类型CMyString的声明，为该类添加赋值运算符函数

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
private:
    char* m_pData;
};
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std; 

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);
private:
    char* m_pData;
};

// 1.经典解法
CMyString& CMyString::operator=(const CMyString& str)
{
    if (this == &str)
    {
        return *this;
    }
    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char(strlen(str.m_pData) + 1);
    strcpy(m_pData, str.m_pData);
    
    return *this;
}