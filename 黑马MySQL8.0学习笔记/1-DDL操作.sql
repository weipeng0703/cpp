-- 1、DDL操作之数据库操作

-- 查看所有数据库
show databases;

-- 创建数据库
create database mydb1;
create database if not EXISTS mydb1;   # 使数据库语句的使用更安全

-- 切换数据库
use mydb1;

-- 删除数据库
drop database mydb1;
create database if EXISTS mydb1;

-- 修改数据库编码
-- alter database mydb1 character set utf8;
-- 
-- 2、DDL操作之表操作

-- 创建表
use mydb1;
create table if not exists student(
	sid int,
	name varchar(20),
	gender varchar(10),
	age int,
	birth date,
	address varchar(20),
	score double
);

-- 查看当前数据中的所有表
show tables;

-- 查看指定表的创建语句
show create table student;

-- CREATE TABLE `student` (
--   `sid` int DEFAULT NULL,
--   `name` varchar(20) DEFAULT NULL,
--   `gender` varchar(10) DEFAULT NULL,
--   `age` int DEFAULT NULL,
--   `birth` date DEFAULT NULL,
--   `address` varchar(20) DEFAULT NULL,
--   `score` double DEFAULT NULL
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

-- 查看表结构
desc student;

-- 删除表
drop table student;

-- 修改表结构（使用的少）
-- 1.添加列
-- alter table 表名 add 列名 类型(长度) [约束];
#为student表添加一个新的字段为：系别 dept 类型为 varchar(20)
ALTER TABLE student ADD dept VARCHAR(20);

-- 2.修改列名和类型
-- alter table 表名 change 旧列名 新列名 类型(长度) 约束;
#为student表的dept字段更换为department varchar(30)
ALTER TABLE student change dept department VARCHAR(30);

-- 3.删除列
-- alter table 表名 drop 列名;
#删除student表中department这列
ALTER TABLE student DROP department;

-- 4.修改表名
-- rename table 表名 to 新表名;
#将表student改名成 stu
rename table student to stu;
show tables;
