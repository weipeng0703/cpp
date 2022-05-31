/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-31 16:07:43
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-31 16:52:44
 */
/*
力扣925. 长按键入
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

示例 1:
    输入：name = "alex", typed = "aaleex"
    输出：true
    解释：'alex' 中的 'a' 和 'e' 被长按。
示例 2：
    输入：name = "saeed", typed = "ssaaedd"
    输出：false
    解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
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

// 不能用哈希表，因为字符串中的字母是有顺序的
// 1-双指针遍历两个字符串，判断指针指向的字符是否相同
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.size() < name.size()) return false;
        if (name[0] != typed[0]) return false;
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (i >= 0 && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1])
            {
                j++;
            } else return false;
        }
        // 判断i是否到达name末位
        return i == name.size();
    }
};