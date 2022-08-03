/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-16 10:59:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-08-01 11:04:16
 */
  // https://www.runoob.com/w3cnote/heap-sort.html
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std; 

// 1-调用库
/*
std::priority_queue:在优先队列中，优先级高的元素先出队列，并非按照先进先出的要求，类似一个堆(heap)。
其模板声明带有三个参数，priority_queue<Type, Container, Functional>, 
其中Type为数据类型，Container为保存数据的容器，Functional为元素比较方式。
Container必须是用数组实现的容器，比如 vector, deque. STL里面默认用的是vector. 
比较方式默认用operator< , 所以如果把后面两个参数缺省的话，优先队列就是大顶堆，队头元素最大。

priority_queue()，默认按照从小到大排列。所以top()返回的是最大值而不是最小值！(即优先队列默认是大顶堆)

使用greater<>后，数据从大到小排列，top()返回的就是最小值而不是最大值！（greater后是小顶堆）

如果使用了第三个参数，那第二个参数不能省，用作保存数据的容器！！！！
*/

void heapSortSTL(vector<int>& nums) {
    // 从大到小排序用大根堆
    // priority_queue<int, vector<int>, less<int>> tempHeap;
    // 默认排序方式是大根堆
    // priority_queue<int, vector<int>> tempHeap;
    // 从小到大排序用小根堆
    priority_queue<int, vector<int>, greater<int>> tempHeap;

    for (int x : nums) tempHeap.push(x);
    for (int i = 0; i <nums.size(); i++){
        int temp = tempHeap.top();
        tempHeap.pop();
        nums[i] = temp;
    }
}
// 2-自己建堆

// 维护堆的性质
// 第一个参数为数组，第二个是数组长度，第三个是待维护节点的下标
void heapify(vector<int>& nums, int n, int i) {
    // 该节点的左右子节点
    int left = i * 2 + 1, right = i * 2 + 2;
    // 先假设父节点是最大的数
    int max = i;
    // 寻找三个节点(i节点，i的左右孩子节点)中最大的一个节点
    if (left < n && nums[left] > nums[max]) max = left;
    if (right < n && nums[right] > nums[max]) max = right;
    // 若i节点的某个孩子节点 > 该节点，则交换二者的位置
    if (max != i) {
        swap(nums[max], nums[i]);
        // 交换之后继续维护堆的性质,此时要维护的节点为max
        heapify(nums, n, max);
    }
}
// 建立大根堆，从树的倒数第二层第一个结点开始，对每一个节点进行heapify操作然后向上走
// 建堆的复杂度是O(n)
void heapBuild(vector<int>& nums, int n) {
    for (int i = (n - 1 - 1) / 2; i >= 0; i--) heapify(nums, n, i);
}
// 堆排序复杂度是O(logn)
void heapSort(vector<int>& nums, int n) {
    heapBuild(nums, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        // 剩余数组中元素个数为i，维护堆顶元素i的性质
        heapify(nums, i, 0);
    }
}

int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';
    // heapSortSTL(a);    // 用库函数

    int n = a.size();
    heapSort(a, a.size());   // 自己建堆
    cout << endl;
    cout << "堆排序完成" << endl;
    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }