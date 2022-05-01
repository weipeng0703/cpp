/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-01 10:49:57
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-01 14:13:49
 */
/*
力扣134. 加油站
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。
如果存在解，则 保证 它是 唯一 的。
 
示例 1:
    输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
    输出: 3
    解释:
    从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
    开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
    开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
    开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
    开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
    开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
    因此，3 可为起始索引。
示例 2:
    输入: gas = [2,3,4], cost = [3,4,3]
    输出: -1
    解释:
    你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
    我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
    开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
    开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
    你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
    因此，无论怎样，你都不可能绕环路行驶一周。
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
#include<priority_queue>
using namespace std; 

// 1.暴力+剪枝（超时）
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] < cost[i]) continue;     // 剪枝
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size();
            while (rest > 0 && index != i) {        // 模拟以i为起点行驶一圈
                rest += gas[index] - cost[index];
                index = (index + 1) % gas.size();
            }
            // 如果以i为起点跑一圈，且剩余油量>=0，返回该起始位置
            if (rest >= 0 && index == i) return i;
        }
        return -1;
    }
};

// 2.贪心1——全局贪心
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0, min = INT_MAX;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            if (curSum < min) min = curSum;
        }
        if (curSum < 0) return -1;
        if (min >= 0) return 0;
        for (int i = gas.size() - 1; i >= 0; i--) {
            min += gas[i] - cost[i];
            if (min >= 0) return i;
        }
        return -1;
    }
};

// 3.局部贪心
// 首先如果总油量减去总消耗大于等于零那么一定可以跑完一圈，说明 各个站点的加油站 剩油量rest[i] (gas[i] - cost[i]) 相加一定是大于等于零的。
// i从0开始累加rest[i]，和记为curSum，一旦curSum小于零，说明[0, i]区间都不能作为起始位置，起始位置从i+1算起，再从0计算curSum。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0, totalSum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            // 一旦curSum < 0 说明[0, i]区间都不能作为起始位置，起始位置从i+1算起，再从0计算curSum。
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        // 如果所有加油站的用量和>拥有油量之和，肯定不能跑完全程
        if (totalSum < 0) return -1;
        return start;
    }
};
