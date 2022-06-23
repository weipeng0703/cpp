-- 一、创建外键约束
-- 
-- 方式1-在创建表时设置外键约束
-- 
-- 在 create table 语句中，通过 foreign key 关键字来指定外键，具体的语法格式如下：

[constraint <外键名>] foreign key 字段名 [，字段名2，…] references <主表名> 主键列1 [，主键列2，…]

create database mydb3;
use mydb3;
-- 创建部门表
create table if not exists dept(
deptno varchar(20) primary key , -- 部门号
name varchar(20) -- 部门名字
);

desc dept;

-- 创建员工表
create table if not exists emp(
eid varchar(20) primary key , -- 员工编号
ename varchar(20), -- 员工名字
age int, -- 员工年龄
dept_id varchar(20), -- 员工所属部门
constraint emp_fk foreign key (dept_id) references dept (deptno)  # 外键约束
);

desc emp;


-- 方式2-在创建表时设置外键约束

-- 外键约束也可以在修改表时添加，但是添加外键约束的前提是：从表中外键列中的数据必须与主表中主键列中
-- 的数据一致或者是没有数据。

alter table <数据表名> add constraint <外键名> foreign key(<列名>) references
<主表名> (<列名>);

-- 创建部门表
create table if not exists dept2(
deptno varchar(20) primary key , -- 部门号
name varchar(20) -- 部门名字
);
-- 创建员工表
create table if not exists emp2(
eid varchar(20) primary key , -- 员工编号
ename varchar(20), -- 员工名字
age int, -- 员工年龄
dept_id varchar(20) -- 员工所属部门
);
-- 创建外键约束
alter table emp2 add constraint dept_id_fk foreign key(dept_id) references dept2 (deptno);


-- 二、在外键约束下的数据操作

-- 2.1 数据插入

-- 1、添加主表数据
-- 注意必须先给主表添加数据
insert into dept values('1001', '研发部');
insert into dept values('1002', '销售部');
insert into dept values('1003', '财务部');
insert into dept values('1004', '人事部');

-- 2、添加从表数据
-- 注意给从表添加数据时，外键列的值不能随便写，必须依赖主表的主键列
insert into emp values('1', '乔峰' ,20, '1001');
insert into emp values('2', '段誉' ,21, '1001');
insert into emp values('3', '虚竹' ,23, '1001');
insert into emp values('4', '阿紫' ,18, '1002');
insert into emp values('5', '扫地僧' ,35, '1002');
insert into emp values('6', '李秋水' ,33, '1003');
insert into emp values('7', '鸠摩智' ,50, '1003');

-- 2.2 删除数据
/*
注意：
1：主表的数据被从表依赖时，不能删除，否则可以删除
2: 从表的数据可以随便删除
*/
delete from dept where deptno = '1001'; -- 不可以删除
delete from dept where deptno = '1004'; -- 可以删除
delete from emp where eid = '7'; -- 可以删除

-- 删除外键约束

-- 当一个表中不需要外键约束时，就需要从表中将其删除。外键一旦删除，就会解除主表和从表间的关联关系

alter table <表名> drop foreign key <外键约束名>;

alter table emp2 drop foreign key dept_id_fk;


-- 三、构建多对多外键约束

-- 在多对多关系中，A表的一行对应B的多行，B表的一行对应A表的多行，我们要新增加一个中间表，来建立多
-- 对多关系。

-- 学生表和课程表(多对多)

-- 1 创建学生表student(左侧主表)
create table if not exists student(
sid int primary key auto_increment,
name varchar(20),
age int,
gender varchar(20)
);

-- 2 创建课程表course(右侧主表)
create table course(
cid int primary key auto_increment,
cidname varchar(20)
);

-- 3 创建中间表student_course/score(从表)
create table score(
sid int,
cid int,
score double
);

-- 4 建立外键约束(2次)
alter table score add foreign key(sid) references student(sid);
alter table score add foreign key(cid) references course(cid);

-- 5 给学生表添加数据
insert into student values(1,'小龙女',18,'女'), (2,'阿紫',19,'女'), (3, '周芷若' ,20, '男');

-- 6 给课程表添加数据
insert into course values(1, '语文'),(2, '数学'),(3, '英语');

-- 7 给中间表添加数据
insert into score values(1,1,90),(1,2,92),(2,1, 89),(2,3, 27),(3,2, 34),(3,3, 46);

-- 修改和删除时，中间从表可以随便删除和修改，但是两边的主表受从表依赖的数据不能随便删除和修改
 
 
--  四、多表联合查询

-- 多表查询就是同时查询两个或两个以上的表，因为有的时候用户在查看数据的时候,需要显示的数据来自多张
-- 表.

/*
多表查询有以下分类：
 交叉连接查询 [产生笛卡尔积，了解]
			语法：select * from A,B; 
 内连接查询(使用的关键字 inner join -- inner可以省略)
			隐式内连接（SQL92标准）：select * from A,B where 条件;
			显示内连接（SQL99标准）：select * from A inner join B on 条件;
 外连接查询(使用的关键字 outer join -- outer可以省略)
			左外连接：left outer join
			select * from A left outer join B on 条件;
			右外连接：right outer join
			select * from A right outer join B on 条件;
			满外连接: full outer join
			select * from A full outer join B on 条件;
 子查询
			select的嵌套
 表自关联：
			将一张表当成多张表来用		
*/

-- 4.1 准备查询数据

-- 注：外键约束对多表查询并无影响。

use mydb3;

-- 创建部门表
create table if not exists dept3(
deptno varchar(20) primary key , -- 部门号
name varchar(20) -- 部门名字
);

-- 创建员工表
create table if not exists emp3(
eid varchar(20) primary key , -- 员工编号
ename varchar(20), -- 员工名字
age int, -- 员工年龄
dept_id varchar(20) -- 员工所属部门
);

-- 给dept3表添加数据
insert into dept3 values('1001','研发部');
insert into dept3 values('1002','销售部');
insert into dept3 values('1003','财务部');
insert into dept3 values('1004','人事部');

-- 给emp表添加数据
insert into emp3 values('1','乔峰',20, '1001');
insert into emp3 values('2','段誉',21, '1001');
insert into emp3 values('3','虚竹',23, '1001');
insert into emp3 values('4','阿紫',18, '1001');
insert into emp3 values('5','扫地僧',85, '1002');
insert into emp3 values('6','李秋水',33, '1002');
insert into emp3 values('7','鸠摩智',50, '1002');
insert into emp3 values('8','天山童姥',60, '1003');
insert into emp3 values('9','慕容博',58, '1003');
insert into emp3 values('10','丁春秋',71, '1005');


-- 4.2 交叉连接查询

-- 概念

-- 	• 交叉连接查询返回被连接的两个表所有数据行的笛卡尔积
-- 	• 笛卡尔积可以理解为一张表的每一行去和另外一张表的任意一行进行匹配
-- 	• 假如A表有m行数据，B表有n行数据，则返回m*n行数据
-- 	• 笛卡尔积会产生很多冗余的数据，后期的其他查询可以在该集合的基础上进行条件筛选

-- 语法

select * from 表1,表2,表3….;

select * from dept3, emp3;


-- 4.3 内连接查询

-- 概念

-- 	内连接查询求多张表的交集

-- 语法

-- 	隐式内连接（SQL92标准）：select * from A,B where 条件;
-- 	显示内连接（SQL99标准）：select * from A inner join B on 条件;

-- 查询每个部门的所属员工
select * from dept3,emp3 where dept3.deptno = emp3.dept_id;
select * from dept3 inner join emp3 on dept3.deptno = emp3.dept_id

-- 查询研发部和销售部的所属员工
select * from dept3,emp3 where dept3.deptno = emp3.dept_id and name in( '研发部','销售部');
select * from dept3 join emp3 on dept3.deptno = emp3.dept_id and name in( '研发部','销售部');

-- 查询每个部门的员工数,并升序排序
select deptno,count(1) as total_cnt from dept3,emp3 where dept3.deptno = emp3.dept_id group by deptno order by
total_cnt; 

select deptno,count(1) as total_cnt from dept3 join emp3 on dept3.deptno = emp3.dept_id group by deptno order by total_cnt;

-- 查询人数大于等于3的部门，并按照人数降序排序
select deptno,count(1) as total_cnt from dept3,emp3 where dept3.deptno = emp3.dept_id group by deptno having total_cnt >= 3 order by total_cnt desc;
-- 美化功能
SELECT
	deptno,
	count( 1 ) AS total_cnt 
FROM
	dept3,
	emp3 
WHERE
	dept3.deptno = emp3.dept_id 
GROUP BY
	deptno 
