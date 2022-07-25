/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-27 09:44:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-25 17:08:09
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

#include <iostream>
using namespace std;

#include <stdio.h>

class test {
public:
    test() { cout << "constructor with argument" << endl;}
    ~test() {}
    test(const test& t) { cout << "copy constructor" << endl; }
    test& operator=(const test& e) {
        cout << "assignment operator" << endl;
        return *this;
    }
};
int main() {
    test ort;
    test a(ort);
    test b = ort;
    a = b;
    return 0;
}