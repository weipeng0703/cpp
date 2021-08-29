// 设计管理类
// 管理类负责的内容：
// 1.与用户的沟通菜单页面
// 2.对职工增删改查的操作
// 3.与文件读写的交互
#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

class WorkerManager
{
public:

    // 构造函数
    WorkerManager();

    // 显示菜单
    void Show_Menu();

    // 退出系统
    void exitSystem();

    // 记录职工人数
    int m_EmpNum;

    // 职工数组的指针
    Worker ** m_EmpArray;

    // 添加职工
    void Add_Emp();

    // 析构函数
    ~WorkerManager();


};