/*
语法格式
	select
	[all|distinct]
	<目标列的表达式1> [别名],
	<目标列的表达式2> [别名]...
	from <表名或视图名> [别名],<表名或视图名> [别名]...
	[where<条件表达式>]
	[group by <列名>
	[having <条件表达式>]]
	[order by <列名> [asc|desc]]
	[limit <数字或者列表>];

简化版语法
	select *| 列名 from 表 where 条件
*/

-- 数据准备

-- 1.创建数据库
create database if not exists mydb2;
use mydb2;

-- 2.添加商品表
create table product(
pid int primary key auto_increment, -- 商品编号
pname varchar(20) not null , -- 商品名字
price double, -- 商品价格
category_id varchar(20) -- 商品所属分类
);

-- 3.添加数据
insert into product values(null,'海尔洗衣机',5000,'c001');
insert into product values(null,'美的冰箱',3000,'c001');
insert into product values(null,'格力空调',5000,'c001');
insert into product values(null,'九阳电饭煲',200,'c001');
insert into product values(null,'啄木鸟衬衣',300,'c002');
insert into product values(null,'恒源祥西裤',800,'c002');
insert into product values(null,'花花公子夹克',440,'c002');
insert into product values(null,'劲霸休闲裤',266,'c002');
insert into product values(null,'海澜之家卫衣',180,'c002');
insert into product values(null,'杰克琼斯运动裤',430,'c002');
insert into product values(null,'兰蔻面霜',300,'c003');
insert into product values(null,'雅诗兰黛精华水',200,'c003');
insert into product values(null,'香奈儿香水',350,'c003');
insert into product values(null,'SK-II神仙水',350,'c003');
insert into product values(null,'资生堂粉底液',180,'c003');
insert into product values(null,'老北京方便面',56,'c004');
insert into product values(null,'良品铺子海带丝',17,'c004');
insert into product values(null,'三只松鼠坚果',88,null);

desc product;

-- 一、简单查询

-- 1.查询所有商品
SELECT pid, pname, price, category_id from product;
select * from product;

-- 2.查询商品名和商品价格
select pname, price from product;

-- 3.别名查询，使用的关键字是as(as也可以省略)

-- 3.1 表别名
select * from product as p;
select * from product p;

select p.id, u.id from product p, user u;		# 表别名的用途

-- 3.2 列别名
select pname as '商品名', price '商品价格' from product;

-- 4.去重(去掉某一列中重复的值，后面一般跟某一列)
select distinct price from product;
select distinct * from product;

-- 5.查询结果是表达式：将所有商品的价格+10元进行显示.
select pname,price+10 as 'newProduct' from product;



-- 二、运算符

-- 数据库中的表结构确立后，表中的数据代表的意义就已经确定。通过MySQL运算符进行运算，就可以获取到表结
-- 构以外的另一种数据。
-- 例如，学生表中存在一个birth字段，这个字段表示学生的出生年份。而运用MySQL的算术运算符用当前的年份减
-- 学生出生的年份，那么得到的就是这个学生的实际年龄数据。

-- MySQL支持4种运算符
-- 算术运算符
-- 比较运算符
-- 逻辑运算符
-- 位运算符


-- 1. 算术运算符

select 6 + 2;
select 6 - 2;
select 6 * 2;
select 6 / 2;
select 6 % 2;

-- 将每件商品的价格加10
select pname, price + 10 as new_price_1 from product;
-- 将所有商品的价格上调10%
select pname, price * 1.1 as new_price_2 from product;


-- 2. 条件查询

-- 查询商品名称为“海尔洗衣机”的商品所有信息：
select * from product where pname = '海尔洗衣机';

-- 查询价格为800商品
select * from product where price = 800;

-- 查询价格不是800的所有商品
select * from product where price != 800;
select * from product where price <> 800;
select * from product where not(price = 800);

-- 查询商品价格大于60元的所有商品信息
select * from product where price > 60;

-- 查询商品价格在200到1000之间所有商品
select * from product where price >= 200 and price <=1000;

select * from product where price between 200 and 1000;


-- 算术运算符高阶操作

