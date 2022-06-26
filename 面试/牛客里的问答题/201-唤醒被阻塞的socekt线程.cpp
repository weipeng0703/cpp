// 题目
/*
怎么唤醒被阻塞的socket线程？
*/

// 解答
/*
(1)同步阻塞：
    等待锁的释放
(2)等待阻塞：
    1）使用Thread.sleep造成的阻塞:时间结束后自动进入RUNNABLE状态
    2）使用Thread.wait造成的阻塞:使用Thread.notify或者Thread.notifyAll唤醒
    3）使用Thread.join造成的阻塞:等待上一个线程执行完后自动进入RUNNABLE状态

    4）使用Thread.suspend造成的阻塞:使用Thread.resum唤醒
    5）使用LockSupport.park造成的阻塞:使用LockSupport.unpark唤醒
    6）使用LockSupport.parkNanos造成的阻塞:指定时间结束后，自动唤醒
    7）使用LockSupport.parkUntil造成的阻塞:到达指定的时间，自动唤醒


*/

