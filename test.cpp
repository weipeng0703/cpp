/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-27 09:44:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-30 23:03:44
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
using namespace std;

#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct Person {
    string name;
    int age;
    //初始构造函数
    Person(string p_name, int p_age): name(std::move(p_name)), age(p_age) {
        cout << "I have been constructed" << endl;
    }
    //拷贝构造函数
    Person(const Person& other): name(std::move(other.name)), age(other.age) {
        cout << "I have been copy constructed" << endl;
    }
    //转移构造函数
    Person(Person&& other): name(std::move(other.name)), age(other.age) {
        cout << "I have been moved" << endl;
    }
};
int main() {
    vector<Person> e;
    cout << "emplace_back:" << endl;
    e.emplace_back("Jane", 23); //不用构造类对象
    vector<Person> p;
    cout << "push_back:"<< endl;
    p.push_back(Person("Mike", 36));
    return 0; 
}