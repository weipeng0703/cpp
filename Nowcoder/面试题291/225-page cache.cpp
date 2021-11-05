// 题目
/*
为什么要有page cache，操作系统怎么设计的page cache
*/

// 解答
/*
加快从磁盘读取文件的速率。
page cache中有一部分磁盘文件的缓存，因为从磁盘中读取文件比较慢，所以读取文件先去page cache中去查找，
如果命中，则不需要去磁盘中读取，大大加快读取速度。

在 Linux 内核中，文件的每个数据块最多只能对应一个 Page Cache 项，它通过两个数据结构来管理这些 Cache项，
一个是radix tree，另一个是双向链表。
Radix tree 是一种搜索树，Linux内核利用这个数据结构来通过文件内偏移快速定位Cache 项

*/

