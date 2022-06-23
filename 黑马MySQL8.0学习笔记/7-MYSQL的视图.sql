-- 视图
use mydb6_view;
-- 准备数据
create database if not exists mydb6_view;
use mydb6_view;
create table dept(
	deptno int primary key,
  dname varchar(20),
	loc varchar(20)
);
insert into dept values(10, '教研部','北京'),
(20, '学工部','上海'),
(30, '销售部','广州'),
(40, '财务部','武汉');

create table emp(
	empno int primary key,
	ename varchar(20),
	job varchar(20),
	mgr int,
	hiredate date,
	sal numeric(8,2),
	comm numeric(8, 2),
	deptno int,
-- 	FOREIGN KEY (mgr) REFERENCES emp(empno),
	FOREIGN KEY (deptno) REFERENCES dept(deptno) ON DELETE SET NULL ON UPDATE CASCADE
);
insert into emp values
(1001, '甘宁', '文员', 1013, '2000-12-17', 8000.00, null, 20),
(1002, '黛绮丝', '销售员', 1006, '2001-02-20', 16000.00, 3000.00, 30),
(1003, '殷天正', '销售员', 1006, '2001-02-22', 12500.00, 5000.00, 30),
(1004, '刘备', '经理', 1009, '2001-4-02', 29750.00, null, 20),
(1005, '谢逊', '销售员', 1006, '2001-9-28', 12500.00, 14000.00, 30),
(1006, '关羽', '经理', 1009, '2001-05-01', 28500.00, null, 30),
(1007, '张飞', '经理', 1009, '2001-09-01', 24500.00, null, 10),
(1008, '诸葛亮', '分析师', 1004, '2007-04-19', 30000.00, null, 20),
(1009, '曾阿牛', '董事长', null, '2001-11-17', 50000.00, null, 10),
(1010, '韦一笑', '销售员', 1006, '2001-09-08', 15000.00, 0.00, 30),
(1011, '周泰', '文员', 1008, '2007-05-23', 11000.00, null, 20),
(1012, '程普', '文员', 1006, '2001-12-03', 9500.00, null, 30),
(1013, '庞统', '分析师', 1004, '2001-12-03', 30000.00, null, 20),
(1014, '黄盖', '文员', 1007, '2002-01-23', 13000.00, null, 10);

create table salgrade(
	grade int primary key,
	losal int,
	hisal int
);
insert into salgrade values
(1, 7000, 12000),
(2, 12010, 14000),
(3, 14010, 20000),
(4, 20010, 30000),
(5, 30010, 99990);


desc dept;

-- 1. 视图的创建

-- 语法

create [or replace] [algorithm = {undefined | merge | temptable}]
view view_name [(column_list)]
as select_statement
[with [cascaded | local] check option]

参数说明：
（1）algorithm：可选项，表示视图选择的算法。
（2）view_name ：表示要创建的视图名称。
（3）column_list：可选项，指定视图中各个属性的名词，默认情况下与SELECT语句中的查询的属性相同。
（4）select_statement：表示一个完整的查询语句，将查询记录导入视图中。
（5）[with [cascaded | local] check option]：可选项，表示更新视图时要保证在该视图的权限范围之内。


create or replace view view1_emp as select ename,job from emp;


-- 查看表和视图
show tables;

show full tables;

-- 2. 修改视图

-- 概念

-- 修改视图是指修改数据库中已存在的表的定义。当基本表的某些字段发生改变时，可以通过修改视图来保持视图和基
-- 本表之间一致。MySQL中通过CREATE OR REPLACE VIEW语句和ALTER VIEW语句来修改视图。

-- 语法

alter view 视图名 as select语句


ALTER VIEW view1_emp AS SELECT
a.deptno,
a.dname,
a.loc,
b.ename,
b.sal 
FROM
	dept a,
	emp b 
WHERE
	a.deptno = b.deptno;


-- 3. 更新视图

-- 概念

/*
某些视图是可更新的。也就是说，可以在UPDATE、DELETE或INSERT等语句中使用它们，以更新基表的内容。
对于可更新的视图，在视图中的行和基表中的行之间必须具有一对一的关系。
如果视图包含下述结构中的任何一种，那么它就是不可更新的：

	• 聚合函数（SUM(), MIN(), MAX(), COUNT()等）
	• DISTINCT
	• GROUP BY
	• HAVING
	• UNION或UNION ALL
	• 位于选择列表中的子查询
	• JOIN
	• FROM子句中的不可更新视图
	• WHERE子句中的子查询，引用FROM子句中的表。
	• 仅引用文字值（在该情况下，没有要更新的基本表）
*/

-- 注意：
-- 视图中虽然可以更新数据，但是有很多的限制。一般情况下，最好将视图作为查询数据的虚拟表，而不要通过视图更
-- 新数据。因为，使用视图更新数据时，如果没有全面考虑在视图中更新数据的限制，就可能会造成数据更新失败。

-- ---------更新视图-------
CREATE 
	OR REPLACE VIEW view1_emp AS SELECT
	ename,
	job 
FROM
	emp;
	
select * from view1_emp;

update view1_emp set ename = '鲁肃' where ename = '谢逊'; -- 可以修改

insert into view1_emp values('孙权','文员'); -- 不可以插入，因为是修改真实的表，所以没有表中后面几项且没有默认值，所以无法修改表


-- ----------视图包含聚合函数不可更新--------------
create or replace view view2_emp
as
select count(*) cnt from emp;

insert into view2_emp values(100);
update view2_emp set cnt = 100;

-- ----------视图包含distinct（去重）不可更新---------
create or replace view view3_emp
as
select distinct job from emp;

insert into view3_emp values('财务');

-- ----------视图包含goup by 、having不可更新------------------
create or replace view view4_emp
as
select deptno ,count(*) cnt from emp group by deptno having cnt > 2;

insert into view4_emp values(30,100);

-- ----------------视图包含union或者union all不可更新----------------
CREATE 
	OR REPLACE VIEW view5_emp AS SELECT
	empno,
	ename 
FROM
	emp 
WHERE
	empno <= 1005 UNION SELECT empno, ename FROM emp WHERE empno > 1005;

insert into view5_emp values(1015,'韦小宝');

-- -------------------视图包含子查询不可更新--------------------
create or replace view view6_emp
as
select empno,ename,sal from emp where sal = (select max(sal) from emp);

insert into view6_emp values(1015,'韦小宝',30000);

-- ----------------------视图包含join不可更新-----------------
create or replace view view7_emp
as
select dname,ename,sal from emp a join dept b on a.deptno = b.deptno;

insert into view7_emp(dname,ename,sal) values('行政部','韦小宝',30000);


-- --------------------视图包含常量文字值不可更新-------------------
create or replace view view8_emp
as
select '行政部' dname,'杨过' ename;

insert into view8_emp values('行政部','韦小宝')


-- 4. 其他操作

-- 4.1 重命名视图

-- rename table 视图名 to 新视图名; 
rename table view1_emp to my_view1;


-- 4.2 删除视图

-- drop view 视图名[,视图名…];
drop view if exists view8_emp; 

-- 注意：删除视图时，只能删除视图的定义，不会删除数据。
