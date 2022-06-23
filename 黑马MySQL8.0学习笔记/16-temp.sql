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

