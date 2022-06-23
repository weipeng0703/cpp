-- 一、单列索引

-- 概念：一个索引只包含单个列，但一个表中可以有多个单列索引;

-- 1. 普通索引

-- 准备数据

create database mydb5;
use mydb5;

-- 1.1 创建索引

-- 方式1-创建表的时候直接指定

CREATE TABLE student (
	sid INT PRIMARY KEY,
	card_id VARCHAR ( 20 ),
	NAME VARCHAR ( 20 ),
	gender VARCHAR ( 20 ),
	age INT,
	birth date,
	phone_num VARCHAR ( 20 ),
	score DOUBLE,
	INDEX index_name ( NAME ) -- 给name列创建索引
	
);

select * from student where name = '张三';		# 数据量大的时候效果明显

-- 方式2-直接创建

-- 语法
create index indexname on tablename(columnname); 

create index index_gender on student(gender);

select * from student where name = '张三';		# 数据量大的时候效果明显

-- 方式3-修改表结构(添加索引)

-- 语法
alter table tablename add index indexname(columnname)

alter table student add index index_age(age);


-- 1.2 查看索引

-- 1、查看数据库所有索引

-- select * from mysql.`innodb_index_stats` a where a.`database_name` = '数据库名’; 

select * from mysql.`innodb_index_stats` a where a.`database_name` = 'mydb5';

-- 2、查看表中所有索引

-- select * from mysql.`innodb_index_stats` a where a.`database_name` = '数据库名' and a.table_name like '%表名%’; 

select * from mysql.`innodb_index_stats` a where a.`database_name` = 'mydb5' and a.table_name like '%student%';

-- 3、查看表中所有索引

-- show index from table_name; 

show index from student;

-- 1.3 删除索引

-- 语法

drop index 索引名 on 表名;
-- 或
alter table 表名 drop index 索引名;

drop index index_gender on student;
-- 或
alter table student drop index index_name;




-- 2. 唯一索引

-- 概念

-- • 唯一索引与前面的普通索引类似，不同的就是：索引列的值必须唯一，但允许有空值。
-- 如果是组合索引，则列值的组合必须唯一。

-- 2.1 创建索引

-- 方式1-创建表的时候直接指定
CREATE TABLE student2 (
	sid INT PRIMARY KEY,
	card_id VARCHAR ( 20 ),
	NAME VARCHAR ( 20 ),
	gender VARCHAR ( 20 ),
	age INT,
	birth date,
	phone_num VARCHAR ( 20 ),
	score DOUBLE,
	UNIQUE index_card_id ( card_id ) -- 给card_id列创建索引
);

-- 方式2-直接创建

-- create unique index 索引名 on 表名(列名) 

create unique index index_card_id on student2(card_id);


-- 方式3-修改表结构(添加索引)

-- alter table 表名 add unique [索引名] (列名)

alter table student2 add unique index_phone_num(phone_num)

-- 2.2 删除索引

drop index index_card_id on student2 
-- 或
alter table student2 drop index index_phone_num


-- 3. 主键索引

-- 概念

-- 每张表一般都会有自己的主键，当我们在创建表时，MySQL会自动在主键列上建立一个索引，这就是主键索引。
-- 主键是具有唯一性并且不允许为NULL，所以他是一种特殊的唯一索引。

show index from student2;





-- 二、组合索引

-- 概念

-- 	• 组合索引也叫复合索引，指的是我们在建立索引的时候使用多个字段，例如同时使用身份证和手机号建立
-- 	索引，同样的可以建立为普通索引或者是唯一索引。
-- 	• 复合索引的使用复合最左原则。

-- 语法

-- 创建索引的基本语法
create index indexname on table_name(column1(length),column2(length));


use mydb5;

-- 创建组合索引的基本语法-- 普通组合索引
-- create index indexname on table_name(column1(length),column2(length)); 

create index index_phone_name on student(phone_num,name);

-- 操作-删除索引
drop index index_phone_name on student;

-- 创建组合索引的基本语法-- 唯一组合索引
create unique index index_phone_name_2 on student(phone_num,name);


