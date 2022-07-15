/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-27 09:44:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-14 15:18:29
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

int main() {
    // auto basicLambda = [] {cout << "hello world!" << endl; };
    // basicLambda();

    // auto add = [] (int a, int b) -> int {return a + b;};
    // auto cheng = [] (int a, int b)  {return a * b;};

    // int sum = add(2, 5);
    // int chengyi = cheng(2, 5);

    // cout << sum << endl;
    // cout << chengyi << endl;

    // int x = 10;
    // auto addX = [x] (int a) {return a + x;};

    // auto chengX = [&x] (int a) {return a * x;};

    // cout << addX(2) << endl;
    // cout << chengX(2) << endl;

    // int val = 3;
    // vector<int> ans {1,2,3,4,5,6,7,8,9};
    // int count = std::count_if(ans.begin(), ans.end(), [val] (int x) {return x > val;});
    // cout << count << endl;

    constexpr int getFive() { return 5; };
    int arr[getFive() + 1];

    return 0; 
}