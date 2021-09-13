/*
案例描述
    公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
    员工信息有: 姓名 工资组成；
    部门分为：策划、美术、研发
    随机给10名员工分配部门和工资
    通过multimap进行信息的插入 key(部门编号) value(员工)
    分部门显示员工信息。

实现步骤
    创建10名员工，放到vector中
    遍历vector容器，取出每个员工，进行随机分组
    分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
    分部门显示员工信息

*/
#include<ctime>
#include<string>
#include<iostream>
#include<map>
#include<vector>
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
using namespace std;


class Worker
{
public:


    string m_Name;
    int m_Salary;

};

void CreateWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_Salary = rand()%10000 + 10000;

        v.push_back(worker);
    }
    



}

void SetGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptId = rand() % 3;   // 0  1  2

        // 部门编号  员工
        m.insert(make_pair(deptId, *it));
    
    }
    
}

void ShowWorker(multimap<int, Worker> &m)
{
    cout << "策划部门的信息：" << endl;
    
    multimap<int, Worker>::iterator pos = m.find(CEHUA);

    int count = m.count(CEHUA); // 统计具体人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << pos->second.m_Name << " 工资为：" << pos->second.m_Salary << endl; 
    }
    
    cout << "-----------------------------------------" << endl;
    cout << "美术部门的信息：" << endl;
    
    multimap<int, Worker>::iterator pos1 = m.find(MEISHU);

    count = m.count(MEISHU); // 统计具体人数
    index = 0;
    for (; pos1 != m.end() && index < count; pos1++, index++)
    {
        cout << pos1->second.m_Name << " 工资为：" << pos1->second.m_Salary << endl; 
    }
    
    cout << "-----------------------------------------" << endl;
    cout << "研发部门的信息：" << endl;
    
    multimap<int, Worker>::iterator pos2 = m.find(YANFA);

    count = m.count(YANFA); // 统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos2++, index++)
    {
        cout << pos2->second.m_Name << " 工资为：" << pos2->second.m_Salary << endl; 
    }

}

int main()
{
    srand((unsigned int)time(NULL));
    vector<Worker> vWorker;
    // 1.创建员工
    CreateWorker(vWorker);

    // 测试
    // for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    // {
    //     cout << (*it).m_Name << " 工资为：" << (*it).m_Salary << endl;
    // }

    // 2.员工分组
    multimap<int, Worker> m;
    SetGroup(vWorker, m);

    // 3.分组显示员工
    ShowWorker(m);   

    return 0;
}