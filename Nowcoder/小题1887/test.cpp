/*
 * @Descripttion: My project
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-01-11 20:11:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-07 16:50:56
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
#include <memory>
using namespace std; 

bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int i = 1; i * 2 <= n; i++)
        {
            if (n % i == 0) {
                bool flag = true;
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j - i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }

int main() {

    string s = "aaaa";
    bool flag = repeatedSubstringPattern(s);
    if (flag) cout << "1" << endl;
    else cout << "0" << endl;
    return 0;
}
