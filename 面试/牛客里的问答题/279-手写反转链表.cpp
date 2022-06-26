// 题目
/*
手写链表反转
*/

// 解答
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
}

ListNode* ReverseList(ListNode* pHead)
{
    if(!pHead||!pHead->next)
        return pHead;
    ListNode *pre=nullptr;
    ListNode *p=pHead;
    ListNode *next=pHead->next;
    while(p)
    {
        p->next=pre;
        pre=p;
        p=next;
        if(next)
        next=next->next;
    }
    return pre;
}

*/

