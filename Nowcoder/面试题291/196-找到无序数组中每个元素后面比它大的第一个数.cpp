// 题目
/*
n个整数的无序数组，找到每个元素后面比它大的第一个数，要求时间复杂度为O(N)
*/

// 解答
/*


*/
#include<vector>
#include<stack>
#include<iostream>
using namespace std;

vector<int> findMax(vector<int>num)
{
    // num为空
    if(num.size()==0)
        return num;

    vector<int> res(num.size());
    int i=0;
    stack<int> s;
    while(i<num.size())
    {
        if(s.empty()||num[s.top()]>=num[i])
        {
            s.push(i++);
        }
        else
        {
            res[s.top()]=num[i];
            s.pop();
        }
    }
    while(!s.empty())
    {
        res[s.top()]=INT_MAX;    // 如果之后没有比他大的数，输出最大值INT_MAX
        s.pop();
    }

    return res;
}

int main()
{
    vector<int> test;
    test.push_back(2);
    test.push_back(12);
    test.push_back(2342);
    test.push_back(122);
    test.push_back(12123);
    test.push_back(121);
    test.push_back(5);
    test.push_back(0);
    test.push_back(12);
    test.push_back(1);
    test.push_back(3);
    test.push_back(19);
    
    vector<int> ret = findMax(test);

    for (auto iterator = ret.begin(); iterator != ret.end(); iterator++)
    {
         cout << *iterator << endl;
    }
    

    return 0;
}