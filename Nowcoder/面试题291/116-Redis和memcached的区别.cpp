// 题目
/*
Redis和memcached的区别
*/

// 解答
/*
1）数据类型 ：redis数据类型丰富，支持set liset等类型；memcache支持简单数据类型，需要客户端自己处理复杂对象

2）持久性：redis支持数据落地持久化存储；memcache不支持数据持久存储。

3）分布式存储：redis支持master-slave复制模式；memcache可以使用一致性hash做分布式。

4）value大小不同：memcache是一个内存缓存，key的长度小于250字符，单个item存储要小于1M，不适合虚拟机使用

5）数据一致性不同：redis使用的是单线程模型，保证了数据按顺序提交；memcache需要使用cas保证数据一致性。CAS（Check and Set）是一个确保并发一致性的机制，属于“乐观锁”范畴；原理很简单：拿版本号，操作，对比版本号，如果一致就操作，不一致就放弃任何操作

6）cpu利用：redis单线程模型只能使用一个cpu，可以开启多个redis进程

*/