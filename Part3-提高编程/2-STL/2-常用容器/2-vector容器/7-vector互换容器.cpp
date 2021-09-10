/*
功能描述：
    实现两个容器内元素的互换  
函数原型：
    swap(vec); // 将vec与本身的元素互换
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PrintVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ' ';
    }
    
    cout << endl;


}
// 基本使用
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "交换前v1：" << endl;
    PrintVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    cout << "交换前v2：" << endl;
    PrintVector(v2);
    
    cout << "交换后：" << endl;
    v1.swap(v2);
    PrintVector(v1);
    PrintVector(v2);
}

// 用swap()收缩内存空间
void test2()
{
    vector<int> v;

	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//收缩内存
    // vector<int>(v)为匿名对象特点:当前行执行完后编译器自动回收内存
    // .swap(v) 进行容器交换
	vector<int>(v).swap(v); //匿名对象

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;



}

int main()
{
    test1();
    test2();

    return 0;
}