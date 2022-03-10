#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
using namespace std; 

int main(){
    vector<int> temp = {1,4,4,4,4,4,45,5,6,6,7,7};
    // sort(temp.begin(), temp.end());
    // reverse(temp.begin(), temp.end());

    // for (auto ele : temp)
    // {
    //     cout << ele << " ";
    // }

    // cout << "值为4的个数为" << count(temp.begin(), temp.end(), 4);
    // bool flag = binary_search(temp.begin(), temp.end(), 63);
    // if (flag)
    // {
    //     cout << "找到" << endl;
    // }
    // else
    // {
    //     cout << "找不到" << endl;
    // }
    
    // auto it1 = lower_bound(temp.begin(), temp.end(), 4);
    // auto it2 = upper_bound(temp.begin(), temp.end(), 4);
    // cout << *it1 << endl;
    // cout << *it2 << endl;
    // cout << *it2 - *it1 << endl;
    // cout << it2 - it1 << endl;

    unique(temp.begin(), temp.end());

    for (auto ele : temp)
    {
        cout << ele << " ";
    }

    return 0;
}