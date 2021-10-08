/*
哈希表插入元素的做法：seperate chaining

但是如果插入的链表部分元素又过多（欲插入的元素的个数比最初哈希表分配的bucket的数量还多）的做法：
将初始bucket的个数扩充（原大小二倍的数字附近的素数），重新计算（reshaping）被打散的链表内元素的去处（同样是取余）

每一个hashtable初始大小为20个字节

hashtable构造时必须考虑如何构造hash function将传入的东西转换为适合插入到哈希表的形式

hash function的目的：希望根据元素值算出一个hash code，使得元素经过hash code映射后能够足够杂乱地被放置于hashtable内，
                    越乱越不容易发生碰撞

注意：标准库没有提供现成的 hash<std::string>


*/ 