/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

*/
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 对于链表找环路的问题，有一个通用的解法——快慢指针（Floyd 判圈法）。
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        // 判断是否存在环路
        do{
            if (!fast || !fast->next)
            {
                // 如果 fast可以走到尽头，那么说明没有环路
                return nullptr;
            }
            fast = fast -> next -> next;
            slow = slow -> next;
        }while(fast != slow);
        // 若存在回路寻找节点
        fast = slow;
        while (fast != slow)        // 二者相等时跳出循环，此时的相遇点即为环路起始点
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};