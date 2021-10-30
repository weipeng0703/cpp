// 题目
/*
数据库的三种范式
*/

// 解答
/*
事务隔离级别                           脏读                不可重复读            幻读

读未提交（read-uncommitted）            是                     是                 是
不可重复读（read-committed）            否                     是                 是
可重复读（repeatable-read）             否                     否                 是           
串行化（serializable）                  否                     否                 否

*/