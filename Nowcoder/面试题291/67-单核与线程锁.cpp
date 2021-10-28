// 题目
/*
单核机器上写多线程程序，是否需要考虑加锁，为什么？
*/

// 解答
/*
在单核机器上写多线程程序，仍然需要线程锁。
因为线程锁通常用来实现线程的同步和通信。

在单核机器上的多线程程序，仍然存在线程同步的问题。
因为在抢占式操作系统中，通常为每个线程分配一个时间片，当某个线程时间片耗尽时，
操作系统会将其挂起，然后运行另一个线程。

如果这两个线程共享某些数据，不使用线程锁的前提下，可能会导致共享数据修改引起冲突。
*/

// 知识点
/*

*/