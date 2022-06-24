/*
功能描述：
    栈容器常用的对外接口
构造函数：
    queue<T> que; //queue采用模板类实现，queue对象的默认构造形式
    queue(const queue &que); //拷贝构造函数
赋值操作：
    queue& operator=(const queue &que); //重载等号操作符
数据存取：
    push(elem); //往队尾添加元素
    pop(); //从队头移除第一个元素
    back(); //返回最后一个元素
    front(); //返回第一个元素
大小操作：
    empty(); //判断堆栈是否为空
    size(); //返回栈的大小
*/

#include<iostream>
#include<queue>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;

    }
    string m_Name;
    int m_Age; 



};
void test1()
{
    // 创建队列
    queue<Person> q;

    // 准备数据
    Person p1("孙悟空",1000);
    Person p2("猪八戒",2000);
    Person p3("沙僧",3000);
    Person p4("唐僧",4000);

    // 向队列中添加元素
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    // 队列不提供迭代器，所以不支持随机访问
    while (!q.empty())
    {
        // 输出队头元素
        cout << "队头元素——姓名为：" << q.front().m_Name << " 年龄为：" << q.front().m_Age << endl;
        cout << "队尾元素——姓名为：" << q.back().m_Name << " 年龄为：" << q.back().m_Age << endl;

        // 弹出队头元素
        q.pop();
    }
    cout << "队列大小为：" << q.size() << endl;

}

int main()
{
    test1();

    return 0;
}