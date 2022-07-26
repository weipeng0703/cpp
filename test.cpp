/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-27 09:44:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-26 19:10:46
 */
# include<vector> 
# include<algorithm>
# include<unordered_map>
# include<string>
# include<stack>
# include<queue>
# include<iostream>
# include<thread>
#include<windows.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

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

class Student {
private:
    int num;
    char *name;
public:
    Student() {
        name = new char(20);
        cout << "Student" << endl;
    };
    ~Student(){
        cout << "~Student " << &name << endl;
        delete name;
        name = NULL;
    };
    //拷贝构造函数
    Student(const Student &s){
        //浅拷贝，当对象的name和传入对象的name指向相同的地址
        name = s.name;
        cout << "浅拷贝 Student" << endl;
        //深拷贝
        //name = new char(20);
        //memcpy(name, s.name, strlen(s.name));
        // cout << "浅拷贝 Student" << endl;
    };
};
int main() {
    {
        // 花括号让s1和s2变成局部对象，方便测试
        Student s1;
        // 复制对象
        Student s2(s1);
    }
    return 0;
}