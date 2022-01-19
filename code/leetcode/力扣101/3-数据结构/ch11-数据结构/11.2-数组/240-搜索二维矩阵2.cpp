/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一:暴力查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            for (int element: row) {
                if (element == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
// 时间复杂度：O(mn)

// 空间复杂度：O(1)

// 有一个简单的技巧：我们可以从右上角开始查找
// 若当前值大于待搜索值，由于每一列的元素都是升序排列的，那么在当前的搜索矩阵中，
// 所有位于该列的元素都是严格大于 target 的，因此我们可以将它们全部忽略，即向左移动一位；
// 若当前值小于待搜索值，由于每一行的元素都是升序排列的，那么在当前的搜索矩阵中，
// 所有位于该行的元素都是严格小于 target 的，因此我们可以将它们全部忽略，即我们向下移动一位。
// 如果最终移动到左下角时仍不等于待搜索值，则说明待搜索值不存在于矩阵中。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // 行数
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].size();      // 列数
        // 最初的值matrix[i][j] = matrix[0][j]
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
        
    }
};
// 时间复杂度:O(m+n)
// 空间复杂度:O(1)