/*
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 Solution class:

    Solution(int[] nums) 使用整数数组 nums 初始化对象
    int[] reset() 重设数组到它的初始状态并返回
    int[] shuffle() 返回数组随机打乱后的结果

示例：

输入
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
输出
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

解释
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]
*/
#include<vector> 
#include<cmath> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 标准库shuffle
// 需要包含头文件
#include <random>
#include <algorithm>
class Solution {
    std::mt19937 m_engine;  // 随机数生成器
    vector<int> m_origin;
    vector<int> m_shuffled;
public:
    Solution(vector<int>& nums) : m_Engine(random_device{}()), m_Origin(nums), m_Shuffled(nums) {}
    
    vector<int> reset() {
        return m_origin;
    }
    
    vector<int> shuffle() {
        std::shuffle(m_shuffled.begin(), m_shuffled.end(), m_engine);
        return m_shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


// 方法二：Knuth-Durstenfeld Shuffle（KDS）算法

// 与经典的Fisher-Yates Shuffle（FYS）洗牌算法思路基本是一样的:
// 不断从原始数组剩余的元素里随机抽出一个，排到结果队列（数组）里。但KDS做了一点优化，它不需要额外的结果数组，直接在原始数组上进行操作，时间复杂度也从O（n*n）
// 提升到了O(N)。
// 大意就是:
// 把数组a分成两段，i之前的位置当做一个队列用于存放结果，不断push；
// i之后的就是你手里剩下的牌，每一趟从剩下的抽一张，push到前一段的结尾。
// 这样的话，抽牌和插入操作就可以在一个容器里完成，而实现FYS需要预备两个容器，一个用于push，一个不断的erase。

// C/C++中在区间[a,b]生成随机数（都是整数）的方法是这样的:
// a + std::rand() % ( b - a + 1 )

class Solution 
{
	struct Initializer
	{
		Initializer()	{
			std::srand(std::time(nullptr)); 
		}
	};

	// 程序启动时自动初始化随机数生成器。通常在main开头调用一次。
	inline static Initializer	m_Init{};

public:
	Solution(const vector<int> &nums) : m_Origin(nums), m_Shuffled(nums){}

	vector<int> reset() {
		return m_Origin;
	}

	vector<int> shuffle()
	{
		int i{}, n = m_Shuffled.size();
		for( ; i < n; ++i )
		{
			auto r = i + rand() % (n - i);	// r : [ i, n - 1 ]
			swap(m_Shuffled[i], m_Shuffled[r] );
		}

		return m_Shuffled;
	}

private:
	vector<int> m_Origin;
	vector<int> m_Shuffled;
};