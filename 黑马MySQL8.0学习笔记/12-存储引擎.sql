-- 查看所有的执行引擎

show engines;

-- 重点关注MyISAM（MYSQL5.5之前的存储引擎）与InnoDB（MYSQL5.5之后的默认存储引擎）

/*
• MyISAM：Mysql 5.5之前的默认数据库引擎，最为常用。拥有较高的插入，查询速度，但不支持事务
• InnoDB：事务型速记的首选引擎，支持ACID事务，支持行级锁定，MySQL5.5后成为默认数据库引擎
• Memory： 所有数据置于内存的存储引擎，拥有极高的插入，更新和查询效率。但是会占用和数据量成正比的
内存空间。并且其内容会在MYSQL重新启动是会丢失。
• Archive ：非常适合存储大量的独立的，作为历史记录的数据。因为它们不经常被读取。Archive 拥有高效的插
入速度，但其对查询的支持相对较差
• Federated ：将不同的 MySQL 服务器联合起来，逻辑上组成一个完整的数据库。非常适合分布式应用
*/

-- 查询当前数据库支持的存储引擎：
show engines;

-- 查看当前的默认存储引擎：
show variables like '%storage_engine%';

-- 查看某个表用了什么引擎(在显示结果里参数engine后面的就表示该表当前用的存储引擎): 
show create table mydb5.student;

CREATE TABLE `student` (
  `sid` int NOT NULL,
  `card_id` varchar(20) DEFAULT NULL,
  `name` varchar(20) DEFAULT NULL,
  `gender` varchar(20) DEFAULT NULL,
  `age` int DEFAULT NULL,
  `birth` date DEFAULT NULL,
  `phone_num` varchar(20) DEFAULT NULL,
  `score` double DEFAULT NULL,
  PRIMARY KEY (`sid`),
  UNIQUE KEY `index_phone_name_2` (`phone_num`,`name`),
  KEY `index_name` (`name`),
  KEY `index_gender` (`gender`),
  KEY `index_age` (`age`),
  KEY `index_phone_name` (`phone_num`,`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci



-- 创建新表时指定存储引擎：
create table(...) engine=MyISAM;

-- 修改数据库引擎
alter table student engine = INNODB;
alter table student engine = MyISAM;


-- 修改MySQL默认存储引擎方法

-- 	1. 关闭mysql服务
-- 	2. 找到mysql安装目录下的my.ini文件：
-- 	3. 找到default-storage-engine=INNODB 改为目标引擎，
-- 	如：default-storage-engine=MYISAM 
-- 	4. 启动mysql服务