-- 查询商品价格是200或800的所有商品
select * from product where price = 200 or price = 800;		# 逻辑表达式
select * from product where price = 200 || price = 800;		# 逻辑表达式
select * from product where price in (200,800);

-- 查询含有'裤'字的所有商品
select * from product where pname like '%裤%';		 # %用于匹配任意字符

-- 查询以'海'开头的所有商品
select * from product where pname like '海%';

-- 查询第二个字为'蔻'的所有商品
select * from product where pname like '_蔻%';		# _用于匹配单个字符

-- 查询category_id为null的商品
select * from product where category_id = null;		# 错误写法，sql中所有的值与null都不相等
select * from product where category_id is null;

-- 查询category_id不为null分类的商品
select * from product where category_id is not null;


-- 求最小值和最大值时有值为null，不会进行比较，结果直接为null
-- 使用least求最小值
select least(10, 20, 30); -- 10
select least(10, null , 30); -- null

-- 使用greatest求最大值
select greatest(10, 20, 30);
select greatest(10, null, 30); -- null

-- 3. 位运算符

-- 位运算符是在二进制数上进行计算的运算符。位运算会先将操作数变成二进制数，进行位运算。
-- 然后再将计算结果从二进制数变回十进制数。

select 3&5; -- 位与
select 3|5; -- 位或
select 3^5; -- 位异或	 异或——相同为0，不同为1
select 3>>1; -- 位右移	011->001  右移除以2	
select 3<<1; -- 位左移	011->110  左移乘以2
select ~3; -- 位取反    18446744073709551612



-- 三、排序查询

-- 如果我们需要对读取的数据进行排序，我们就可以使用 MySQL 的 order by 子句来设定你想按哪个字段哪种
-- 方式来进行排序，再返回搜索结果。

-- 语法（默认是升序）

select 字段名1，字段名2，…… from 表名 order by 字段名1 [asc|desc]，字段名2[asc|desc]……

-- 特点

-- 	1.asc代表升序，desc代表降序，如果不写默认 升序
-- 	2.order by用于子句中可以支持单个字段，多个字段，表达式，函数，别名
-- 	3.order by子句，放在查询语句的最后面。LIMIT子句除外
-- 	4.order by子句中，先按照前面的排序规则排序，若相同再按照之后的规则排序

-- 1.使用价格排序
select * from product order by price asc;		# asc可以省略
select * from product order by price desc;
-- 2.在价格排序(降序)的基础上，以分类排序(降序)
select * from product order by price desc, category_id asc;
-- 3.显示商品的价格(去重复)，并排序(降序)
select distinct price from product order by price desc;



-- 四、聚合查询

-- 之前我们做的查询都是横向查询，它们都是根据条件一行一行的进行判断，而使用聚合函数查询是纵
-- 向查询，它是对一列的值进行计算，然后返回一个 单一的值；另外聚合函数会忽略空值。


-- 聚合函数 		作用
-- count() 		统计指定列不为NULL的记录行数；
-- sum() 			计算指定列的数值和，如果指定列类型不是数值类型，那么计算结果为0
-- max() 			计算指定列的最大值，如果指定列是字符串类型，那么使用字符串排序运算；
-- min() 			计算指定列的最小值，如果指定列是字符串类型，那么使用字符串排序运算；
-- avg() 			计算指定列的平均值，如果指定列类型不是数值类型，那么计算结果为0


-- 1 查询商品的总条数
SELECT COUNT(PID) FROM PRODUCT;
SELECT COUNT(*) FROM PRODUCT;
-- 2 查询价格大于200商品的总条数
SELECT count(pid) from product where price > 200;
-- 3 查询分类为'c001'的所有商品的价格总和
SELECT sum(price) from product where category_id = 'c001';
-- 4 查询商品的最大价格
SELECT max(price) from product;
-- 5 查询商品的最小价格
SELECT min(price) from product;
-- 注：查询商品的最大和最小价格
SELECT max(price) as maxPrice ,min(price) as minPrice from product;
-- 6 查询分类为'c002'所有商品的平均价格
select avg(price) from product where category_id = 'c002';

-- 聚合查询-NULL值的处理

