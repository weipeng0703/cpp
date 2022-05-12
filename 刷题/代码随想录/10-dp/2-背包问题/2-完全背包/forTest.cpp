/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-12 10:15:21
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-12 10:28:29
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
// #include<priority_queue>
using namespace std; 

// 19题
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.size() == 0) return 0;
        vector<int> dp(amount + 1, 0);      // dp[j]表示凑成目标j元有几种方式
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) dp[j] += dp[j - coins[i]];
        }
        return dp[amount];
    }
};

int change_right(int amount, vector<int>& coins) {
    if (coins.size() == 0) return 0;
    vector<int> dp(amount + 1, 0);      // dp[j]表示凑成目标j元有几种方式
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) dp[j] += dp[j - coins[i]];
    }
    // return dp[amount];
    for (int ele : dp) {
        cout << "dp_right数组中的元素为" << ele << endl;
    }
}

int change_wrong(int amount, vector<int>& coins) {
    if (coins.size() == 0) return 0;
    vector<int> dp(amount + 1, 0);      // dp[j]表示凑成目标j元有几种方式
    dp[0] = 1;
    for (int i = 0; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0) dp[i] += dp[i - coins[j]];
    }
    }
    // return dp[amount];
    for (int ele : dp) {
        cout << "dp_wrong数组中的元素为" << ele << endl;
    }
}

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    // change_right(amount, coins);
    change_wrong(amount, coins);        // 结果中存在重复的答案
    // cout << "共有 " << ans << " 种兑换方式" << endl;
    return 0;
}