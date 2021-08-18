/*
案例描述：

学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

最终打印出老师数据以及老师所带的学生数据。

*/
#include<iostream>
#include<string>
#include<typeinfo>
#include<ctime>
using namespace std;

// 定义学生结构体
struct student
{
    string sname;
    int score;
};

// 定义老师结构体
struct teacher
{
    string tname;
    struct student sArray[5];
};

// 给老师和学生赋值的函数
void allocateSpace(struct teacher tArray[], int len)
{
    string nameSeed = "ABCDE";

    // 给老师赋值
    for (int i = 0; i < len; i++)
    {
        tArray[i].tname = "Teacher_";
        tArray[i].tname += nameSeed[i];

        // 通过循环给每名老师所带的学生赋值
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].sname = "Student_" ;
            tArray[i].sArray[j].sname += nameSeed[j];

            int random = rand() % 61 + 40;   // 40~100
            tArray[i].sArray[j].score = random;
        }
        
    }
    
}

// 打印所有信息
void printInfo(struct teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名为：" << tArray[i].tname << endl;  

        for (int j = 0; j < 5; j++)
        {
            cout << "\t该老师负责的第" << j+1 <<  "个学生姓名为：" << tArray[i].sArray[j].sname << ",该学生的成绩为：" << tArray[i].sArray[j].score << endl; 
        }
             
    }
    
}

int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));

    struct teacher tArray[3];

    int len = sizeof(tArray) / sizeof(tArray[0]);
    // 给老师和学生信息赋值
    allocateSpace(tArray, len);

    // 打印老师与学生信息
    printInfo(tArray, len);

    return 0;
}
