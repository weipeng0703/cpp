/*
给你一个非负整数 x ，计算并返回 x 的 平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例 1：
    输入：x = 4
    输出：2
示例 2：
    输入：x = 8
    输出：2
    解释：8 的平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去

提示：

0 <= x <= 2^31 - 1
。
*/
#include<math.h>

// 1.使用e与lnX表示开方
// 因为根号x = x的0.5次方 = (e的lnX)的0.5次方
// 所以x开平方后结果 = exp(0.5 * log(x))
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
        {
            return 0;
        }
        long long ans = exp(0.5 * log(x));
        return (ans + 1) * (ans + 1) <= x? ans + 1 : ans;   
    }
};

// 2.二分查找
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid =l + (r - l) / 2;
            if ((long long) mid * mid <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            
        }
        return ans;
    }
};