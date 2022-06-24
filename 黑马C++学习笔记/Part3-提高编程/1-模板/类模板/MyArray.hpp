#pragma once
#include<string>
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
    // 有参构造
    MyArray(int capacity)
    {
        // cout << "有参构造的调用" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];

    }

    ~MyArray()
    {
        
        if (this->pAddress != NULL)
        {
            // cout << "析构函数的调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
        
    }

    // 拷贝构造
    MyArray(const MyArray& arr)
    {   
        // cout << "拷贝构造的调用" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress;   // 会造成内存重复释放,所以需要提供深拷贝

        // 深拷贝
        this->pAddress = new T[arr.m_Capacity];
        
        // 将之前arr中的数据拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // operator= 防止浅拷贝问题
    MyArray& operator = (const MyArray& arr)
    {
        // cout << "operator=的调用" << endl;
        // 先判断原来堆区是否有数据,如果有要先释放干净
        if (this->pAddress != NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[m_Capacity];

        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        
        return *this;
    }

    // 尾插法进行数据的插入
    void Push_Back(const T & val)
    {
        // 判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        
        this->pAddress[this->m_Size] = val;     // 在数组末尾插入数据
        this->m_Size++;    // 更新数组大小

    }

    // 尾删进行数据的删除
    void Pop_Back()
    {
        // 让用户访问不到数组的最后一个元素即为尾删法(逻辑删除)
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;    // 逻辑删除
    }

    // 通过下标访问数组内的元素   arr[0] = 100
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    // 返回数组的容量
    int GetCapacity()
    {
        return this->m_Capacity;
    }
    
    // 返回数组的大小
    int GetSize()
    {
        return this->m_Size;
    }
       

private:

    T * pAddress;       // 指针指向堆区开辟的真实数组

    int m_Capacity;     // 数组容量:指数组最大能容纳多少东西

    int m_Size;         // 数组大小:当前数组存储了多少东西

};