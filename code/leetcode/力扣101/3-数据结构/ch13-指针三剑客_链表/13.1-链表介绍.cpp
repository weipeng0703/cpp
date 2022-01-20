/*
（单）链表是由节点和指针构成的数据结构，每个节点存有一个值，和一个指向下一个节点的指针，
因此很多链表问题可以用 递归 来处理。
不同于数组，链表并不能直接获取任意节点的值(不能随机访问)，必须要通过指针找到该节点后才能获取其值。
同理，在未遍历到链表结尾时，我们也无法知道链表的长度，除非依赖其他数据结构储存长度。
*/

// 力扣中默认的链表表示方法：
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 由于在进行链表操作时，尤其是删除节点时，经常会因为对当前节点进行操作而导致内存或指针出现问题。
// 有两个小技巧可以解决这个问题：
// 一是尽量处理当前节点的下一个节点而非当前节点本身;
// 二是建立一个虚拟节点 (dummy node)，使其指向当前链表的头节点，这样即使原链表所有节点全被删除，
// 也会有一个 dummy 存在，返回 dummy->next 即可。

// 注意
// 一般来说，算法题不需要删除内存。
// 在刷 LeetCode 的时候，如果想要删除一个节点，可以直接进行指针操作而无需回收内存。
// 实际做软件工程时，对于无用的内存，建议尽量显式回收，或利用智能指针。