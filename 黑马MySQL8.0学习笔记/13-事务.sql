-- MYSQL的事务操作主要有以下几种：

-- 	1、开启事务：Start Transaction
-- 	• 任何一条DML语句(insert、update、delete)执行，标志事务的开启
-- 	• 命令：BEGIN 或 START TRANSACTION
-- 	2、提交事务：Commit Transaction
-- 	• 成功的结束，将所有的DML语句操作历史记录和底层硬盘数据来一次同步
-- 	• 命令：COMMIT
-- 	3、回滚事务：Rollback Transaction
-- 	• 失败的结束，将所有的DML语句操作历史记录全部清空
-- 	• 命令：ROLLBACK



-- • 之前的所有SQL操作其实也有事务，只是MySQL自动帮我们完成的，每执行一条SQL时MySQL就帮我们自动提
-- 交事务，因此如果想要手动控制事务，则必须关闭MySQL的事务自动提交。

-- • 在MySQL中直接用 SET 来改变 MySQL 的自动提交模式:

set autocommit=0; # 禁止自动提交
set autocommit=1; # 开启自动提交


-- 准备数据

create database if not exists mydb12_transcation;
use mydb12_transcation;

-- 创建账户表
create table account(
id int primary key, -- 账户id
name varchar(20), -- 账户名
money double -- 金额
);

-- 插入数据
insert into account values(1,'zhangsan',1000);
insert into account values(2,'lisi',1000);


-- 设置MySQL的事务为手动提交(关闭自动提交)
select @@autocommit;
set autocommit = 0;

-- 模拟账户转账

-- 开启事务
begin;
update account set money = money - 200 where name = 'zhangsan';
update account set money = money + 200 where name = 'lisi';

-- 提交事务
commit;

-- 如果转账中的任何一条出现问题，则回滚事务
rollback;

select * from account;		# select 中查到的是数据最新的变化，而图形显示中的结果是落盘后的结果，所以二者得出的结果可能不一致



-- 查看隔离级别
show variables like '%isolation%';
-- 设置隔离级别
/*
set session transaction isolation level 级别字符串
级别字符串：read uncommitted、read committed、repeatable read、serializable
*/

-- 设置read uncommitted
set session transaction isolation level read uncommitted;
-- 这种隔离级别会引起脏读：A事务读取到B事务没有提交的数据

-- 设置read committed
set session transaction isolation level read committed;
-- 这种隔离级别会引起不可重复读：A事务在没有提交事务之前，可以看到数据不一致

-- 设置repeatable read（MYSQL默认的）
set session transaction isolation level repeatable read;
-- 这种隔离级别会引起幻读，A事务在提交之前和提交之后看到的数据不一致

-- 设置serializable
set session transaction isolation level serializable;
-- 这种隔离级别会解决脏读，不可重复读，幻读问题，比较安全，但是执行效率低（事务A操作表时，表会被锁起，B事务不能操作）


