/*
1.约束的概念
约束英文：constraint
约束实际上就是表中数据的限制条件
2.约束的作用
表在设计的时候加入约束的目的就是为了 保证表中的记录完整性和有效性，
比如用户表有些列的值（手机号）不能为空，有些列的值（身份证号）不能重复。
3.约束的分类
 主键约束(primary key) PK：限制一个列中的数据不能为空
 自增长约束(auto_increment)：一般配合主键约束。某一列的值可以自动增长
 非空约束(not null)：某一列的值不能为空
 唯一性约束(unique)：表示某一列的值不能重复
 默认约束(default)：某一列中的数据如果没赋值，可以自动为其添加值
 零填充约束(zerofill)：有些字段自动填充为0
 外键约束(foreign key) FK：多表操作中的
*/

-- 一、主键约束

-- 1.添加单列主键
-- 创建单列主键有两种方式，一种是在定义字段的同时指定主键，一种是定义完字段之后指定主键

-- 方式1语法
-- 在 create table 语句中，通过 PRIMARY KEY 关键字来指定主键。
-- 在定义字段的同时指定主键，语法格式如下：

create table 表名(
...
<字段名> <数据类型> primary key
...
)

use mydb1;

create table emp1(
eid int primary key,
name VARCHAR(20),
deptId int,
salary double
);

-- 方式2语法
-- --在定义字段之后再指定主键，语法格式如下：
create table 表名(
...
[constraint <约束名>] primary key [字段名]
);

create table emp2(
eid INT,
name VARCHAR(20),
deptId INT,
salary double,
constraint pk1 primary key(eid)    # constraint pk1可以省略
);

-- 主键的作用
-- 主键约束的列非空且唯一
insert into emp2(eid, name, deptID, salary) VALUES(1001, 'zhangsan', 10, 5000);

insert into emp2(eid, name, deptID, salary) VALUES(1002, 'lisi', 10, 5000);

insert into emp2(eid, name, deptID, salary) VALUES(NULL, 'wamgwu', 10, 5000);

-- 2.添加联合主键
-- 注意：
-- 1. 当主键是由多个字段组成时，不能直接在字段名后面声明主键约束。
-- 2. 一张表只能有一个主键，联合主键也是一个主键

-- 语法：
create table 表名(
...
primary key （字段1，字段2，…,字段n)
);

create table emp3(
name varchar(20),
deptId int,
salary double,
primary key(name,deptId)
);

insert into emp3 values('zhangsan', 10, 5000);
insert into emp3 values('zhangsan', 20, 5000);		# 只要前面两个值不是完全相同即可
-- 联合主键的每一列均不能为空 Null
insert into emp3 values(NULL, 20, 5000);	
insert into emp3 values('asdsdasd', NULL, 5000);		

-- 3.通过修改表结构添加主键
-- 语法：
create table 表名(
...
);
alter table <表名> add primary key(字段列表);

-- 添加单列主键
use mydb1;
create table emp4(
eid int,
name varchar(20),
deptId int,
salary double
);
alter table emp4 add primary key(eid);

-- 添加多列主键
create table emp5(
eid int,
name varchar(20),
deptId int,
salary double
);
alter table emp5 add primary key(eid, name);

-- 3.删除主键约束

-- 语法
alter table <数据表名> drop primary key;
-- 注：删除主键的时候不分单列还是多列，因为对于一个表只有一个主键（不分单列还是联合）

-- 删除单列主键
alter table emp1 drop primary key;
-- 删除联合主键
alter table emp5 drop primary key;


-- 二.自增长约束(一般与主键联合使用)

-- 概念
-- 在 MySQL 中，当主键定义为自增长后，这个主键的值就不再需要用户输入数据了，而由数据库系统根据定义自动赋值。
-- 每增加一条记录，主键会自动以相同的步长进行增长。
-- 通过给字段添加 auto_increment 属性来实现主键自增长

-- 语法
-- 字段名 数据类型 auto_increment

create table t_user1(
id int primary key auto_increment,
name varchar(20)
);

insert into t_user1 values(null, 'zhangsan');
insert into t_user1(name) values('lisi');

-- 特点
/*
 默认情况下，auto_increment的初始值是 1，每新增一条记录，字段值自动加 1。
 一个表中只能有一个字段使用 auto_increment约束，且该字段必须有唯一索引，以避免序号重复（即为主键或主键
的一部分）。
 auto_increment约束的字段必须具备 NOT NULL 属性。（主键本身就非空）
 auto_increment约束的字段只能是整数类型（TINYINT、SMALLINT、INT、BIGINT 等。
 auto_increment约束字段的最大值受该字段的数据类型约束，如果达到上限，auto_increment就会失效。
*/

--  指定自增字段初始值
-- 方式1-创建表时指定

use mydb1;
create table t_user2 (
id int primary key auto_increment,
name varchar(20)
)auto_increment=100;

insert into t_user2 values(null, 'zhangsan');
insert into t_user2(name) values('lisi');