-- 	1、count函数对null值的处理
-- 	如果count函数的参数为星号（*），则统计所有记录的个数。而如果参数为某字段，不统计含null值的记录个数。
-- 	2、sum和avg函数对null值的处理
-- 	这两个函数忽略null值的存在，就好象该条记录不存在一样。
-- 	3、max和min函数对null值的处理
-- 	max和min两个函数同样忽略null值的存在。

-- 创建表
create table test_null(
c1 varchar(20),
c2 int
);

-- 插入数据
insert into test_null values('aaa',3);
insert into test_null values('bbb',3);
insert into test_null values('ccc',null);
insert into test_null values('ddd',6);

-- 测试
select count(*), count(c1), count(c2) from test_null;
select sum(c2),max(c2),min(c2),avg(c2) from test_null;

-- 为了防止null的作祟，在SQL中经常采用默认约束，即设定某一列的默认值
create table test_null(
c1 varchar(20),
c2 int DEFAULT 0
);



-- 五、分组查询

-- 概念
-- 分组查询是指使用group by字句对查询信息进行分组。

-- 语法
select 字段1,字段2… from 表名 group by 分组字段 having 分组条件;

-- 1 统计各个分类商品的个数
select category_id ,count(*) from product group by category_id ;
-- 如果要进行分组的话，则SELECT子句之后，只能出现分组的字段和统计函数，其他的字段不能出现：


-- 分组之后的条件筛选-having
--  1.分组之后对统计结果进行筛选的话必须使用having，不能使用where
--  2.where子句用来筛选 FROM 子句中指定的操作所产生的行
--  3.group by 子句用来分组 WHERE 子句的输出。
--  4.having 子句用来从分组的结果中筛选行

select 字段1,字段2… from 表名 group by 分组字段 having 分组条件;

-- 2.统计各个分类商品的个数,且只显示个数大于4的信息
select category_id ,count(*) from product group by category_id having count(*) > 1;

select category_id ,count(*) from product group by category_id having count(*) > 1 order by count(*) desc;



-- 六、分页查询

-- 概念

-- 分页查询在项目开发中常见，由于数据量很大，显示屏长度有限，因此对数据需要采取分页显示方式。
-- 例如数据共有30条，每页显示5条，第一页显示1-5条，第二页显示6-10条。

-- 语法

-- 方式1-显示前n条
select 字段1，字段2... from 表名 limit n
-- 方式2-分页显示
select 字段1，字段2... from 表名 limit m,n
m: 整数，表示从第几条索引开始，计算方式 （当前页-1）*每页显示条数
n: 整数，表示查询多少条数据

-- 查询product表的前5条记录
select * from product limit 5
-- 从第4条开始显示，显示5条
select * from product limit 3,5



-- 七、将一张表的数据导入另一张表

-- 1.INSERT INTO SELECT语句
-- 将一张表的数据导入到另一张表中(要求目标表Table2必须存在)

insert into Table2(field1,field2,…) select value1,value2,… from Table1 
或者：
insert into Table2 select * from Table1

use mydb2;
create table product2 (
	pname varchar(20),
	price double
);

insert into product2(pname, price) select pname, price from product;


-- 2. SELECT INTO FROM语句
-- 要求目标表Table2不存在，因为在插入时会自动创建表Table2，并将Table1中指定字段数据复制到
-- Table2中。
SELECT vale1, value2 into Table2 from Table1



-- 注：DQL查询的关键字书写顺序
SELECT category_id, count(pid), cnt  from product where price > 100 group by category_id having cnt > 4 order by cnt limit 1;

-- DQL查询的关键字执行顺序
from——>where——>group by——>count(pid)——>having——>select——>order by——>limit



-- 八、正则表达式

-- 正则表达式(regular expression)描述了一种字符串匹配的规则，正则表达式本身就是一个字符串，使用这个字符串
-- 来描述、用来定义匹配规则，匹配一系列符合某个句法规则的字符串。
-- 在开发中，正则表达式通常被用来检索、替换那些符合某个规则的文本。
-- MySQL通过REGEXP关键字支持正则表达式进行字符串匹配。

