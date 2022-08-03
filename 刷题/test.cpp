/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 09:17:15
 * @LastEditors: weipeng
 * @LastEditTime: 2022-08-02 22:33:03
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<memory>
#include <time.h>
#include<unordered_map>
#include<queue>
using namespace std;

/*
小A和小B都是搬砖人，因为各自的身体素质不同，所以他们为自己制定了不同的小目标。
小A可以一次搬a1块砖，但是每搬一次就要休息b1分钟，他的目标是一天搬c1块砖;
同样的，小B可以一次搬a2块砖，但是每搬一次就要休息b2分钟，他的目标是一天搬c2块砖。

每个人情况不同，只要完成自己的目标就好，已知某天小A和小B同时开始搬砖，请问他们谁先完成自己的目标？
如果是小A则输出‘A’，如果是小B则输出‘B’，如果两个人同时完成，则输出‘A&B’。

输入描述
第一行是一个整数T，表示数据组数（1≤T≤100）
接下来T行，每行有六个正整数a1,b1,c1,a2,b2,c2,含义如题所示。(a1,b1,c1,a2,b2,c2<=10^9)

输出描述
输出包含T行，每行一个字符串如题所示。

样例输入
2
7 9 19 9 1 89
7 9 95 4 5 9
样例输出
B
B
*/
class B;
class A {
public:
    A() {cout << "A()" << endl;}
    ~A() {cout << "~A()" << endl;}
    shared_ptr<B> _ptrb;
};
class B {
public:
    B() {cout << "B()" << endl;}
    ~B() {cout << "~B()" << endl;}
    shared_ptr<A> _ptra;
};
int main() {

    shared_ptr<A> pa(new A());
    shared_ptr<B> pb(new B());

    pa->_ptrb = pb;
    pb->_ptra = pa;

    cout << pa.use_count() << endl;		// 2
    cout << pb.use_count() << endl;		// 2
    return 0;
}