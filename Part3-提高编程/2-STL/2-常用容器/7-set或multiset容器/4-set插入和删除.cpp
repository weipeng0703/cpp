/*
功能描述：
    set容器进行插入数据和删除数据
函数原型：
    insert(elem); //在容器中插入元素。
    clear(); //清除所有元素
    erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
    erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    erase(elem); //删除容器中值为elem的元素。
*/

#include<string>
#include<iostream>
#include<set>
using namespace std;

void PrintSet(set<int> s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;


}
// 插入和删除
void test1()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    PrintSet(s1);

    // 删除
    s1.erase(s1.begin());
    PrintSet(s1);     

    s1.erase(30);
    PrintSet(s1);

    // 清空
    // s1.erase(s1.begin(), s1.end());
    s1.clear();
    PrintSet(s1);
    
}
void test2()
{
    set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;

	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前" << endl;
	PrintSet(s1);
	PrintSet(s2);
	cout << endl;

	cout << "交换后" << endl;
	s1.swap(s2);
	PrintSet(s1);
	PrintSet(s2);

}


int main()
{

    test1();
    // test2();

    return 0;
}