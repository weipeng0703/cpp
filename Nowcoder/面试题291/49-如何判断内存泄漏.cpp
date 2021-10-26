// 题目
/*
如何判断内存泄漏？
*/

// 解答
/*
    内存泄漏通常是由于调用了malloc/new等内存申请的操作，但是缺少了对应的free/delete。
    为了判断内存是否泄露，我们一方面可以使用linux环境下的内存泄漏检查工具Valgrind,
    另一方面我们在写代码时可以添加内存申请和释放的统计功能，统计当前申请和释放的内存是否一致，以此来判断内存是否泄露。
*/