-- 方式二-创建表之后修改的时候指定
create table t_user3 (
id int primary key auto_increment,
name varchar(20)
);
alter table t_user3 auto_increment=100;

insert into t_user3 values(null, 'wangwu');

-- 注意：
-- 	 delete和truncate在删除后自增列的变化：
--  delete数据之后自动增长从断点开始
--  truncate数据之后自动增长从默认起始值开始

-- 测试delete
delete from t_user2;

insert into t_user2 values(null, 'zhangsan');
insert into t_user2(name) values('lisi');

-- 测试truncate
TRUNCATE t_user3;

insert into t_user3 values(null, 'zhaoliu');


-- 三、非空约束

-- 概念

-- MySQL 非空约束（not null）指字段的值不能为空。对于使用了非空约束的字段，如果用户在添加数据时没
-- 有指定值，数据库系统就会报错。

-- 语法：

-- 方式1：<字段名><数据类型> not null;

-- 方式1，创建表时指定
create table t_user6 (
id int,
name varchar(20) not null,
address varchar(20) not null
);

insert into t_user6 values(1, 'zhaoliu', '南通大街');

insert into t_user6 values(1, 'zhaoliu', null);		# 不可以

insert into t_user6 values(1, '', '');		# 空串是可以的
	

-- 方式2：alter table 表名 modify 字段 类型 not null;

create table t_user7 (
id int,
name varchar(20) , -- 指定非空约束
address varchar(20) -- 指定非空约束
);
alter table t_user7 modify name varchar(20) not null;
alter table t_user7 modify address varchar(20) not null;

insert into t_user7 values(1, 'zhaoliu', '哈工程');

insert into t_user7 values(1, 'zhaoliu', null);

desc t_user7;		# 用于查看表结构的语句

-- 删除非空约束

-- alter table 表名 modify 字段 类型
alter table t_user7 modify name varchar(20);
alter table t_user7 modify address varchar(20);

insert into t_user7 values(10, 'zhaoliu', null);



-- 四、唯一约束

-- 概念

-- 唯一约束（Unique Key）是指所有记录中字段的值不能重复出现。
-- 例如，为 id 字段加上唯一性约束后，每条记录的 id 值都是唯一的，不能出现重复的情况。

-- 语法

-- 方式1：<字段名> <数据类型> unique

-- 创建表时指定
create table t_user8 (
id int ,
name varchar(20) ,
phone_number varchar(20) unique -- 指定唯一约束
);

desc t_user8;

insert into t_user8 values(1, 'zhaoliu', 123456123);
insert into t_user8 values(2, 'zhaoliu', 123123);

insert into t_user8 values(2, 'zhaoliu', null);
insert into t_user8 values(3, 'zhaoliu', null);    # mysql中null与任何值(包括自己)都不相同


-- 方式2： alter table 表名 add constraint 约束名 unique(列);

create table t_user9 (
id int ,
name varchar(20) ,
phone_number varchar(20) -- 指定唯一约束
);
alter table t_user9 CONSTRAINT unique_ph add unique(phone_number);

insert into t_user9 values(1, 'zhaoliu', 123456123);
insert into t_user9 values(2, 'zhaoliu', 123456123);

-- 删除唯一约束

-- alter table <表名> drop index <唯一约束名>;
alter table t_user9 drop index unique_ph;
alter table t_user9 drop index phone_number;



-- 五、默认约束

-- 概念
-- MySQL 默认值约束用来指定某列的默认值。

-- 语法

-- 方式1： <字段名> <数据类型> default <默认值>;

create table t_user10 (
id int ,
name varchar(20) ,
address varchar(20) default '北京' -- 指定默认约束
);

insert into t_user10(id, name, address) values(1, 'zhaoliu', '南京');
insert into t_user10(id, name) values(3, 'zhaoliu');

insert into t_user10 values(3, 'zhaoliu', null);


-- 方式2: alter table 表名 modify 列名 类型 default 默认值;

-- alter table 表名 modify 列名 类型 default 默认值;
create table t_user11 (
id int ,
name varchar(20) ,
address varchar(20)
);
alter table t_user11 modify address varchar(20) default 'beijing';

-- 删除默认约束

-- alter table <表名> modify column <字段名> <类型> default null; 
alter table t_user11 modify column address varchar(20) default null;



-- 六、零填充约束

-- 概念

-- 1、插入数据时，当该字段的值的长度小于定义的长度时，会在该值的前面补上相应的0
-- 2、zerofill默认为int(10)
-- 3、当使用zerofill 时，默认会自动加unsigned（无符号）属性，使用unsigned属性后，数值范围是原
-- 值的2倍，例如，有符号为-128~+127，无符号为0~256。

-- 语法

create table t_user12 (
id int zerofill , -- 零填充约束
name varchar(20)
);

insert into t_user12 values(1, 'zhaoliu');

-- 删除零填充约束
alter table t_user12 modify id int;

insert into t_user12 values(1123, 'zhaoliu');
