#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

// 显示菜单界面
void showMenu()
{   cout << "*************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "*************************" << endl;

}
// 设计联系人结构体
struct Person
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Add;
};


// 设计通讯录结构体
struct AddressBooks
{
    struct Person personArray[MAX];
    int m_Size;

};

void AddPerson(AddressBooks * abs)
{
    // 判断通讯录是否满
    if(abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        // 添加具体联系人

        // 姓名
        string name;
        cout << "请输入联系人姓名：" << endl;
        cin >> name;
        abs -> personArray[abs -> m_Size].m_Name = name;

        // 性别
        cout << "请输入联系人性别：" << endl;
        cout << "1 --- 男性" << endl;
        cout << "2 --- 女性" << endl;
        int sex = 0;
        
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
            abs -> personArray[abs -> m_Size].m_Sex = sex;
            break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }

        // 年龄
        cout << "请输入联系人年龄:" << endl;
        int age = 0;
        cin >> age;

        abs -> personArray[abs -> m_Size].m_Age = age;
        
        // 联系电话
        cout << "请输入联系人电话:" << endl;
        string phone;
        cin >> phone;

        abs -> personArray[abs -> m_Size].m_Phone = phone;

        // 家庭住址
        cout << "请输入联系人住址:" << endl;
        string add;
        cin >> add;

        abs -> personArray[abs -> m_Size].m_Add = add;

        // 更新通讯录人数
        abs -> m_Size++;
        // 提示更新成功
        cout << "联系人添加成功" << endl;

        // 清屏操作
        system("pause");
        system("cls");
    }
    
}

// 显示所有联系人
void ShowPerson(AddressBooks * abs)
{
    // 判断通讯录中人数是否为0
    if (abs -> m_Size == 0)
    {
        cout << "当前记录为空，请添加联系人信息" << endl;
    }
    else
    {
        for (int i = 0; i < abs -> m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t"
            << " 性别：" << (abs->personArray[i].m_Sex == 1? "男":"女") << "\t"
            << " 年龄：" << abs->personArray[i].m_Age << "\t"
            << " 电话：" << abs->personArray[i].m_Phone << "\t"
            << " 住址：" << abs->personArray[i].m_Add << endl;
        }   
    }
    system("pause");
    system("cls"); 
}

// 检测联系人是否存在，若存在，返回其具体位置，否则返回-1
int IsExist(AddressBooks * abs, string name)
{
    for (int i = 0; i < abs -> m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
    
}

// 删除联系人
void DeletePerson(AddressBooks * abs)
{
    cout << "请输入您想删除的联系人的姓名:" << endl;
    string name;
    cin >> name;

    int flag = IsExist(abs, name);

    if (flag == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        for (int i = flag; i < abs -> m_Size; i++)
        {
            // 数据前移
            abs -> personArray[i] = abs -> personArray[i+1];
            abs -> m_Size--;
            cout << "删除联系人成功！" << endl;
        }
        
    }

    system("pause");
    system("cls");
}

// 查找联系人
void FindPerson(AddressBooks * abs)
{
    cout << "请输入您想查找的联系人的姓名:" << endl;
    string name;
    cin >> name;

    int flag = IsExist(abs, name);

    if (flag == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        cout << "姓名：" << abs->personArray[flag].m_Name << "\t"
            << " 性别：" << (abs->personArray[flag].m_Sex == 1? "男":"女") << "\t"
            << " 年龄：" << abs->personArray[flag].m_Age << "\t"
            << " 电话：" << abs->personArray[flag].m_Phone << "\t"
            << " 住址：" << abs->personArray[flag].m_Add << endl;
        
    }

    system("pause");
    system("cls");
}

// 修改联系人
void ModifyPerson(AddressBooks * abs)
{
    cout << "请输入您想修改的联系人的姓名:" << endl;
    string name;
    cin >> name;

    int flag = IsExist(abs, name);

    if (flag == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        // 姓名
        string name;
        cout << "请重新输入姓名：" << endl;
        cin >> name;
        abs -> personArray[flag].m_Name = name;

        // 性别
        cout << "请重新输入性别：" << endl;
        cout << "1 --- 男性" << endl;
        cout << "2 --- 女性" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;

            if (sex == 1 || sex == 2)
                {
                    abs -> personArray[flag].m_Sex = sex;
                    break;
                }
            
            cout << "输入错误，请重新输入：" << endl;

        }

        // 年龄
        cout << "请重新输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs -> personArray[flag].m_Age = age;

        // 电话
        cout << "请重新输入电话：" << endl;
        string phone;
        cin >> phone;
        abs -> personArray[flag].m_Phone = phone;

        // 住址
        cout << "请重新输入住址：" << endl;
        string add;
        cin >> add;
        abs -> personArray[flag].m_Add = add;

        cout << "修改成功" << endl;
        
    }

    system("pause");
    system("cls");

}

// 清空联系人
void ClearAllPerson(AddressBooks * abs)
{
    cout << "！！！该行为危险，将清空所有联系人！！！\n确定的话请再按 6 ！" << endl;

    int flag =0;
    cin >> flag;

    if (flag == 6)
    {
        // 将当前记录的联系人数量置为0，做一个逻辑上的清空
        abs -> m_Size = 0;   
        cout << "通讯录已清空！" << endl;

        system("pause");
        system("cls");
    }
    else
    {
        cout << "将退回主界面！" << endl;

        system("pause");
        system("cls");
    }
    
    
}

int main()
{
    // 创建通讯录结构体变量
    struct AddressBooks abs;
    // 初始化通讯录中当前人员个数
    abs.m_Size = 0;

    int select = 0;   // 创建用户选择输入的变量

    while (true)
    {
        // 菜单调用
    showMenu();

    cin >> select;

    switch (select)
        {
        case 1:   // 1.添加联系人
            AddPerson(&abs);   // 利用地址传递可以修饰实参
            break;
        case 2:   // 2.显示联系人
            ShowPerson(&abs);
            break;
        case 3:   // 3.删除联系人
            DeletePerson(&abs);
            break;
        case 4:   // 4.查找联系人
            FindPerson(&abs);
            break;
        case 5:   // 5.修改联系人
            ModifyPerson(&abs);
            break;
        case 6:   // 6.清空联系人
            ClearAllPerson(&abs);
            break;
        case 0:   // 7.退出通讯录
            cout << "欢迎下次使用！" << endl;

            return 0;
            break;
        }
    }
}
    
    