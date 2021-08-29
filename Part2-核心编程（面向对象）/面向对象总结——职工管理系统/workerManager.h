// 设计管理类
// 管理类负责的内容：
// 1.与用户的沟通菜单页面
// 2.对职工增删改查的操作
// 3.与文件读写的交互
#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empFile.txt"
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

    // 保存文件
    void save();

    // 判断文件是否为空的标志
    bool m_FileIsEmpty;

    // 统计人数
    int get_EmpNum();

    // 初始化员工
    void init_Emp();

    // 显示职工
    void Show_Emp();

    // 删除职工
    void Del_Emp();

    // 判断职工是否存在:若存在返回职工所在数组中的位置，否则返回-1
    int IsExist(int id);

    // 修改职工
    void Mod_Emp();

    // 查找职工
    void Find_Emp();

    // 按照职工编号进行排序操作
    void Sort_Emp();

    // 清空操作
    void ClearAll_File();

    // 析构函数
    ~WorkerManager();


};