/*
一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；
所有孩子至少要有一个糖果。求解最少需要多少个糖果

输入输出样例
输入是一个数组，表示孩子的评分。输出是最少糖果的数量。
Input: [1,0,2]
Output: 5
在这个样例中，最少的糖果分法是 [2,1,2]。
*/
#include<vector> 
#include<algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2)
        {
            return size;
        }

        vector<int> res(size, 1);
        for (int i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                res[i] = res[i - 1] + 1;
            }
        }
        // 不能像下面这样写，因为当i = size - 1时
        // res[i + 1]会越界 
        // for(int i = 0;i < size; i++)
        // {
        //     if (ratings[i + 1] > ratings[i])
        //     {
        //         res[i + 1] = res[i] + 1;
        //     }

        // }
        for (int i = size - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                res[i - 1] = max(res[i - 1], res[i] + 1);
            }
            
        }
        
        
        return accumulate(res.begin(), res.end(), 0);
    }
};