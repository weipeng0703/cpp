// 题目
/*
C++有哪些锁
*/

// 解答
/*

C++标准库里有的：

std::mutex(C++11)，普通互斥锁，可以阻塞式等锁（lock()）也可以非阻塞式上锁（try_lock()）
std::timed_mutex(C++11)，互斥锁的加时版本，如果在一段时间内（try_lock_for()）或是在某个时间之前（try_lock_until()）获取锁成功则成功上锁
std::recursive_mutex(C++11)，递归互斥锁，在互斥锁的基础上允许持有锁的线程多次通过lock()或者try_lock()获取锁，而std::mutex的拥有者不能继续请求上锁
std::recursive_timed_mutex(C++11)，递归锁的加时版本
std::shared_mutex(C++17)，共享互斥锁，允许多个线程共享锁(lock_shared()系列)，但只有一个线程能够持有互斥锁(lock()系列)，也就是一般所说的读写锁
std::shared_timed_mutex(C++14)，共享互斥锁的加时版本。该版本先于不加时的，因为当时赶着把共享互斥锁加进标准来不及了

RAII式锁管理器：
std::lock_guard<Mutex>(C++11)，最基础的管理器，只能自动上锁，退出作用域自动解锁，提前解锁都做不到
std::unique_lock<Mutex>(C++11)，独享所有权的锁管理器，除基础RAII功能之外还能移交所有权（此时不解锁），（解锁后）上锁和（提前）解锁
std::scoped_lock<Mutexes...>(C++17)，同时获取多个锁的锁管理器，获取过程是原子性的，要么同时获取要么什么都没有，避免一个个获取锁的时候发生死锁
std::shared_lock<SharedMutex>(C++14)，配合共享锁使用的锁管理器

原子变量：
std::atomic<T>(C++11)，就是……原子变量。但不保证原子性不是由锁来实现的
std::atomic_flag(C++11)，原子性的标记变量，保证其原子性的实现是无锁的

条件变量：
std::condition_variable(C++11)，需要std::unique_lock来使用
std::condition_variable_any(C++11)，不限于std::unique_lock

标准库并没有自旋锁std::spin_lock。自旋锁是忙等的，可以用std::atomic_flag来实现：
#include <atomic>
#include <iostream>

std::atomic_flag lock = ATOMIC_FLAG_INIT; // 这是个标准库里的宏

void spin_lock_output(int n) {
    // 上锁
    while(lock.test_and_set(std::memory_order_acquire))
        ; // 忙等自旋
    std::cout << "output from thread " << n << std::endl;
    // 解锁
    lock.clear(std::memory_order_release);
}


*/