/*
^ 				匹配输入字符串的开始位置。
$ 				匹配输入字符串的结束位置。
. 				匹配除 "\n" 之外的任何单个字符。
[...] 		字符集合。匹配所包含的任意一个字符。例如， '[abc]' 可以匹配 "plain" 中的 'a'。
[^...] 		负值字符集合。匹配未包含的任意字符。例如， '[^abc]' 可以匹配 "plain" 中的'p'。
p1|p2|p3 	匹配 p1 或 p2 或 p3。例如，'z|food' 能匹配 "z" 或 "food"。'(z|f)ood' 则匹配 "zood" 或 "food"。
* 				匹配前面的子表达式零次或多次。例如，zo* 能匹配 "z" 以及 "zoo"。* 等价于{0,}。
+ 				匹配前面的子表达式一次或多次。例如，'zo+' 能匹配 "zo" 以及 "zoo"，但不能匹配 "z"。+ 等价于 {1,}。
{n} 			n 是一个非负整数。匹配确定的 n 次。例如，'o{2}' 不能匹配 "Bob" 中的 'o'，但是能匹配"food" 中的两个 o。
{n,m} 		m 和 n 均为非负整数，其中n <= m。最少匹配 n 次且最多匹配 m 次。
*/

-- ^ 在字符串开始处进行匹配
SELECT 'abc' REGEXP '^a';
select * from product where pname REGEXP '^海';

-- $ 在字符串末尾开始匹配
SELECT 'abc' REGEXP 'a$';
SELECT 'abc' REGEXP 'c$';
select * from product where pname REGEXP '水$';

-- . 匹配任意字符，可以匹配除了换行符之外的任意字符
SELECT 'abc' REGEXP '.b';
SELECT 'abc' REGEXP '.c';
SELECT 'abc' REGEXP 'a.';
select * from product where pname REGEXP '.水';

-- [...] 匹配括号内的任意单个字符。正则表达式的任意字符是否在前面的字符串中出现
SELECT 'abc' REGEXP '[xyz]';
SELECT 'abc' REGEXP '[xaz]';

-- [^...] 注意^符号只有在[]内才是取反的意思，在别的地方都是表示开始处匹配
SELECT 'a' REGEXP '[^abc]';
SELECT 'x' REGEXP '[^abc]';
SELECT 'abc' REGEXP '[^a]';

-- a* 匹配0个或多个a,包括空字符串。 可以作为占位符使用.有没有指定字符都可以匹配到数

SELECT 'stab' REGEXP '.ta*b';
SELECT 'stb' REGEXP '.ta*b';
SELECT '' REGEXP 'a*';

-- a+ 匹配1个或者多个a,但是不包括空字符
SELECT 'stab' REGEXP '.ta+b';
SELECT 'stb' REGEXP '.ta+b';

-- a? 匹配0个或者1个a
SELECT 'stb' REGEXP '.ta?b';
SELECT 'stab' REGEXP '.ta?b';
SELECT 'staab' REGEXP '.ta?b';

-- a1|a2 匹配a1或者a2，
SELECT 'a' REGEXP 'a|b';
SELECT 'b' REGEXP 'a|b';
SELECT 'b' REGEXP '^(a|b)';		# 是否以(a|b)开头
SELECT 'a' REGEXP '^(a|b)';
SELECT 'c' REGEXP '^(a|b)';

-- a{m} 匹配m个a
SELECT 'auuuuc' REGEXP 'au{4}c';
SELECT 'auuuuc' REGEXP 'au{3}c';

-- a{m,n} 匹配m到n个a,包含m和n
SELECT 'auuuuc' REGEXP 'au{3,}c';
SELECT 'auuuuc' REGEXP 'au{4,5}c';
SELECT 'auuuuc' REGEXP 'au{5,10}c';

-- (abc) abc作为一个序列匹配，不用括号括起来都是用单个字符去匹配，如果要把多个字符
-- 作为一个整体去匹配就需要用到括号，所以括号适合上面的所有情况。
SELECT 'xababy' REGEXP 'x(abab)y';
SELECT 'xababy' REGEXP 'x(ab)*y';
SELECT 'xababy' REGEXP 'x(ab){1,2}y';