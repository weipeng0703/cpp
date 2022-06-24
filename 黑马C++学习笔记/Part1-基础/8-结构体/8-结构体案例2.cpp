/*
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。

通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。

五名英雄信息如下：

		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},

*/
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct Hero
{
    string name;
    int age;
    string sex;
};

void bubblesort(struct Hero array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (array[j].age > array[j+1].age)
            {
                struct Hero temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
            
        }
        
    }
    
}

void PrintArrayInfo(struct Hero array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "第" << i+1 << "个英雄为" << array[i].name << ",其年龄为" << array[i].age  << ",其性别为" << array[i].sex << endl;
    }

}

int main()
{
    struct Hero array[5]=
    {
        {"刘备",23,"男"},
	    {"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"} 
    };

    int len = sizeof(array) / sizeof(array[0]);

    cout << "排序前：" << endl;
    PrintArrayInfo(array, len);


    bubblesort(array, len);
    
    cout << "排序后：" << endl;
    PrintArrayInfo(array, len);

    return 0;
}