HAVING
	total_cnt >= 3 
ORDER BY
	total_cnt DESC;
	
select deptno,count(1) as total_cnt from dept3 join emp3 on dept3.deptno = emp3.dept_id group by deptno having total_cnt >= 3 order by total_cnt desc;


-- 4.4 外连接查询

-- 外连接分为左外连接（left outer join）、右外连接(right outer join)，满外连接(full outer join)。
-- 注意：oracle里面有full join,可是在mysql对full join支持的不好。我们可以使用union来达到目的。

-- 左外连接：left outer join
-- 		select * from A left outer join B on 条件;
-- 右外连接：right outer join
-- 		select * from A right outer join B on 条件;
-- 满外连接: full outer join
-- 		select * from A full outer join B on 条件;

-- 外连接查询
-- 查询哪些部门有员工，哪些部门没有员工
use mydb3;
select * from dept3 left outer join emp3 on dept3.deptno = emp3.dept_id;

-- 查询哪些员工有对应的部门，哪些没有
select * from dept3 right outer join emp3 on dept3.deptno = emp3.dept_id;

-- 使用union关键字实现左外连接和右外连接的并集

select * from dept3 full join emp3 on dept3.deptno = emp3.dept_id;		# 无法执行，mysql对full join的支持不友好

select * from dept3 left outer join emp3 on dept3.deptno = emp3.dept_id
union
select * from dept3 right outer join emp3 on dept3.deptno = emp3.dept_id;


-- 4.5 子查询（select的嵌套）

-- 概念

-- 子查询就是指的在一个完整的查询语句之中，嵌套若干个不同功能的小查询，从而一起完成复杂查询
-- 的一种编写形式，通俗一点就是包含select嵌套的查询。

-- 特点

-- 	1.单行单列：返回的是一个具体列的内容，可以理解为一个单值数据；
-- 	2.单行多列：返回一行数据中多个列的内容；
-- 	3.多行单列：返回多行记录之中同一列的内容，相当于给出了一个操作范围；
-- 	4.多行多列：查询返回的结果是一张临时表

-- 查询年龄最大的员工信息，显示信息包含员工号、员工名字，员工年龄
select eid,ename,age from emp3 where age = (select max(age) from emp3);

-- 查询研发部和销售部的员工信息，包含员工号、员工名字

-- 方式1-多表查询的关联查询
select * from dept3 a join emp3 b on a.deptno = b.dept_id and name = '研发部' or name = '销售部';
-- 方式2-子查询
select * from emp3 where dept_id in (select deptno from dept3 where name = '研发部' or name = '销售部');
select * from emp3 where dept_id in (select deptno from dept3 where name in ('研发部','销售部'));

-- 查询研发部20岁以下的员工信息,包括员工号、员工名字，部门名字
-- 方式1-关联查询
select * from dept3 a join emp3 b on a.deptno = b.dept_id and (name = '研发部' and age < 20);
-- 方式2-子查询
select * from (select * from dept3 where name = '研发部') t1 join (select * from emp3 where age < 20) t2 on t1.deptno = t2.dept_id; 


-- 4.6 子查询关键字

-- 在子查询中，有一些常用的逻辑关键字，这些关键字可以给我们提供更丰富的查询功能，主要关键字如下:
--  1.ALL关键字

-- 语法

select …from …where c > all(查询语句)
--等价于：
select ...from ... where c > result1 and c > result2 and c > result3

-- 特点:

-- 	• ALL: 与子查询返回的所有值比较为true 则返回true
-- 	• ALL可以与=、>、>=、<、<=、<>结合是来使用，分别表示等于、大于、大于等于、小于、小于等于、不等于其中的其中的所有数据。
-- 	• ALL表示指定列中的值必须要大于子查询集的每一个值，即必须要大于子查询集的最大值；
-- 	如果是小于号即小于子查询集的最小值。同理可以推出其它的比较运算符的情况。

-- 查询年龄大于‘1003’部门所有年龄的员工信息
select age from emp3 where dept_id = '1003';
select * from emp3 where age > all(select age from emp3 where dept_id = '1003');

-- 查询不属于任何一个部门的员工信息
select * from emp3 where dept_id != all(select deptno from dept3);

--  2.ANY关键字
--  3.SOME关键字

-- 语法

select …from …where c > any(查询语句)
--等价于：
select ...from ... where c > result1 or c > result2 or c > result3


