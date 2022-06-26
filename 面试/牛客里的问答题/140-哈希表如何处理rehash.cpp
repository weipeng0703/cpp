// 题目
/*
hash表如何rehash，以及怎么处理其中保存的资源
*/

// 解答
/*
C++的hash表中有一个负载因子loadFactor，当loadFactor<=1时，hash表查找的期望复杂度为O(1). 
因此，每次往hash表中添加元素时，我们必须保证是在loadFactor <1的情况下，才能够添加。

因此，当Hash表中loadFactor==1时，Hash就需要进行rehash。
rehash过程中，会模仿C++的vector扩容方式，Hash表中每次发现loadFactor ==1时，就开辟一个原来桶数组的两倍空间，
称为新桶数组，然后把原来的桶数组中元素全部重新哈希到新的桶数组中。


*/