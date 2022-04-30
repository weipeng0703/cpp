/*

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        deque<int> dq;
        if(size == 0)
        {
            return {};
        }
        for (int right = 0; right < num.size(); right++)
        {
            while (!dq.empty() && num[right] >= num[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(right);

            int left = right - size + 1;
            while (dq.front() < left)
            {
                dq.pop_front();
            }
            if (right + 1 >= size)
            {
                res.push_back(num[dq.front()]);
            }
            
        }
        return res;
    }
};