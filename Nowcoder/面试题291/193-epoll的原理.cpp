// 题目
/*
epoll原理
*/

// 解答
/*


epoll 是一种更加高效的 IO 复用技术，epoll 的使用步骤及原理如下：

调用 epoll_create() 会在内核中创建一个 eventpoll 结构体数据，称之为 epoll 对象，
在这个结构体中有 2 个比较重要的数据成员，
一个是需要检测的文件描述符的信息 struct_root rbr（红黑树），
还有一个是就绪列表struct list_head rdlist，存放检测到数据发送改变的文件描述符信息（双向链表）；

调用 epoll_ctrl() 可以向 epoll 对象中添加、删除、修改要监听的文件描述符及事件；
调用 epoll_wait() 可以让内核去检测就绪的事件，并将就绪的事件放到就绪列表中并返回，通过返回的事件数组做进一步的事件处理。

epoll 的两种工作模式：

    LT 模式（水平触发）

    LT（Level - Triggered）是缺省的工作方式，并且同时支持 Block 和 Nonblock Socket。
    在这种做法中，内核检测到一个文件描述符就绪了，然后可以对这个就绪的 fd 进行 IO 操作，
    如果不作任何操作，内核还是会继续通知。

    ET 模式（边沿触发）

    ET（Edge - Triggered）是高速工作方式，只支持 Nonblock socket。
    在这种模式下，当描述符从未就绪变为就绪时，内核通过 epoll 检测到。
    然后它会假设你知道文件描述符已经就绪，并且不会再为那个文件描述符发送更多的就绪通知，
    直到你做了某些操作导致那个文件描述符不再为就绪状态了。
    但是请注意，如果一直不对这个 fd 进行 IO 操作（从而导致它再次变成未就绪），内核不会发送更多的通知（only once）。

    ET 模式在很大程度上减少了 epoll 事件被重复触发的次数，因此效率要比 LT 模式高。
    epoll 工作在 ET 模式的时候，必须使用非阻塞套接口，
    以避免由于一个文件描述符的阻塞读/阻塞写操作把处理多个文件描述符的任务饿死。

*/