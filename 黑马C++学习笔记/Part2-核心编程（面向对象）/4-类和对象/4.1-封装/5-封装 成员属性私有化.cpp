/*
**优点1：**将所有成员属性设置为私有，可以自己控制读写权限

**优点2：**对于写权限，我们可以检测数据的有效性
*/
#include<iostream>
#include<string>
using namespace std;

/*
**优点1：**将所有成员属性设置为私有，可以自己控制读写权限
class Person
{
public:
    // 设置姓名
    void SetName (string name)
    {
        m_name = name;
    }
    // 获取姓名
    string GetName()
    {
        return m_name;
    }
    // 获取年龄
    int GetAge()
    {
        m_age = 0;   // 初始化后，只让有需求的人看到年龄而不可随意修改——只读
        return m_age;
    }
    // 设置情人  只写
    void SetLover(string lover)
    {
        m_lover = lover;
    }


private:
    string m_name;      // 可读可写
    int m_age;          // 只读    
    string m_lover;     // 只写

};

int main()
{
    Person p1;

    p1.SetName("张三");
    cout << "姓名为：" << p1.GetName() << endl;

    cout << "年龄为：" << p1.GetAge() << endl;
    
    p1.SetLover("李四");
    // cout << "年龄为：" << p1.GetLover() << endl;

    return 0;
}
*/

// **优点2：**对于写权限，我们可以检测数据的有效性
class Person
{
public:
    // 设置姓名
    void SetName (string name)
    {
        m_name = name;
    }
    // 获取姓名
    string GetName()
    {
        return m_name;
    }

    // 设置年龄,将年龄改为可读可写（若修改，年龄需在0~200）
    void SetAge(int age)
    {
        if (age < 0 || age > 200)
        {
            age = 0;
            cout << "输入有误" << endl;
            return;
        }
        else
        {
            m_age = age;
        }
        
    }

    // 获取年龄   
    int GetAge()
    {
        // m_age = 0;   // 初始化后，只让有需求的人看到年龄而不可随意修改——只读
        return m_age;
    }
    // 设置情人  只写
    void SetLover(string lover)
    {
        m_lover = lover;
    }


private:
    string m_name;      // 可读可写
    int m_age;          // 只读    
    string m_lover;     // 只写

};

int main()
{
    Person p1;

    p1.SetName("张三");
    cout << "姓名为：" << p1.GetName() << endl;

    p1.SetAge(50);
    cout << "年龄为：" << p1.GetAge() << endl;
    
    p1.SetLover("李四");
    // cout << "年龄为：" << p1.GetLover() << endl;

    return 0;
}