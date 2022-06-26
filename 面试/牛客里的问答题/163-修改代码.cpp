// 题目
/*
有段代码写成了下边这样，如果在只修改一个字符的前提下，使代码输出20个hello?

for(int i = 0; i < 20; i--)
cout << "hello" << endl;
*/

// 解答
/*
for(int i = 0; i + 20; i--)
cout << "hello" << endl;
或
for(int i = 40; i + 20; i--)
cout << "hello" << endl;


*/

#include<iostream>
using namespace std;


int main()
{
    // for(int i = 0; i < 20; i--)
    //     cout << "hello" << endl;

    for(int i = 0; i + 20; i--)
        {
            cout << "hello" << endl;
            cout << -i + 1 << endl;    // 统计hello出现的次数
        }

}