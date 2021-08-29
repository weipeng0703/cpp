// 将构造函数和析构函数空实现补全

#include"workerManager.h"

WorkerManager::WorkerManager()
{
    // 初始化属性
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;

}

WorkerManager::~WorkerManager()
{



}

void WorkerManager::Show_Menu()
{
    cout << "----------------------------------" << endl;
    cout << "-------欢迎使用职工管理系统-------" << endl;
    cout << "----------0.退出管理程序----------" << endl;
    cout << "----------1.增加职工信息----------" << endl;
    cout << "----------2.显示职工信息----------" << endl;
    cout << "----------3.删除离职员工----------" << endl;
    cout << "----------4.修改职工信息----------" << endl;
    cout << "----------5.查找职工信息----------" << endl;
    cout << "----------6.按照编号排序----------" << endl;
    cout << "----------7.清空所有信息----------" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;
}


void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);  // 退出程序
}

void WorkerManager::Add_Emp()
{
    cout << "请输入添加职工的数量:" << endl;

    int addNumber = 0;  // 保存用户输入的数量

    cin >> addNumber;

    if (addNumber > 0)
    {
        // 计算添加新空间的大小
        int newSize = this->m_EmpNum + addNumber; // 原来记录的人数+新增的人数

        // 开辟新空间
        Worker ** newspace= new Worker*[newSize];

        // 将原来空间下的数据拷贝到新空间
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newspace[i] = this->m_EmpArray[i];
            }
            
        }

        // 添加新数据
        for (int i = 0; i < addNumber; i++)
        {
            int id;        // 编号
            string name;   // 姓名
            int dID;       // 部门选项

            cout << "请输入第" << i+1 << "个新职工的编号：" << endl;
            cin >> id;

            cout << "请输入第" << i+1 << "个新职工的姓名：" << endl;
            cin >> name;

            cout << "请选择该新职工的岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.部门经理" << endl;
            cout << "3.老板" << endl;
            cin >> dID;


            Worker * worker = NULL;

            switch (dID)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            
            default:
                break;
            }

            // 将创建的职工指针，保存到数组中
            newspace[this->m_EmpNum + i] = worker;

        }

        // 释放原有空间
        delete[] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newspace;

        // 更新新的职工人数
        this->m_EmpNum = newSize;

        // 提示
        cout << "成功添加" << addNumber << "名新职工！" << endl;
        
        
    }
    else
    {
        cout << "输入数据有误" << endl;
    }

    // 按任意键后清屏回到上级目录
    system("pause");
    system("cls");
    
    

}