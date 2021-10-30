// 题目
/*
SQL优化的方法
*/

// 解答
/*

1.应尽量避免在 where 子句中使用!=或<>操作符
2.对查询进行优化，应尽量避免全表扫描，首先应考虑在 where 及 order by 涉及的列上建立索引
3.应尽量避免在 where 子句中对字段进行 null值判断，否则将导致引擎放弃使用索引而进行全表扫描
4.尽量避免在 where 子句中使用 or 来连接条件
5.in 和 not in 也要慎用，否则会导致全表扫描


*/