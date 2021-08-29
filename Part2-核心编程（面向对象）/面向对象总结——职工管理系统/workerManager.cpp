// 将构造函数和析构函数空实现补全

#include"workerManager.h"
#include<fstream>


WorkerManager::WorkerManager()
{
    // 1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        cout << "文件不存在！" << endl;

        // 初始化记录人数
        this->m_EmpNum = 0;
        // 初始化数组指针
        this->m_EmpArray = NULL;
        // 初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 2.文件存在，数据为空
    char ch;
    ifs >> ch;
    if (!ifs.eof())
    {
        cout << "文件为空！" << endl;

        // 初始化记录人数
        this->m_EmpNum = 0;
        // 初始化数组指针
        this->m_EmpArray = NULL;
        // 初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 3.文件存在且有记录

    int num = this->get_EmpNum();
    cout << "职工人数为" << num << endl;
    this->m_EmpNum = num;

    // 开辟空间
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    // 将文件中的数据，存到数组中
    this->init_Emp();

    // 测试代码
    // for (int i = 0; i < this->m_EmpNum; i++)
    // {
    //     cout << "职工编号：" << this->m_EmpArray[i]->m_ID  
    //     << "\t职工姓名：" << this->m_EmpArray[i]->m_Name 
    //     << "\t职工岗位：" << this->m_EmpArray[i]->m_DeptID << endl;
    // }
    
    
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i];
            }
            
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
        
    }
    


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

        // 更新职工不为空标志
        this->m_FileIsEmpty = false;

        // 提示
        cout << "成功添加" << addNumber << "名新职工！" << endl;
        
        // 保存数据到文件中
        this->save();
    }
    else
    {
        cout << "输入数据有误" << endl;
    }

    // 按任意键后清屏回到上级目录
    system("pause");
    system("cls");
    
    

}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < i<this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_ID << " " 
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptID << endl;
    }
    
    ofs.close();

}


int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dID;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dID)
    {
        num++;
    }
    
    return num;



}


void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dID;

    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> dID)
    {
        Worker * worker = NULL;

        if (dID == 1)
        {
            worker = new Employee(id, name, dID);
        
        }
        else if (dID == 2)
        {
            worker = new Manager(id, name, dID);
        
        }
        else if (dID == 3)
        {
            worker = new Boss(id, name, dID);
        
        }
        this->m_EmpArray[index] = worker;
        index++;
        
        
    }
    
    // 关闭文件
    ifs.close();



}


void WorkerManager::Show_Emp()
{
    // 判断文件是否为空
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            // 利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();

        }
        
    }
    system("pause");
    system("cls");
    


}


void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        // 按照编号使删除职工
        cout << "请输入想要删除的员工编号：" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1)   // 说明职工存在，删除该位置上的职工
        {
            // 数据前移
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;

            // 同步更新到文件中
            this->save();
            
            cout << "删除职工成功！" << endl;
        }
        else
        {
            cout << "删除失败，未找到该员工！" << endl;
        }
        
        system("pause");
        system("cls");
    
    }

}


int WorkerManager::IsExist(int id)
{
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_ID == id)
        {
            index = i;

            break;
        }
        
    }

    return index;
    
}

void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入要修改的职工的编号：" << endl;
        int id = 0;
        cin >> id;

        int ret = this->IsExist(id);

        if (ret != -1)
        {
            // 查到编号为id的职工

            delete this->m_EmpArray[ret];

            int newID = 0;
            string newName = "";
            int newDepID = 0;

            cout << "查找到" << id << "号职工，请输入新的职工号：" << endl;
            cin >> newID;

            cout << "请输入新的姓名：" << endl;
            cin >> newName;

            cout << "请输入新的岗位：" << endl;
            cout << "1.普通职员" << endl;
            cout << "2.部门经理" << endl;
            cout << "3.老板" << endl;
            cin >> newDepID;

            Worker * worker = NULL;

            switch (newDepID)
            {
            case 1:
                worker = new Employee(newID, newName, newDepID);
                break;
            case 2:
                worker = new Manager(newID, newName, newDepID);
                break;
            case 3:
                worker = new Boss(newID, newName, newDepID);
                break;
            
            default:
                break;
            }

            // 更新数据到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功！" << endl;

            // 将数据保存到文件中
            this->save();

        }
        else
        {
            cout << "修改失败，查无此人！" << endl;
        }
        
        
    }
    system("pause");
    system("cls");

}

void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl; 
    }
    else
    {
        cout << "请输入查找方式：" << endl;
        cout << "1.按照职工编号查找" << endl;
        cout << "2.按照职工姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            // 按照编号查找
            int id = 0;
            cout << "请输入员工编号：" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "查找成功，该职工信息如下：" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查无此人！" << endl;
            }
            
            
        }
        else if (select == 2)
        {
            string name = "";
            cout << "请输入员工姓名：" << endl;
            cin >> name;

            // 加入一个是否查到的标志
            bool flag = true;   // 默认未找到

            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功，该职工信息如下：" << endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
                
            }
            if (flag == false)
            {
                cout << "查找失败，查无此人！" << endl;
            }
            
            
        }
        else
        {
            cout << "输入有误，请重新输入！" << endl;
        }
                
    }
    system("pause");
    system("cls");
}


void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
        {
            cout << "文件不存在或记录为空！" << endl; 
            system("pause");
            system("cls");
        } 
    else
    {
        cout << "请选择排序方式：" << endl;
        cout << "1.按照职工号进行升序" << endl;
        cout << "2.按照职工号进行降序" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < this->m_EmpNum; i++)
        {
            int minOrMax = i;  // 声明最小值或最大值下标
            for (int j = i+1; j < this->m_EmpNum; j++)
            {
                if (select == 1)   // 升序
                {
                    if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;

                    }
                
                }
                else if (select == 2)   // 降序
                {
                    if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
                    {
                        minOrMax = j;
                    }
                }
    
            } 
            // 判断一开始认定的 最大值或最小值 是不是计算的最大值或最小值，如果不是，交换数据
            if(i != minOrMax)    // 不知道为什么这地方一直报错
            {
            Worker * temp = this->m_EmpArray[i];
            this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
            this->m_EmpArray[minOrMax] = temp;
            }  
        } 
        cout << "排序成功，排序后的结果为：" << endl;
        this->save();
        this->Show_Emp(); 
    }
}

void WorkerManager::ClearAll_File()
{
    cout << "确定执行清空操作？" << endl;
    cout << "1.确定" << endl;
    cout << "2.返回上一级" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);   // 删除文件后重新操作
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            // 删除堆区每个职工对象
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }
            // 删除堆区数组指针
            delete [] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
            
        }
        cout << "清空成功！" << endl;
        
    }
    system("pause");
    system("cls");

}