-- 特点

-- 	• ANY:与子查询返回的任何值比较为true 则返回true
-- 	• ANY可以与=、>、>=、<、<=、<>结合是来使用，分别表示等于、大于、大于等于、小于、小于
-- 	等于、不等于其中的其中的任何一个数据。
-- 	• 表示制定列中的值要大于子查询中的任意一个值，即必须要大于子查询集中的最小值。同理可以
-- 	推出其它的比较运算符的情况。
-- 	• SOME和ANY的作用一样，SOME可以理解为ANY的别名

-- 查询年龄大于‘1003’部门任意一个员工年龄的员工信息
select * from emp3 where age > some(select age from emp3 where dept_id = '1003') and dept_id != '1003';


--  4.IN关键字

-- 语法

select …from …where c(c是指定的关键字/列名) in(查询语句)
--等价于：
select ...from ... where c = result1 or c = result2 or c = result3

-- 特点

-- 	• IN关键字，用于判断某个记录的值，是否在指定的集合中
-- 	• 在IN关键字前边加上not可以将条件反过来

-- 查询研发部和销售部的员工信息，包含员工号、员工名字
select * from emp3 where dept_id in (select deptno from dept3 where name = '研发部' or name = '销售部') ;


--  5.EXISTS关键字

-- 语法

select … from … where exists(查询语句)

-- 特点

-- • 该子查询如果“有数据结果”(至少返回一行数据)， 则该EXISTS() 的结果为“true”，外层查询执行
-- • 该子查询如果“没有数据结果”（没有任何数据返回），则该EXISTS()的结果为“false”，外层查询不执行
-- • EXISTS后面的子查询不返回任何实际数据，只返回真或假，当返回真时 where条件成立
-- • 注意，EXISTS关键字，比IN关键字的运算效率高，因此，在实际开发中，特别是大数据量时，推荐使用
-- EXISTS关键字

select * from emp3 where exists(select 1);		# 只要后面()里有结果,这条语句就去执行前面的语句 

-- 查询公司是否有大于60岁的员工，有则输出
select * from emp3  where exists(select * from emp3 where emp3.age > 60);		# 有问题

select * from emp3 a where exists(select * from emp3 b where a.age > 60);

-- 查询有所属部门的员工信息
select * from emp3 a where exists(select * from dept3 b where a.dept_id = b.deptno);


-- 4.7 自关联查询

-- 概念

-- MySQL有时在信息查询时需要进行对表自身进行关联查询，即一张表自己和自己关联，一张表当成多张表来用。
-- 注意自关联时表必须给表起别名。

-- 语法

select 字段列表 from 表1 a , 表1 b where 条件;
或者
select 字段列表 from 表1 a [left] join 表1 b on 条件;

-- 1.创建表,并建立自关联约束
create table t_sanguo(
eid int primary key ,
ename varchar(20),
manager_id int,
foreign key (manager_id) references t_sanguo (eid) -- 添加自关联约束
);

-- 2.添加数据
insert into t_sanguo values(1,'刘协',NULL);
insert into t_sanguo values(2,'刘备',1);
insert into t_sanguo values(3,'关羽',2);
insert into t_sanguo values(4,'张飞',2);
insert into t_sanguo values(5,'曹操',1);
insert into t_sanguo values(6,'许褚',5);
insert into t_sanguo values(7,'典韦',5);
insert into t_sanguo values(8,'孙权',1);
insert into t_sanguo values(9,'周瑜',8);
insert into t_sanguo values(10,'鲁肃',8);

-- 3.进行关联查询
-- 查询每个三国人物及他的上级信息，如: 关羽 刘备
select * from t_sanguo a, t_sanguo b where a.manager_id = b.eid;
select a.ename, b.ename from t_sanguo a, t_sanguo b where a.manager_id = b.eid;
select a.ename, b.ename from t_sanguo a join t_sanguo b on a.manager_id = b.eid;

-- 查询所有人物及其上级(没有的话显示null)
select a.ename, b.ename from t_sanguo a left join t_sanguo b on a.manager_id = b.eid;

-- 查询所有人物,上级,上上级(将一张表当作三张表用)
SELECT
	a.ename,
	b.ename,
	c.ename 
FROM
	t_sanguo a
	LEFT JOIN t_sanguo b ON a.manager_id = b.eid
	LEFT JOIN t_sanguo c ON b.manager_id = c.eid;