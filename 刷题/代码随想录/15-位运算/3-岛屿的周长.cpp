/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-26 09:15:13
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-26 09:52:14
 */
/*
力扣T1356. 根据数字二进制下 1 的数目排序
给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
请你返回排序后的数组。

示例 1：
    输入：arr = [0,1,2,3,4,5,6,7,8]
    输出：[0,1,2,4,8,3,5,6,7]
    解释：[0] 是唯一一个有 0 个 1 的数。
    [1,2,4,8] 都有 1 个 1 。
    [3,5,6] 有 2 个 1 。
    [7] 有 3 个 1 。
    按照 1 的个数排序得到的结果数组为 [0,1,2,4,8,3,5,6,7]
示例 2：
    输入：arr = [1024,512,256,128,64,32,16,8,4,2,1]
    输出：[1,2,4,8,16,32,64,128,256,512,1024]
    解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
示例 3：
    输入：grid = [[1,0]]
    输出：4
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 两种计算某个数二进制中1的个数的方法
// 方法一：向右移位每位与1做与运算
int countBitOne(int n) {
    int ans = 0;
    while (n > 0) {
        if ((n & 1) == 1) ans++;
        n >>= 1;
    }
    return ans;
}
// 方法二：循环n的二进制中1的个数次，比方法一高效
int countBitTwo(int n) {
    int ans = 0;
    while (n) {
        n &= (n - 1);
        ans++;
    }
    return ans;
}


// 1. 位运算
class Solution {
public:
    int countBitOne(int n) {
        int ans = 0;
        while (n > 0) {
            if ((n & 1) == 1) ans++;
            n >>= 1;
        }
        return ans;
    }
    static bool cmp(int a, int b) {
        int bitA = countBitOne(a);
        int bitB = countBitOne(b);
        if (bitA == bitB) return a < b;
        return bitA < bitB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};