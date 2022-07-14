/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-14 18:37:18
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-14 21:06:01
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

struct C {
    std::shared_ptr<C> m_child;
    std::shared_ptr<C> m_parent;
};

int main() {

    auto parent = std::make_shared<C>();
    auto child = std::make_shared<C>();

    // 建立相互引用
    parent->m_child = child;
    child->m_parent = parent;

    parent = nullptr;
    child = nullptr;
    return 0;
}