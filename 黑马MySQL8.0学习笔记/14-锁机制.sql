-- 数据准备

create database mydb14_lock;

use mydb14_lock;

create table `tb_book` (
`id` int(11) auto_increment,
`name` varchar(50) default null,
`publish_time` date default null,
`status` char(1) default null,
primary key (`id`)
) engine=myisam default charset=utf8;

insert into tb_book (id, name, publish_time, status) values(null,'java编程思想','2088-08-01','1');
insert into tb_book (id, name, publish_time, status) values(null,'solr编程思想','2088-08-08','0')

-- 一、MyISAM表锁

-- MyISAM 存储引擎只支持表锁

-- 表锁特点

-- 1） 对MyISAM 表的读操作，不会阻塞其他用户对同一表的读请求，但会阻塞对同一表的写请求；
-- 2） 对MyISAM 表的写操作，则会阻塞其他用户对同一表的读和写操作；
-- 
-- 简而言之，就是读锁会阻塞写，但是不会阻塞读。而写锁，则既会阻塞读，又会阻塞写。
-- 读锁是共享锁，任何用户都可以对其添加；写锁是排他/互斥锁（只能加一个），某个用户上锁后除非解锁，其他用户不能对其上锁

-- 此外，MyISAM 的读写锁调度是写优先，这也是MyISAM不适合做写为主的表的存储引擎的原因。
-- 因为写锁后，其他线程不能做任何操作，大量的更新会使查询很难得到锁，从而造成永远阻塞。

加读锁 ： lock table table_name read;
加写锁 ： lock table table_name write;




-- 二、 InnoDB行锁（InnoDB的表锁跟MyISAM的表锁类似）

-- 行锁特点

-- 行锁特点 ：偏向InnoDB 存储引擎，开销大，加锁慢；会出现死锁；锁定粒度最小，发生锁冲突的概率最低,并发度也最高。
-- InnoDB 与 MyISAM 的最大不同有两点：一是 支持事务；二是 采用了行级锁。

-- InnoDB 实现了以下两种类型的行锁：

/*
共享锁（S）：又称为读锁，简称S锁，共享锁就是多个事务对于同一数据可以共享一把锁，都能访问到数据，但是只能读不能
修改。
排他锁（X）：又称为写锁，简称X锁，排他锁就是不能与其他锁并存，如一个事务获取了一个数据行的排他锁，其他事务就不
能再获取该行的其他锁，包括共享锁和排他锁，但是获取排他锁的事务是可以对数据就行读取和修改。

对于UPDATE、DELETE和INSERT语句，InnoDB会自动给涉及数据集加排他锁（X)；
对于普通SELECT语句，InnoDB不会加任何锁；
*/

-- 数据准备
-- 行锁
create table test_innodb_lock(
id int(11),
name varchar(16),
sex varchar(1)
)engine = innodb ;
insert into test_innodb_lock values(1,'100','1');
insert into test_innodb_lock values(3,'3','1');
insert into test_innodb_lock values(4,'400','0');
insert into test_innodb_lock values(5,'500','1');
insert into test_innodb_lock values(6,'600','0');
insert into test_innodb_lock values(7,'700','0');
insert into test_innodb_lock values(8,'800','1');
insert into test_innodb_lock values(9,'900','1');
insert into test_innodb_lock values(1,'200','0');
create index idx_test_innodb_lock_id on test_innodb_lock(id);
create index idx_test_innodb_lock_name on test_innodb_lock(name);

set autocommit = 0;		# 关闭自动提交
-- 加锁

共享锁（S）：SELECT * FROM table_name WHERE ... LOCK IN SHARE MODE
排他锁（X) ：SELECT * FROM table_name WHERE ... FOR UPDATE
