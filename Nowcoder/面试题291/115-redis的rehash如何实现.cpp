// 题目
/*
Redis的rehash怎么做的，为什么要渐进rehash，渐进rehash又是怎么实现的?
*/

// 解答
/*
因为redis是单线程，当K很多时，如果一次性将键值对全部rehash，庞大的计算量会影响服务器性能，甚至可能会导致服务器在一段时间内停止服务。不可能一步完成整个rehash操作，所以redis是分多次、渐进式的rehash。渐进性哈希分为两种：
1）操作redis时，额外做一步rehash

对redis做读取、插入、删除等操作时，会把位于table[dict->rehashidx]位置的链表移动到新的dictht中，然后把rehashidx做加一操作，移动到后面一个槽位。

2）后台定时任务调用rehash

后台定时任务rehash调用链，同时可以通过server.hz控制rehash调用频率

*/