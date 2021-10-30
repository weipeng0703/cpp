// 题目
/*
Redis怎么实现的定期删除功能
*/

// 解答
/*

expire key time
pexpire key time
expireat key 时间戳
pexpireat key 时间戳

过期字典的使用：redis会将过期的key 存储在过期字典中，通过使用定时器删除策略可以保证过期键尽快被删除，并且释放内存。但是操作cpu变慢。
实现：
使用 redis.c/activeExpireCycle 定期检查过期键
1. redis周期性使用redis.c/serveCron ,
2.使用 activeExpireCycle 便利服务器中的各个数据库
3.在过期字典里面随机检查一部分的key 如果是过期键就删除，不是就不执行，

*/