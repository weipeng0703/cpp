// 老板头文件
#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Boss : public Worker 
{
public:
    // 构造函数
    Boss(int id, string name, int d_ID);

    // 显示个人信息
    virtual void showInfo();   // 纯虚函数

    // 获取岗位名称
    virtual string getDeptName();



};