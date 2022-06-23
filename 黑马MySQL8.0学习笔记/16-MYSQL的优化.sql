--  MySQL的优化方式有很多，大致我们可以从以下几点来优化MySQL:
-- • 从设计上优化
-- • 从查询上优化
-- • 从索引上优化
-- • 从存储上优化

-- 查看SQL执行频率

-- MySQL 客户端连接成功后，通过 show [session|global] status 命令可以查看服务器状态信息。通过
-- 查看状态信息可以查看对当前数据库的主要操作类型。

-- 下面的命令显示了当前 session 中所有统计参数的值

-- 查看当前会话统计结果
show session status like 'Com_______'; 

-- 查看自数据库上次启动至今统计结果
show global status like 'Com_______'; 

-- 查看针对Innodb引擎的统计结果
show status like 'Innodb_rows_%'; 





-- 定位低效率执行的SQL

-- 可以通过以下两种方式定位执行效率较低的 SQL 语句。 

-- 1.慢查询日志 : 通过慢查询日志定位那些执行效率较低的 SQL 语句。
-- show processlist：该命令查看当前MySQL在进行的线程，包括线程的状态、是否锁表等，可以实时地
-- 2.查看 SQL 的执行情况，同时对一些锁表操作进行优化。

-- 1.慢查询日志

-- 查看慢日志配置信息
show variables like '%slow_query_log%';

-- 开启慢日志查询
set global slow_query_log=1;

-- 查看慢日志记录SQL的最低阈值时间
show variables like 'long_query_time%';

select sleep(10);

-- 修改慢日志记录SQL的最低阈值时间
set global long_query_time = 4;



-- 2. show processlist

show processlist;

select sleep(50);





--  explain分析执行计划

-- 概念

-- 通过以上步骤查询到效率低的 SQL 语句后，可以通过 EXPLAIN命令获取 MySQL如何执行 SELECT 语句的信
-- 息，包括在 SELECT 语句执行过程中表如何连接和连接的顺序。

-- 准备测试数据

create database mydb13_optimize;

use mydb13_optimize;

-- 查询执行计划
explain select * from user where uid = 1;

explain select * from user where uname = '张飞';


-- Explain 之 id

-- 概述

-- id 字段是 select查询的序列号，是一组数字，表示的是查询中执行select子句或者是操作表的顺序。id 情况有三种

-- 1、id 相同表示:这几张表优先级一样,加载表的顺序是从上到下。

explain select * from user u, user_role ur, role r where u.uid = ur.uid and ur.rid = r.rid ;

-- 2、id 不同: id值越大，优先级越高，越先被执行(即最里面的查询)。

explain select * from role where rid = (select rid from user_role where uid = (select uid from user where uname = '张飞'));

-- 3） id 有相同，也有不同，同时存在。id相同的可以认为是一组，从上往下顺序执行；在所有的组中，id
-- 的值越大，优先级越高，越先执行。

EXPLAIN SELECT
	* 
FROM
	role r,
	( SELECT
		* 
	FROM
		user_role ur 
	WHERE
	ur.uid = ( SELECT uid FROM USER WHERE uname = '张飞' )) t 
WHERE
	r.rid = t.rid;
	

	
-- Explain 之 select_type


-- 简单查询SIMPLE-没有子查询和union

explain select * from user;

explain select * from user u, user_role ur where u.uid = ur.uid;

-- 子查询SUBQUERY(在select和where中包含子查询)与主查询PRIMARY(子查询中的最外层查询)

explain select * from role where rid = (select rid from user_role where uid = (select uid from user where uname = '张飞'));

-- DERIVED-在from列表中包含子查询,被标记为衍生表

explain select * from (select * from user limit 2) t;

-- UNION-查询语句中包含union
-- UNION RESULT
explain select * from user where uid = 1 union select * from user where uid = 3;


-- Explain之type

