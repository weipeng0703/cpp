/*
**作用：**将自定义的结构体放入到数组中方便维护

语法：struct 结构体名 数组名[元素个数] = { {} , {} , ... {} }
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    struct Student stuArray[3] = 
    {
        {"张三" , 18 , 100},
        {"李四" , 19 , 80},
        {"王五" , 20 , 90},
    };

    // stuArray[2].name = "赵六";   //后期可以修改结构体变量中的变量信息

    // 访问结构体数组中的数据
    cout << "姓名：" << stuArray[1].name <<" 年龄：" << stuArray[1].age <<" 分数：" << stuArray[1].score << endl;
    
    // 遍历结构体数组中的数据
    for (int i = 0; i < 3; i++)
    {
        cout << "姓名：" << stuArray[i].name <<" 年龄：" << stuArray[i].age <<" 分数：" << stuArray[i].score << endl;
    }
    
    return 0;
}