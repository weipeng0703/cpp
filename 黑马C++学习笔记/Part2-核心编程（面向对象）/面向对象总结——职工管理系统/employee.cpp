// 普通员工
#pragma once
#include<iostream>
#include<string>
#include"employee.h"
using namespace std;

// 构造函数
Employee::Employee(int id, string name, int d_ID)
{
    this->m_ID = id;
    this->m_Name = name;
    this->m_DeptID = d_ID;

}

// 显示个人信息
void Employee::showInfo()
{
    cout << "职工编号：" << this->m_ID 
    << "\t职工姓名：" << this->m_Name 
    << "\t岗位：" << this->getDeptName() 
    << "\t岗位职责：完成经理的任务" << endl; 

}

// 获取岗位名称
string Employee::getDeptName()
{
    return string("员工");

}