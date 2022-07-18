/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-18 09:42:16
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-18 10:16:48
 */
# include<vector> 
# include<algorithm>
# include<unordered_map>
# include<string>
# include<stack>
// # include<priority_queue>
# include<iostream>
# include<thread>
#include<windows.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class B;
class A {
public:
    A() {cout << "A()" << endl;}
    ~A() {cout << "~A()" << endl;}
    void funcA () {
        cout << "非常好用的方法" << endl;
    }
    weak_ptr<B> _ptrb;
};
class B {
public:
    B() {cout << "B()" << endl;}
    ~B() {cout << "~B()" << endl;}
    void funcB () {
        // _ptra->funcA(); 
        shared_ptr<A> ps = _ptra.lock();    // 提升方法
        if (ps != nullptr) ps->funcA();
    }
    weak_ptr<A> _ptra;
};
int main() {

    shared_ptr<A> pa(new A());
    shared_ptr<B> pb(new B());

    pa->_ptrb = pb;
    pb->_ptra = pa;

    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;
    pb->funcB();
    return 0;
}