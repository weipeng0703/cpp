-- MYSQL的函数

-- 概述
-- 在MySQL中，为了提高代码重用性和隐藏实现细节，MySQL提供了很多函数。函数可以理解为别人封装好的模板代码。

-- 分类
-- 	在MySQL中，函数非常多，主要可以分为以下几类:
-- 	• 聚合函数:count max min等等
-- 	• 数学函数:绝对值  四舍五入等
-- 	• 字符串函数:切割 替换等
-- 	• 日期函数:处理日期
-- 	• 控制流函数:类似if 循环 判断等
-- 	• 窗口函数:8.0版本以上才会支持


-- 一、 聚合函数

-- 概述

-- 在MySQL中，聚合函数主要由：count,sum,min,max,avg,这些聚合函数我们之前都学过，不再重复。

-- 这里我们学习另外一个函数:group_concat(），该函数用户实现行的合并
-- group_concat()函数首先根据group by指定的列进行分组，并且用分隔符分隔，将同一个分组中的值连接起来，返回一个字符串结果。

-- 语法

group_concat([distinct] 字段名 [order by 排序字段 asc/desc] [separator '分隔符'])


-- 1. 准备数据

create database mydb4;
use mydb4;
create table emp(
emp_id int primary key auto_increment comment '编号',
emp_name char(20) not null default '' comment '姓名',
salary decimal(10,2) not null default 0 comment '工资',
department char(20) not null default '' comment '部门'
);
insert into emp(emp_name,salary,department)
values ('张晶晶',5000,'财务部'),('王飞飞',5800,'财务部'),('赵刚',6200,'财务部'),('刘小贝',5700,'人事部'),('王大鹏',6700,'人事部'),('张小斐',5200,'人事部'),('刘云云',7500,'销售部'),('刘云鹏',7200,'销售部'),('刘云鹏',7800,'销售部');

-- 将所有员工的名字合并成一行
select group_concat(emp_name) from emp;

-- 指定分隔符合并
select department,group_concat(emp_name separator ';' ) as names from emp group by department;

-- 指定排序方式和分隔符
select department, group_concat(emp_name order by salary desc separator ';' ) as namesSortBySalary from emp group by department;



-- 二、数学函数

-- 返回 x 的绝对值
SELECT ABS(-1) -- 返回1

-- 返回大于或等于 x 的最小整数
SELECT CEIL(1.5) -- 返回2

-- 返回小于或等于 x 的最大整数
SELECT FLOOR(1.5) -- 返回1

-- 返回列表中的最大值

-- 返回以下数字列表中的最大值：
SELECT GREATEST(3, 12, 34, 8, 25); -- 34
-- 返回以下字符串列表中的最大值：
SELECT GREATEST("Google", "Runoob", "Apple"); -- Runoob

-- 返回列表中的最小值

-- 返回以下数字列表中的最小值：
SELECT LEAST(3, 12, 34, 8, 25); -- 3
-- 返回以下字符串列表中的最小值：
SELECT LEAST("Google", "Runoob", "Apple"); -- Apple

-- 返回字段 expression 中的最大值

-- 返回数据表 Products 中字段 Price 的最大值：
SELECT MAX(Price) AS LargestPrice FROM Products;

-- 返回字段 expression 中的最小值

-- 返回数据表 Products 中字段 Price 的最小值：
SELECT MIN(Price) AS LargestPrice FROM Products;

-- 返回 x 除以 y 以后的余数
select mod(5, 2);

-- 返回圆周率(3.141593）
select PI();

-- 返回x的y次方
-- 2 的 3 次方：
SELECT POW(2,3) -- 8

-- 返回 0 到 1 的随机数
select rand();

-- 返回离 x 最近的整数（遵循四舍五入）
select round(1.23456);

-- 返回指定位数的小数（遵循四舍五入）
select round(1.23456, 3);	-- 1.235

-- 返回数值 x 保留到小数点后 y 位的值（与ROUND 最大的区别是不会进行四舍五入）
SELECT TRUNCATE(1.23456,3) -- 1.234



-- 三、字符串函数

-- 返回字符串s的字符数
-- 返回字符串 RUNOOB 的字符数
SELECT CHAR_LENGTH("RUNOOB") AS LengthOfString;
SELECT CHAR_LENGTH("你好吗") AS LengthOfString;		# 3

-- lengtn()返回的是字节数
SELECT LENGTH("你好吗") AS LengthOfString;		# 9

-- 返回字符串s的字符数
-- 返回字符串 RUNOOB 的字符数
SELECT CHARACTER_LENGTH("RUNOOB") AS LengthOfString;

-- 字符串 s1,s2 等多个字符串合并为一个字符串 
-- 合并多个字符串
SELECT CONCAT("SQL ", "Runoob ", "Gooogle ", "Facebook") AS ConcatenatedString;

-- 同 CONCAT(s1,s2,...) 函数，但是每个字符串之间要加上 x，x 可以是分隔符
-- 合并多个字符串，并添加分隔符：（分隔符位于第一位）
SELECT CONCAT_WS("---", "SQL", "Tutorial", "is", "fun!")AS ConcatenatedString;

-- 返回第一个字符串 s 在字符串列表(s1,s2...)中的位置
-- 返回字符串 c 在列表值中的位置：
SELECT FIELD("c", "a", "b", "c", "d", "e");

-- 去掉字符串 s 开始处的空格 
-- 去掉字符串 RUNOOB开始处的空格：
SELECT LTRIM(" RUNOOB") AS LeftTrimmedString;-- RUNOOB

-- 从字符串 s 的 n 位置截取长度为 len 的子字符串，同 SUBSTRING(s,n,len)
-- 从字符串 RUNOOB 中的第 2 个位置截取3个 字符：
SELECT MID("RUNOOB", 2, 3) AS ExtractString; -- UNO

-- 从字符串 s 中获取 s1 的开始位置 
-- 返回字符串 abc 中 b 的位置：
SELECT POSITION('b' in 'abc') -- 2

-- 将字符串 s2 替代字符串 s 中的字符串 s1 
-- 将字符串 abc 中的字符 a 替换为字符 x：
SELECT REPLACE('abc','a','x')  -- xbc

-- 将字符串s的顺序反过来 
-- 将字符串 abc 的顺序反过来：
SELECT REVERSE('abc') -- cba

-- 返回字符串 s 的后 n 个字符 
-- 返回字符串 runoob 的后两个字符：
SELECT RIGHT('runoob',2) -- ob

-- 去掉字符串 s 结尾处的空格 
-- 去掉字符串 RUNOOB 的末尾空格：
SELECT RTRIM("RUNOOB ") AS RightTrimmedString; -- RUNOOB

-- 比较字符串 s1 和 s2，如果 s1 与 s2 相等返回 0 ，如果 s1>s2 返回 1，如果 s1<s2 返回 -1
-- 比较字符串：
SELECT STRCMP("runoob", "runoob"); -- 0
SELECT STRCMP("runoob", "aunoob"); -- 1
SELECT STRCMP("runoob", "zunoob"); -- -1

-- 从字符串 s 的 start 位置截取长度为 length 的子字符串 
-- 从字符串 RUNOOB 中的第 2 个位置截取 3个 字符：
SELECT SUBSTR("RUNOOB", 2, 3) AS ExtractString; -- UNO

-- 从字符串 s 的 start 位置截取长度为 length 的子字符串 
-- 从字符串 RUNOOB 中的第 2 个位置截取 3个 字符：
SELECT SUBSTRING("RUNOOB", 2, 3) AS ExtractString; -- UNO

-- 去掉字符串 s 开始和结尾处的空格 
-- 去掉字符串 RUNOOB 的首尾空格：
SELECT TRIM(' RUNOOB ') AS TrimmedString;

-- 将字符串转换为大写 
-- 将字符串 runoob 转换为大写：
SELECT UCASE("runoob"); -- RUNOOB

-- 将字符串转换为大写 将字符串 
-- runoob 转换为大写：
SELECT UPPER("runoob"); -- RUNOOB

-- 将字符串 s 的所有字母变成小写字母 
-- 字符串 RUNOOB 转换为小写：
SELECT LCASE('RUNOOB') -- runoob

-- 将字符串 s 的所有字母变成小写字母 
-- 字符串 RUNOOB 转换为小写：
SELECT LOWER('RUNOOB') -- runoob



-- 四、日期函数

-- 返回从1970-01-01 00:00:00到当前毫秒值
select UNIX_TIMESTAMP(); # 1632729059

-- 将制定日期转为毫秒值时间戳 返回从1970-01-01 00:00:00到该时刻的毫秒值
SELECT UNIX_TIMESTAMP('2011-12-07 13:01:03');		# 1323234063

-- 将毫秒值时间戳转为指定格式日期 
SELECT FROM_UNIXTIME(1598079966,'%Y-%m-%d %H:%i:%s'); # 2020-08-22 15:06:06

-- 返回当前日期 
SELECT CURDATE();	
 
SELECT CURRENT_DATE();	

-- 返回当前时间
SELECT CURRENT_TIME();

SELECT CURTIME();

-- 返回当前日期和时间 
SELECT CURRENT_TIMESTAMP();

-- 从日期或日期时间表达式中提取日期值 
SELECT DATE("2017-06-15"); 

-- 计算日期 d1->d2 之间相隔的天数 
SELECT DATEDIFF('2001-01-01','2001-02-02');


-- 	计算时间差值    秒级
SELECT TIMEDIFF("13:10:11", "13:10:10");

-- 按表达式 f的要求显示日期 
SELECT DATE_FORMAT('2011-1-1 11:11:11','%Y-%m-%d %r') as standardTimeFormat;

-- 将字符串转变为日期 
SELECT STR_TO_DATE("August 10 2017", "%M %d %Y") as standardTimeFormat; 

-- 函数从日期减去指定的时间间隔。 
-- Orders 表中 OrderDate 字段减去 2 天：
SELECT DATE_SUB('2021-10-01',INTERVAL 2 DAY) AS OrderPayDate;

-- 将日期进行加法（跳转）
ADDDATE/DATE_ADD(d,INTERVAL expr type)

SELECT DATE_add('2021-10-01',INTERVAL 2 DAY) AS OrderPayDate;

SELECT DATE_ADD("2017-06-15 09:34:21", INTERVAL 15 MINUTE);

SELECT DATE_ADD("2017-06-15 09:34:21", INTERVAL -3 HOUR);

SELECT DATE_ADD("2017-06-15 09:34:21", INTERVAL -3 HOUR);

-- 从日期中获取指定的值
SELECT EXTRACT(MINUTE FROM '2011-11-11 11:11:11');

-- 返回给给定日期的那一月份的最后一天 
SELECT LAST_DAY("2017-06-20");

-- 基于给定参数年份 year 和所在年中的天数获取那一天的日期
-- 序号 day-of-year 返回一个日期
SELECT MAKEDATE(2017, 3);


-- 返回年月日时分秒、季节 
SELECT YEAR("2017-06-15");

SELECT MONTH("2017-06-15");

SELECT DAY("2017-06-15");

SELECT HOUR('1:2:3');

SELECT MINUTE('1:2:3');

SELECT SECOND('1:2:3');

SELECT QUARTER('2011-11-11 11:11:11');

-- 返回日期中的月份 年份等等

SELECT MONTHNAME('2011-11-11 11:11:11');

SELECT DAYNAME('2011-11-11 11:11:11');

SELECT DAYOFMONTH('2011-11-11 11:11:11');

SELECT DAYOFWEEK('2011-11-11 11:11:11');

SELECT DAYOFYEAR('2011-11-11 11:11:11');

-- 计算日期 d 是本年的第几个星期，范围是 0 到 53 
SELECT WEEK('2011-11-11 11:11:11');

SELECT WEEKDAY("2017-06-15");

SELECT WEEKOFYEAR('2011-11-11 11:11:11');

SELECT YEARWEEK("2017-06-15");

SELECT YEARWEEK("2017-06-15");

SELECT NOW();



-- 五、控制流函数

-- 5.1 if逻辑判断语句

-- 如果表达式 expr 成立，返回结果 v1；否则，返回结果 v2。
SELECT IF(1 > 0,'正确','错误') ;

use mydb3;
select  *, if (score >= 85, '优秀', '非优秀') flag from score;

-- 如果 v1 的值不为 NULL，则返回 v1，否则返回 v2。
SELECT IFNULL(null,'Hello Word');

-- 判断表达式是否为 NULL 
SELECT ISNULL(NULL);		# 1
SELECT ISNULL(5);				# 0

-- 比较两个字符串，如果字符串 expr1 与 expr2 相等 返回 NULL，否则返回 expr1
SELECT NULLIF(25, 25);		# null
SELECT NULLIF(25, 26);		# 25
SELECT NULLIF(26, 25);		# 26

-- case when 语句

-- CASE 表示函数开始，END 表示函数结束。
-- 如果condition1 成立，则返回 result1, 如果 condition2 成立，则返回 result2，当全部不成立则返回 result，而
-- 当有一个成立之后，后面的就不执行了。

select case 100 
	when 50 then 'tom' 
	when 100 then 'mary'
	else 'tim' 
end as 示例;

select case 
	when 1=2 then 'tom' 
	when 2=2 then 'mary' 
	else'tim' 
end as 示例;


use mydb4;
-- 创建订单表
create table orders(
oid int primary key, -- 订单id
price double, -- 订单价格
payType int -- 支付类型(1:微信支付 2:支付宝支付 3:银行卡支付 4：其他)
);

insert into orders values(1,1200,1);
insert into orders values(2,1000,2);
insert into orders values(3,200,3);
insert into orders values(4,3000,1);
insert into orders values(5,1500,2);

-- 方式1
select *, case
	when payType=1 then '微信支付'
	when payType=2 then '支付宝支付'
	when payType=3 then '银行卡支付'
	else '其他支付方式'
end as payTypeStr
from orders;

-- 方式2
select *, case payType
	when 1 then '微信支付'
	when 2 then '支付宝支付'
	when 3 then '银行卡支付'
	else '其他支付方式'
end as payTypeStr
from orders;





-- 六、窗口函数

-- 概念
-- 
-- • MySQL 8.0 新增窗口函数,窗口函数又被称为开窗函数，与Oracle 窗口函数类似，属于MySQL的一大特点.
-- • 非聚合窗口函数是相对于聚函数来说的。聚合函数是对一组数据计算后返回单个值（即分组），非聚合函数一次只会
-- 处理一行数据。窗口聚合函数在行记录上计算某个字段的结果时，可将窗口范围内的数据输入到聚合函数中，并不改
-- 变行数。

-- 语法结构

-- window_function ( expr ) OVER (
-- PARTITION BY ...
-- ORDER BY ...
-- frame_clause 
-- )

/*
其中，window_function 是窗口函数的名称；expr 是参数，有些函数不需要参数；OVER子句包含三个选项：
 分区（PARTITION BY）
PARTITION BY选项用于将数据行拆分成多个分区（组），它的作用类似于GROUP BY分组。如果省略了 PARTITION 
BY，所有的数据作为一个组进行计算
 排序（ORDER BY）
OVER 子句中的ORDER BY选项用于指定分区内的排序方式，与 ORDER BY 子句的作用类似
 以及窗口大小（frame_clause）。
frame_clause选项用于在当前分区内指定一个计算窗口，也就是一个与当前行相关的数据子集。
*/

-- 6.1 序号函数

-- 概念

-- 序号函数有三个：ROW_NUMBER()、RANK()、DENSE_RANK()，可以用来实现分组排序，并添加序号。

-- 语法格式

row_number()|rank()|dense_rank() over (
partition by ...
order by ...
)

-- 准备数据
use mydb4;

create table employee(
dname varchar(20), -- 部门名
eid varchar(20),
ename varchar(20),
hiredate date, -- 入职日期
salary double -- 薪资
);

insert into employee values('研发部','1001','刘备','2021-11-01',3000);
insert into employee values('研发部','1002','关羽','2021-11-02',5000);
insert into employee values('研发部','1003','张飞','2021-11-03',7000);
insert into employee values('研发部','1004','赵云','2021-11-04',7000);
insert into employee values('研发部','1005','马超','2021-11-05',4000);
insert into employee values('研发部','1006','黄忠','2021-11-06',4000);
insert into employee values('销售部','1007','曹操','2021-11-01',2000);
insert into employee values('销售部','1008','许褚','2021-11-02',3000);
insert into employee values('销售部','1009','典韦','2021-11-03',5000);
insert into employee values('销售部','1010','张辽','2021-11-04',6000);
insert into employee values('销售部','1011','徐晃','2021-11-05',9000);
insert into employee values('销售部','1012','曹洪','2021-11-06',6000);

-- 序号函数操作

-- 对每个部门的员工按照薪资排序，并给出排名（不考虑相同值的情况）
SELECT
	dname,
	ename,
	salary,
	row_number() over ( PARTITION BY dname ORDER BY salary DESC ) AS rn1, 
	rank() over ( PARTITION BY dname ORDER BY salary DESC ) AS rn2,
	dense_rank() over ( PARTITION BY dname ORDER BY salary DESC ) AS rn3 
FROM
	employee;

-- 求出每个部门薪资排在前三名的员工- 分组求TOP-N问题
-- 需要用子查询
SELECT * 
FROM
	( SELECT dname, ename, salary, dense_rank() over ( PARTITION BY dname ORDER BY salary DESC ) AS rn FROM employee ) t 
WHERE
	t.rn <= 3

-- 对所有员工进行全局排序（不分组）
-- 不加partition by表示全局排序
SELECT
	dname,
	ename,
	salary,
	dense_rank() over ( ORDER BY salary DESC ) AS rn 
FROM
	employee;



-- 6.2 开窗聚合函数

-- 概念

-- 在窗口中每条记录动态地应用聚合函数（SUM()、AVG()、MAX()、MIN()、COUNT()），可以动态计算在指定的
-- 窗口内的各种聚合函数值。

SELECT
	dname,
	ename,
	salary,
	sum( salary ) over ( PARTITION BY dname ORDER BY hiredate ) AS pv1 
FROM
	employee;
	
	
SELECT
	dname,
	ename,
	salary,
	sum( salary ) over ( PARTITION BY dname ) AS pv1 
FROM
	employee;-- 如果没有order by排序语句 默认把分组内的所有数据进行sum操作

-- 按一定的范围加和

SELECT
	dname,
	ename,
	salary,
	sum( salary ) over ( PARTITION BY dname ORDER BY hiredate rows BETWEEN unbounded preceding AND current ROW ) AS c1 
FROM
	employee;
	
SELECT
	dname,
	ename,
	salary,
	sum( salary ) over ( PARTITION BY dname ORDER BY hiredate rows BETWEEN 3 preceding AND current ROW ) AS c1 
FROM
	employee;


-- min max avg等
SELECT
	dname,
	ename,
	salary,
	avg( salary ) over ( PARTITION BY dname ORDER BY hiredate rows BETWEEN 3 preceding AND 1 following ) AS c1 
FROM
	employee;


SELECT
	dname,
	ename,
	salary,
	max( salary ) over ( PARTITION BY dname ORDER BY hiredate rows BETWEEN current ROW AND unbounded following ) AS c1 
FROM
	employee;


-- 6.3 分布函数

-- CUME_DIST
-- • 用途：分组内小于、等于当前rank值的行数 / 分组内总行数
-- • 应用场景：查询小于等于当前薪资（salary）的比例

SELECT
	dname,
	ename,
	salary,
	cume_dist() over ( ORDER BY salary ) AS rn1,-- 没有partition语句 所有的数据位于一组
	cume_dist() over ( PARTITION BY dname ORDER BY salary ) AS rn2 # 每个部门内的数据处于一组
FROM
	employee;

/*
rn1: 没有partition,所有数据均为1组，总行数为12，
第一行：小于等于3000的行数为3，因此，3/12=0.25
第二行：小于等于4000的行数为5，因此，5/12=0.4166666666666667
rn2: 按照部门分组，dname='研发部'的行数为6,
第一行：研发部小于等于3000的行数为1，因此，1/6=0.16666666666666666
*/


-- PERCENT_RANK
-- •用途：每行按照公式(rank-1) / (rows-1)进行计算。其中，rank为RANK()函数产生的序号，rows为当前窗口的记录总行数
-- •应用场景：不常用

SELECT
	dname,
	ename,
	salary,
	rank() over ( PARTITION BY dname ORDER BY salary DESC ) AS rn,
	percent_rank() over ( PARTITION BY dname ORDER BY salary DESC ) AS rn2 
FROM
	employee;
	
/*
rn2:
第一行: (1 - 1) / (6 - 1) = 0
第二行: (1 - 1) / (6 - 1) = 0
第三行: (3 - 1) / (6 - 1) = 0.4
*/


-- 前后函数-LAG和LEAD
-- •用途：返回位于当前行的前n行（LAG(expr,n)）或后n行（LEAD(expr,n)）的expr的值
-- •应用场景：查询前1名同学的成绩和当前同学成绩的差值 

-- lag的用法
SELECT
	dname,
	ename,
	hiredate,
	salary,
	lag( hiredate, 1, '2000-01-01' ) over ( PARTITION BY dname ORDER BY hiredate ) AS last_1_time,
	lag( hiredate, 2 ) over ( PARTITION BY dname ORDER BY hiredate ) AS last_2_time 
FROM
	employee;
	
/*
last_1_time: 指定了往上第1行的值，default为'2000-01-01' 
第一行，往上1行为null,因此取默认值 '2000-01-01'
第二行，往上1行值为第一行值，2021-11-01 
第三行，往上1行值为第二行值，2021-11-02 
last_2_time: 指定了往上第2行的值，为指定默认值
第一行，往上2行为null
第二行，往上2行为null
第四行，往上2行为第二行值，2021-11-01 
第七行，往上2行为第五行值，2021-11-02 
*/


-- lead的用法
SELECT
	dname,
	ename,
	hiredate,
	salary,
	lead( hiredate, 1, '2000-01-01' ) over ( PARTITION BY dname ORDER BY hiredate ) AS last_1_time,
	lead( hiredate, 2 ) over ( PARTITION BY dname ORDER BY hiredate ) AS last_2_time 
FROM
	employee;


-- 头尾函数-FIRST_VALUE和LAST_VALUE
 
-- 介绍
-- •用途：返回第一个（FIRST_VALUE(expr)）或最后一个（LAST_VALUE(expr)）expr的值
-- •应用场景：截止到当前，按照日期排序查询第1个入职和最后1个入职员工的薪资
 
-- 操作

-- 注意, 如果不指定ORDER BY，则进行排序混乱，会出现错误的结果
SELECT
	dname,
	ename,
	hiredate,
	salary,
	first_value( salary ) over ( PARTITION BY dname ORDER BY hiredate ) AS FIRST,
	last_value( salary ) over ( PARTITION BY dname ORDER BY hiredate ) AS last 
FROM
	employee;


-- 其他函数-NTH_VALUE(expr, n)、NTILE(n)

-- NTH_VALUE(expr,n)
-- •用途：返回窗口中第n个expr的值。expr可以是表达式，也可以是列名
-- •应用场景：截止到当前薪资，显示每个员工的薪资中排名第2或者第3的薪资
 
-- 操作

-- 查询每个部门截止目前薪资排在第二和第三的员工信息
SELECT
	dname,
	ename,
	hiredate,
	salary,
	nth_value( salary, 2 ) over ( PARTITION BY dname ORDER BY hiredate ) AS second_score,
	nth_value( salary, 3 ) over ( PARTITION BY dname ORDER BY hiredate ) AS third_score 
FROM
	employee
	
	
	
-NTILE

-- 介绍
-- 	•用途：将分区中的有序数据分为n个等级，记录等级数
-- 	•应用场景：将每个部门员工按照入职日期分成3组
 
-- 操作

-- 根据入职日期将每个部门的员工分成3组
SELECT
	dname,
	ename,
	hiredate,
	salary,
	ntile( 3 ) over ( PARTITION BY dname ORDER BY hiredate ) AS rn 
FROM
	employee;


