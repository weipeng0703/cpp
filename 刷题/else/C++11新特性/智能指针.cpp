/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-14 18:37:18
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-15 16:38:15
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

// struct C {
//     std::shared_ptr<C> m_child;
//     std::shared_ptr<C> m_parent;
// };

// int main() {

//     auto parent = std::make_shared<C>();
//     auto child = std::make_shared<C>();

//     // 建立相互引用
//     parent->m_child = child;
//     child->m_parent = parent;

//     parent = nullptr;
//     child = nullptr;
//     return 0;
// }

int main() {

    std::shared_ptr<int> p1(new int(10));
    std::shared_ptr<int> p2(p1);
    cout << "p1 = " << *p2 << endl;     // 10
    cout << "p2 = " << *p2 << endl;     // 10

    cout << p1.use_count() << endl;     // 2
    cout << p2.use_count() << endl;     // 2

    p1.reset();
    cout << "p1 = " << *p2 << endl;     // 10，本应释放内存，但是还有一个指针指向该内存
    cout << "p2 = " << *p2 << endl;     // 10
    cout << p1.use_count() << endl;     // 0
    cout << p2.use_count() << endl;     // 1
    if (p1) {
        cout << "p1不为空" << endl;
    } else cout << "p1为空" << endl;    // 输出

    p2.reset();
    cout << "p1 = " << *p2 << endl;     // 报错，因为两个指针都reset了，该内存被释放了
    cout << "p2 = " << *p2 << endl;     // 报错，因为两个指针都reset了，该内存被释放了
    cout << p2.use_count() << endl;     // 0

    return 0;
}