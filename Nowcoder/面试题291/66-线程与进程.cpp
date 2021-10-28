// 题目
/*
有了进程，为什么还要有线程？
*/

// 解答
/*
线程产生的原因：

进程可以使多个程序能并发执行，以提高资源的利用率和系统的吞吐量；
但是其具有一些缺点：

    进程在同一时间只能干一件事
    进程在执行的过程中如果阻塞，整个进程就会挂起，即使进程中有些工作不依赖于等待的资源，仍然不会执行。

因此，操作系统引入了比进程粒度更小的线程，作为并发执行的基本单位，
从而减少程序在并发执行时所付出的时空开销，提高并发性。

和进程相比，线程的优势如下：

    1.从资源上来讲，线程是一种非常"节俭"的多任务操作方式。
    在linux系统下，启动一个新的进程必须分配给它独立的地址空间，
    建立众多的数据表来维护它的代码段、堆栈段和数据段，这是一种"昂贵"的多任务工作方式。

    2.从切换效率上来讲，运行于一个进程中的多个线程，它们之间使用相同的地址空间，
    而且线程间彼此切换所需时间也远远小于进程间切换所需要的时间。
    据统计，一个进程的开销大约是一个线程开销的30倍左右。

    3.从通信机制上来讲，线程间方便的通信机制。
    对不同进程来说，它们具有独立的数据空间，
    要进行数据的传递只能通过进程间通信的方式进行，这种方式不仅费时，而且很不方便。
    线程则不然，由于同一进程下的线程之间贡献数据空间，
    所以一个线程的数据可以直接为其他线程所用，这不仅快捷，而且方便。

除以上优点外，多线程程序作为一种多任务、并发的工作方式，还有如下优点：

1、使多CPU系统更加有效。
操作系统会保证当线程数不大于CPU数目时，不同的线程运行于不同的CPU上。

2、改善程序结构。
一个既长又复杂的进程可以考虑分为多个线程，成为几个独立或半独立的运行部分，这样的程序才会利于理解和修改。
*/

// 知识点
/*

*/