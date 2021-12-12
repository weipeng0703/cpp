/*
给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1

示例 1：

    输入：n = 3
    输出：0
    解释：3! = 6 ，不含尾随 0
示例 2：

    输入：n = 5
    输出：1
    解释：5! = 120 ，有一个尾随 0
示例 3：

    输入：n = 0
    输出：0
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一:暴力法不太可
class Solution {
public:
    int jiecheng(int n)
    {
        return n > 1? n * jiecheng(n - 1) : 1;
    }
    int trailingZeroes(int n) {
        if (n == 0)
        {
            return 0;
        }
        int count = 0;
        strint str;
        str = to_string(jiecheng(n));

        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] ==  '0')
            {
                count++;
            }

            if (str[i + 1] != '0')
            {
                break;
            }
            
        }
        return count;
    }
};

// 方法二:数学方法
/*
    求n!
    0的来源 2 * 5 所以一对2和5即可产生一个0,所以0的个数即为min(阶乘中5的个数和2的个数) 
    又因为是2的倍数的数一定比是5的倍数的数多 所以2的个数一定>=5的个数 所以只需要统计 5 的个数了
    例如 5！ = 1 * 2 * 3 * 4 * 5
                  2      2 2  5    一个2和一个5配对出现0 所以5!末尾只有一个零
        而在 n = 25 时 可以产生5的有 5 10 15 20 25 
                                    即 n/5 = 5个 然而 25 = 5*5 所以少算了一个5 
        n>=25时,故而需要补上它 因此所有可以产生25的也要加上 
                                    即为 n/5 + n/25  然鹅 125 = 5*25 所以又少算了一个5
        n>=125时,故而需要补上它 因此所有可以产生125的也要加上
                                    即为 n/5 + n/25 + n/125  然鹅 625 = 5*125 所以又少算了一个5
        继续补上...
        所以最终为 n/5 + n/25 + n/125 + n/625 + ... 
                即 n/5 + n/5/5 + n/5/5/5 + n/5/5/5/5 + ... 
        代码如下
*/
class Solution {
public:
    int trailingZeroes(int n) {
        return (n == 0)? 0 : n / 5 + trailingZeroes(n / 5)
    }
};