-- 结果值从最好到最坏以此是：system > const > eq_ref > ref > range > index > ALL



-- Explain之其他指标字段

-- table

-- 显示这一步所访问数据库中表名称有时不是真实的表名字，可能是简称

-- rows

-- 扫描行的数量。

-- key

-- possible_keys : 显示可能应用在这张表的索引， 一个或多个。
-- key ： 实际使用的索引， 如果为NULL， 则没有使用索引。
-- key_len : 表示索引中使用的字节数，该值为索引字段最大可能长度，并非实际使用长度，在不损失精确性的前提下， 长度越短越好 。

-- extra

-- 其他的额外的执行计划信息，在该列展示 。





-- show profile分析SQL

-- 概念

-- Mysql从5.0.37版本开始增加了对 show profiles 和 show profile 语句的支持。show profiles 能够在做SQL优化时帮
-- 助我们了解时间都耗费到哪里去了。

-- 通过 have_profiling 参数，能够看到当前MySQL是否支持profile：

select @@have_profiling;

set profiling=1; -- 开启profiling 开关；

-- 通过profile，我们能够更清楚地了解SQL执行的过程。首先，我们可以执行一系列的操作
show databases;

use mydb13_optimize;

show tables;

select * from user where uid < 2;

select count(*) from user;

-- 查看各个语句的耗时

show profiles;

-- 通过show profile for query query_id 语句可以查看到该SQL执行过程中每个线程的状态和消耗的时间：

show profile for query 322;

-- 在获取到最消耗时间的线程状态后，MySQL支持进一步选择all、cpu、block io 、context switch、page faults等明细类型
-- 类查看MySQL在使用什么资源上耗费了过高的时间。例如，选择查看CPU的耗费时间 ：

show profile cpu for query 133;





-- trace分析优化器执行计划

-- MySQL5.6提供了对SQL的跟踪trace, 通过trace文件能够进一步了解为什么优化器选择A计划, 而不是选择B计划

-- 打开trace ， 设置格式为 JSON，并设置trace最大能够使用的内存大小，避免解析过程中因为默认内存过小而不能够完
-- 整展示。

SET optimizer_trace="enabled=on",end_markers_in_json=on;
set optimizer_trace_max_mem_size=1000000;

-- 执行SQL语句

select * from user where uid < 2;

-- 最后， 检查information_schema.optimizer_trace就可以知道MySQL是如何执行SQL的 ：

select * from information_schema.optimizer_trace \G;





-- 使用索引优化

-- 概述

-- 索引是数据库优化最常用也是最重要的手段之一, 通过索引通常可以帮助用户解决大多数的MySQL的性能优化问题。


-- 数据准备

use mydb13_optimize;
create table `tb_seller` (
`sellerid` varchar (100),
`name` varchar (100),
`nickname` varchar (50),
`password` varchar (60),
`status` varchar (1),
`address` varchar (100),
`createtime` datetime,
primary key(`sellerid`)
);

insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('alibaba','阿里巴巴','阿里小店','e10adc3949ba59abbe56e057f20f883e','1','北京
市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('baidu','百度科技有限公司','百度小店
','e10adc3949ba59abbe56e057f20f883e','1','北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('huawei','华为科技有限公司','华为小店
','e10adc3949ba59abbe56e057f20f883e','0','北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('itcast','传智播客教育科技有限公司','传智播客
','e10adc3949ba59abbe56e057f20f883e','1','北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('itheima','黑马程序员','黑马程序员','e10adc3949ba59abbe56e057f20f883e','0','
北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('luoji','罗技科技有限公司','罗技小店
','e10adc3949ba59abbe56e057f20f883e','1','北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('oppo','OPPO科技有限公司','OPPO官方旗舰店
','e10adc3949ba59abbe56e057f20f883e','0','北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('ourpalm','掌趣科技股份有限公司','掌趣小店
','e10adc3949ba59abbe56e057f20f883e','1','北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('qiandu','千度科技','千度小店','e10adc3949ba59abbe56e057f20f883e','2','北京
市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('sina','新浪科技有限公司','新浪官方旗舰店
','e10adc3949ba59abbe56e057f20f883e','1','北京市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('xiaomi','小米科技','小米官方旗舰店
','e10adc3949ba59abbe56e057f20f883e','1','西安市','2088-01-01 12:00:00');
insert into `tb_seller` (`sellerid`, `name`, `nickname`, `password`, `status`, `address`,
`createtime`) values('yijia','宜家家居','宜家家居旗舰店','e10adc3949ba59abbe56e057f20f883e','1','
北京市','2088-01-01 12:00:00');


-- 创建组合索引

create index idx_seller_name_sta_addr on tb_seller(name,status,address);


-- 避免索引失效应用-1. 全值匹配

-- 该情况下，索引生效，执行效率高。

-- 全值匹配,和字段匹配成功即可,和字段顺序无关

explain select * from tb_seller where name='小米科技' and status='1' and address='北京市';

explain select * from tb_seller where address='北京市' and name='小米科技' and status='1';



-- 避免索引失效应用-2. 最左前缀法则

-- 如果索引了多列，要遵守最左前缀法则。指的是查询从索引的最左前列开始，并且不跳过索引中的列。

explain select * from tb_seller where name='小米科技'; -- 403
explain select * from tb_seller where name='小米科技' and status='1'; -- 410
explain select * from tb_seller where status='1' and name='小米科技'; -- 410

-- 违法最左前缀法则 ， 索引失效：
explain select * from tb_seller where status='1'; -- nulll

-- 如果符合最左法则，但是出现跳跃某一列，只有 最左列索引 生效：
explain select * from tb_seller where name='小米科技' and address='北京市'; -- 403
-- 该情况下，索引生效，执行效率高。


-- 避免索引失效应用-3. 其他匹配原则
-- 该情况下，索引生效，执行效率高。

-- 3.1 范围查询右边的列，不能使用索引 。
explain select * from tb_seller where name='小米科技' and status >'1' and address='北京市';	# 410

-- 3.2 不要在索引列上进行运算操作， 索引将失效。
explain select * from tb_seller where substring(name,3,2)='科技';

-- 3.3 字符串不加单引号，造成索引失效。
explain select * from tb_seller where name='小米科技' and status = 1 ;	# 403
explain select * from tb_seller where name='小米科技' and status = '1' ;	# 410

-- 3.4 尽量使用覆盖索引，避免select *

-- 需要从原表及磁盘上读取数据
explain select * from tb_seller where name='小米科技' and address='北京市'; -- 效率低

-- 从索引树中就可以查询到所有数据
explain select name from tb_seller where name='小米科技' and address='北京市'; -- 效率高
explain select name,status,address from tb_seller where name='小米科技' and address='北京市'; -- 效率高

-- 如果查询列，超出索引列，也会降低性能。
explain select name,status,address,password from tb_seller where name='小米科技' and address='北京市'; -- 效率低

-- 3.5 用or分割开的条件， 那么涉及的索引都不会被用到。
explain select * from tb_seller where name='黑马程序员' or createtime = '2088-01-01 12:00:00';
explain select * from tb_seller where name='黑马程序员' or address = '西安市';
explain select * from tb_seller where name='黑马程序员' or status = '1';

-- 3.6 以%开头的Like模糊查询，索引失效。
explain select * from tb_seller where name like '科技%'; -- 用索引
explain select * from tb_seller where name like '%科技'; -- 不用索引
explain select * from tb_seller where name like '%科技%';-- 不用索引

-- 为了弥补该不足,不用*，使用索引列,允许以%实现索引匹配
explain select name from tb_seller where name like '%科技%';

-- 3.7 如果MySQL评估使用索引比全表更慢，则不使用索引。
-- 这种情况是由数据本身的特点来决定的

-- 创建单列索引
create index index_address on tb_seller(address);

explain select * from tb_seller where address = '北京市'; -- 数量在所有数据中占的很多,所以没有使用索引
explain select * from tb_seller where address = '西安市'; -- 数量少,使用了索引

-- 3.8 is NULL ， is NOT NULL 有时有效，有时索引失效。

-- 创建单列索引
create index index_address on tb_seller(nickname);

explain select * from tb_seller where nickname is NULL; -- 索引有效
explain select * from tb_seller where nickname is not NULL; -- 无效

-- 3.9 in走索引, not in 没走索引

-- 普通索引(不一定)

explain select * from tb_seller where nickname in ('阿里小店', '百度小店'); -- 索引有效
explain select * from tb_seller where nickname not in ('阿里小店', '百度小店'); -- 索引有效

-- 主键索引不管in 还是not in都会使用索引

explain select * from tb_seller where sellerid in ('alibaba', 'baidu'); -- 索引有效
explain select * from tb_seller where sellerid not in ('alibaba', 'baidu'); -- 索引有效


-- 3.10 单列索引和复合索引,尽量使用复合索引

create index idx_seller_name_sta_addr on tb_seller(name,status,address);

/*
上面的组合索引等价于:
	name
	name + status
	name + status + address
*/

-- 如果一张表有多个单列索引,即使where中都使用了这些索引列,则只有一个最优索引(由优化器决定)生效




-- SQL优化

-- 大批量插入数据

create table `tb_user` (
`id` int(11) not null auto_increment,
`username` varchar(45) not null,
`password` varchar(96) not null,
`name` varchar(45) not null,
`birthday` datetime default null,
`sex` char(1) default null,
`email` varchar(45) default null,
`phone` varchar(45) default null,
`qq` varchar(32) default null,
`status` varchar(32) not null comment '用户状态',
`create_time` datetime not null,
`update_time` datetime default null,
primary key (`id`),
unique key `unique_user_username` (`username`)
);


-- 当使用load 命令导入数据的时候，适当的设置可以提高导入的效率。对于 InnoDB 类型的表，有以下几种方
-- 式可以提高导入的效率：

-- 1） 主键顺序插入
/*
因为InnoDB类型的表是按照主键的顺序保存的，所以将导入的数据按照主键的顺序排列，可以有效的提高导入数据
的效率。如果InnoDB表没有主键，那么系统会自动默认创建一个内部列作为主键，所以如果可以给表创建一个主键，
将可以利用这点，来提高导入数据的效率。
*/

-- 1、首先，检查一个全局系统变量 'local_infile' 的状态， 如果得到如下显示 Value=OFF，则说明这是不可用的
show global variables like 'local_infile';
-- 2、修改local_infile值为on，开启local_infile
set global local_infile=1;
-- 3、加载数据
/*
脚本文件介绍 :
sql1.log ----> 主键有序---94秒
sql2.log ----> 主键无序---2217秒
*/
load data local infile 'D:\\test\\sql1.log' into table tb_user fields terminated by ',' lines terminated by '\n';

truncate table tb_user;

load data local infile 'D:\\test\\sql2.log' into table tb_user fields terminated by ',' lines terminated by '\n';

-- 2 )、关闭唯一性校验

-- 在导入数据前执行 SET UNIQUE_CHECKS=0，关闭唯一性校验，在导入结束后执行SET UNIQUE_CHECKS=1，恢
-- 复唯一性校验，可以提高导入的效率。

-- 关闭唯一性校验

SET UNIQUE_CHECKS=0;

truncate table tb_user;

load data local infile 'D:\\test\\sql1.log' into table tb_user fields terminated by ',' lines terminated by '\n';

SET UNIQUE_CHECKS=1;




-- 优化insert语句

-- 当进行数据的insert操作的时候，可以考虑采用以下几种优化方案:

-- 1. 如果需要同时对一张表插入很多行数据时，应该尽量使用多个值表的insert语句，这种方式将大大的缩减客户端与数据库之间的连接、关闭等消耗。使得效率比分开执行的单个insert语句快。

-- 原始方式为：

insert into tb_test values(1,'Tom');
insert into tb_test values(2,'Cat');
insert into tb_test values(3,'Jerry');

-- 优化后的方案为 ：
insert into tb_test values(1,'Tom'),(2,'Cat')，(3,'Jerry');


-- 2. 在事务中进行数据插入。

-- 在这之前要先关闭事务的自动提交

begin;

insert into tb_test values(1,'Tom');
insert into tb_test values(2,'Cat');
insert into tb_test values(3,'Jerry');

commit;


-- 3. 数据有序插入

insert into tb_test values(4,'Tim');
insert into tb_test values(1,'Tom');
insert into tb_test values(3,'Jerry');
insert into tb_test values(5,'Rose');
insert into tb_test values(2,'Cat');

-- 优化后
insert into tb_test values(1,'Tom');
insert into tb_test values(2,'Cat');
insert into tb_test values(3,'Jerry');
insert into tb_test values(4,'Tim');
insert into tb_test values(5,'Rose');






-- 优化 order by 语句


-- 数据准备

CREATE TABLE `emp` (
`id` int(11) NOT NULL AUTO_INCREMENT,
`name` varchar(100) NOT NULL,
`age` int(3) NOT NULL,
`salary` int(11) DEFAULT NULL,
PRIMARY KEY (`id`)
);

insert into `emp` (`id`, `name`, `age`, `salary`) values('1','Tom','25','2300');
insert into `emp` (`id`, `name`, `age`, `salary`) values('2','Jerry','30','3500');
insert into `emp` (`id`, `name`, `age`, `salary`) values('3','Luci','25','2800');
insert into `emp` (`id`, `name`, `age`, `salary`) values('4','Jay','36','3500');
insert into `emp` (`id`, `name`, `age`, `salary`) values('5','Tom2','21','2200');
insert into `emp` (`id`, `name`, `age`, `salary`) values('6','Jerry2','31','3300');
insert into `emp` (`id`, `name`, `age`, `salary`) values('7','Luci2','26','2700');
insert into `emp` (`id`, `name`, `age`, `salary`) values('8','Jay2','33','3500');
insert into `emp` (`id`, `name`, `age`, `salary`) values('9','Tom3','23','2400');
insert into `emp` (`id`, `name`, `age`, `salary`) values('10','Jerry3','32','3100');
insert into `emp` (`id`, `name`, `age`, `salary`) values('11','Luci3','26','2900');
insert into `emp` (`id`, `name`, `age`, `salary`) values('12','Jay3','37','4500');

-- 创建组合索引

create index idx_emp_age_salary on emp(age,salary);

-- • 2、两种排序方式

-- 第一种是通过对返回数据进行排序，也就是通常说的 filesort 排序，所有 不是通过索引 直接返回排序结果的排序都叫
-- FileSort 排序。

-- 第二种通过有序索引顺序扫描直接返回有序数据，这种情况即为 using index，不需要额外排序，操作效率高。

-- 排序 order by

explain select * from emp order by age;	# Using filesort
explain select * from emp order by age, salary;	# Using filesort

-- 改造

explain select id from emp order by age;	# Using index
explain select id, age from emp order by age;	# Using index
explain select id, age, salary, name from emp order by age;	# Using filesort

-- order by后面多个排序字段要求排序方式尽量相同
explain select id, age from emp order by age asc, salary desc;	# Using index; Using filesort
explain select id, age from emp order by age asc, salary asc;	# Using index

-- order by后面多个排序字段顺序尽量和组合索引字段顺序一致
explain select id, age from emp order by salary asc, age asc;	Using index; Using filesort


-- • 3、Filesort 的优化
/*
通过创建合适的索引，能够减少 Filesort 的出现，但是在某些情况下，条件限制不能让Filesort消失，那就需要加快 Filesort的排序操作。对于Filesort ， MySQL 有两种排序算法：

1） 两次扫描算法 ：MySQL4.1 之前，使用该方式排序。首先根据条件取出排序字段和行指针信息，然后在排序区 sort buffer 中排序，如果sort buffer不够，则在临时表 temporary table 中存储排序结果。完成排序之后，再根据行指针回表读取记录，该操作可能会导致大量随机I/O操作。

2）一次扫描算法：一次性取出满足条件的所有字段，然后在排序区 sort buffer 中排序后直接输出结果集。排序时内存开销较大，但是排序效率比两次扫描算法要高。

MySQL 通过比较系统变量 max_length_for_sort_data 的大小和Query语句取出的字段总大小， 来判定是否那种排序算法，如果max_length_for_sort_data 更大，那么使用第二种优化之后的算法；否则使用第一种。

可以适当提高 sort_buffer_size 和 max_length_for_sort_data 系统变量，来增大排序区的大小，提高排序的效率。
*/

show variables like 'max_length_for_sort_data';	# 4096
show variables like 'sort_buffer_size';					# 262144









-- 优化 group by 

/*
于GROUP BY 实际上也同样会进行排序操作，而且与ORDER BY 相比，GROUP BY 主要只是多了排序之后的分组
操作。当然，如果在分组的时候还使用了其他的一些聚合函数，那么还需要一些聚合函数的计算。所以，在
GROUP BY 的实现过程中，与 ORDER BY 一样也可以利用到索引。
*/

-- 如果查询包含 group by 但是用户想要避免排序结果的消耗， 则可以执行order by null 禁止排序。如下 ：

drop index idx_emp_age_salary on emp;

explain select age,count(*) from emp group by age;

explain select age,count(*) from emp group by age order by null;

create index idx_emp_age_salary on emp(age,salary)；







-- 优化子查询

-- 使用子查询可以一次性的完成很多逻辑上需要多个步骤才能完成的SQL操作，同时也可以避免事务或者表锁死，并且写起
-- 来也很容易。
-- 但是，有些情况下，子查询是可以被更高效的连接（JOIN）替代。

use mydb13_optimize;

explain select * from user where uid in (select uid from user_role );

explain select * from user u  join user_role ur on u.uid = ur.uid;

-- system>const>eq_ref>ref>range>index>ALL
-- 连接(Join)查询之所以更有效率一些 ，是因为MySQL不需要在内存中创建临时表来完成这个逻辑上需要两个步骤的查询工作。





-- 优化limit查询(分页查询)

/*
一般分页查询时，通过创建覆盖索引能够比较好地提高性能。一个常见又非常头疼的问题就是 limit 900000,10 ，此时
需要MySQL排序前900010 记录，仅仅返回900000 - 900010 的记录，其他记录丢弃，查询排序的代价非常大 。
*/

select count(*) from tb_user;

select * from tb_user limit 0, 10;

-- 对于该语句会非常慢
select * from tb_user limit 900000, 10;


-- 1、优化思路一
-- 在索引上完成排序分页操作，最后根据主键关联回原表查询所需要的其他列内容。

select * from tb_user a, (select id from tb_user order by id limit 900000, 10) b where a.id = b.id;

-- 验证:
explain select * from tb_user limit 900000, 10;	# 未使用索引
explain select * from tb_user a, (select id from tb_user order by id limit 900000, 10) b where a.id = b.id; # 使用索引


-- 2、优化思路二
-- 该方案适用于主键自增的表，可以把Limit 查询转换成某个位置的查询 。

select * from tb_user where id > 900000 limit 10;

-- 验证
explain select * from tb_user where id > 900000 limit 10;		# 使用了主键索引