select * from student where name = '张三';
select * from student where phone_num = '15100046637';
select * from student where phone_num = '15100046637' and name = '张三';
select * from student where name = '张三' and phone_num = '15100046637';
/* 
1. 三条sql只有 2 、 3、4能使用的到索引idx_phone_name,因为条件里面必须包含索引前面的字段才能够进行匹配（最左原则）。

2.而3和4相比where条件的顺序不一样，为什么4可以用到索引呢？是因为mysql本身就有一层sql优化，

3.他会根据sql来识别出来该用哪个索引，我们可以理解为3和4在mysql眼中是等价的。
*/





-- 三、全文索引

-- 概念

-- • 全文索引的关键字是fulltext
-- • 全文索引主要用来查找文本中的关键字，而不是直接与索引中的值相比较，它更像是一个搜索引擎，基于
-- 相似度的查询，而不是简单的where语句的参数匹配。
-- • 用 like + % 就可以实现模糊匹配了，为什么还要全文索引？like + % 在文本比较少时是合适的，但是对于
-- 大量的文本数据检索，是不可想象的。全文索引在大量的数据面前，能比 like + % 快 N 倍，速度不是一个
-- 数量级，但是全文索引可能存在精度问题。

-- 全文索引的版本、存储引擎、数据类型的支持情况：
-- • MySQL 5.6 以前的版本，只有 MyISAM 存储引擎支持全文索引；
-- • MySQL 5.6 及以后的版本，MyISAM 和 InnoDB 存储引擎均支持全文索引;
-- • 只有字段的数据类型为 char、varchar、text 及其系列才可以建全文索引；
-- • 在数据量较大时候，现将数据放入一个没有全局索引的表中，然后再用create index创建fulltext索引，要比先为一张
-- 表建立fulltext然后再将数据写入的速度快很多；
-- • 测试或使用全文索引时，要先看一下自己的 MySQL 版本、存储引擎和数据类型是否支持全文索引。


-- 查看最小搜索长度和最大搜索长度
show variables like '%ft%';
  
	
-- 数据准备

-- 创建表的时候添加全文索引
create table t_article (
id int primary key auto_increment ,
title varchar(255) ,
content varchar(1000) ,
writing_date date
-- fulltext (content) -- 创建全文检索
);

insert into t_article values(null,"Yesterday Once More","When I was young I listen to 
the radio",'2021-10-01');
insert into t_article values(null,"Right Here Waiting","Oceans apart, day after 
day,and I slowly go insane",'2021-10-02');
insert into t_article values(null,"My Heart Will Go On","every night in my dreams,i 
see you, i feel you",'2021-10-03');
insert into t_article values(null,"Everything I Do","eLook into my eyes,You will see 
what you mean to me",'2021-10-04');
insert into t_article values(null,"Called To Say I Love You","say love you no new 
year's day, to celebrate",'2021-10-05');
insert into t_article values(null,"Nothing's Gonna Change My Love For You","if i had 
to live my life without you near me",'2021-10-06');
insert into t_article values(null,"Everybody","We're gonna bring the flavor show U 
how.",'2021-10-07');

-- 创建全文索引

-- 修改表结构添加全文索引
alter table t_article add fulltext index_content(content)

-- 直接添加全文索引
create fulltext index index_content on t_article(content);

-- 使用索引

-- 使用全文索引和常用的模糊匹配使用 like + % 不同，全文索引有自己的语法格式，使用 match 和 against 关键字，格式:

match (col1,col2,...) against(expr [search_modifier])


select * from t_article where match(content) against('yo'); -- 没有结果 单词数需要大于等于3 
select * from t_article where match(content) against('you'); -- 有结果




-- 四、空间索引

-- • MySQL在5.7之后的版本支持了空间索引，而且支持OpenGIS几何数据模型
-- • 空间索引是对空间数据类型的字段建立的索引，MYSQL中的空间数据类型有4种，分别是GEOMETRY、
-- POINT、LINESTRING、POLYGON。
-- • MYSQL使用SPATIAL关键字进行扩展，使得能够用于创建正规索引类型的语法创建空间索引。
-- • 创建空间索引的列，必须将其声明为NOT NULL。
-- • 空间索引一般是用的比较少，了解即可。


CREATE TABLE shop_info (
	id INT PRIMARY KEY auto_increment COMMENT 'id',
	shop_name VARCHAR ( 64 ) NOT NULL COMMENT '门店名称',
	geom_point geometry NOT NULL COMMENT '经纬度',
	SPATIAL KEY geom_index ( geom_point ) 
);