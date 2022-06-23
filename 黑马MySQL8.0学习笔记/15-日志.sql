-- 概念

-- 在任何一种数据库中，都会有各种各样的日志，记录着数据库工作的方方面面，以帮助数据库管理员追踪数据库曾
-- 经发生过的各种事件。MySQL 也不例外。


-- 分类

-- 	错误日志
-- 	二进制日志
-- 	查询日志
-- 	慢查询日志


-- 1. 错误日志

-- 错误日志是 MySQL 中最重要的日志之一，它记录了当 mysqld 启动和停止时，以及服务器在运行过程中发生任何严
-- 重错误时的相关信息。当数据库出现任何故障导致无法正常使用时，可以首先查看此日志。
-- 该日志是默认开启的 ， 默认存放目录为 mysql 的数据目录, 默认的日志文件名为 hostname.err（hostname是主机
-- 名）。

-- 查看日志位置指令

show variables like 'log_error%';


-- 2、二进制日志

-- 概述

/*
二进制日志（BINLOG）记录了所有的 DDL（数据定义语言）语句和 DML（数据操纵语言）语句，但是不包括数
据查询语句。此日志对于灾难时的数据恢复起着极其重要的作用，MySQL的主从复制， 就是通过该binlog实现
的。
二进制日志，MySQl8.0默认已经开启，低版本的MySQL的需要通过配置文件开启，并配置MySQL日志的格式。
Windows系统：my.ini Linux系统:my.cnf
*/

#配置开启binlog日志， 日志的文件前缀为 mysqlbin -----> 生成的文件名如 : mysqlbin.000001,mysqlbin.000002
log_bin=mysqlbin
#配置二进制日志的格式
binlog_format=STATEMENT


-- 日志格式

/*
• STATEMENT
该日志格式在日志文件中记录的都是SQL语句（statement），每一条对数据进行修改的SQL都会记录在日志文件
中，通过Mysql提供的mysqlbinlog工具，可以清晰的查看到每条语句的文本。主从复制的时候，从库（slave）
会将日志解析为原文本，并在从库重新执行一次。
• ROW
该日志格式在日志文件中记录的是每一行的数据变更，而不是记录SQL语句。比如，执行SQL语句 ： update 
tb_book set status='1' , 如果是STATEMENT 日志格式，在日志中会记录一行SQL文件； 如果是ROW，由于是对全
表进行更新，也就是每一行记录都会发生变更，ROW 格式的日志中会记录每一行的数据变更。
• MIXED
混合了STATEMENT 和 ROW两种格式。
*/


-- 查看MySQL是否开启了binlog日志
show variables like 'log_bin';

-- 查看binlog日志的格式
show variables like 'binlog_format';

-- 查看所有日志
show binlog events;

-- 查看最新的日志
show master status;

-- 查询指定的binlog日志
show binlog events in 'binlog.000010';

select * from mydb1.emp2;
select count(*) from mydb1.emp2;
update mydb1.emp2 set salary = 8000;

-- 从指定的位置开始,查看指定的Binlog日志
show binlog events in 'binlog.000010' from 156;

-- 从指定的位置开始,查看指定的Binlog日志,限制查询的条数
show binlog events in 'binlog.000010' from 156 limit 2;

--从指定的位置开始，带有偏移，查看指定的Binlog日志,限制查询的条数
show binlog events in 'binlog.000010' from 666 limit 1, 2;

-- 清空所有的 binlog 日志文件
reset master




-- 3、查询日志

-- 概念

-- • 查询日志中记录了客户端的所有操作语句，而二进制日志不包含查询数据的SQL语句。
-- • 默认情况下， 查询日志是未开启的。如果需要开启查询日志，可以设置以下配置 ：

#该选项用来开启查询日志 ， 可选值 ： 0 或者 1 ； 0 代表关闭， 1 代表开启
general_log=1
#设置日志的文件名 ， 如果没有指定， 默认的文件名为 host_name.log 
general_log_file=file_name


-- 查看MySQL是否开启了查询日志
show variables like 'general_log';

-- 开启查询日志

set global general_log=1;
select * from mydb1.emp2;
select * from mydb6_view.emp;
select count(*) from mydb1.emp2;
select count(*) from mydb6_view.emp;
update mydb1.emp2 set salary = 9000;



-- 4、慢查询日志

-- 概念

-- 慢查询日志记录了所有执行时间超过参数 long_query_time 设置值并且扫描记录数不小于
-- min_examined_row_limit 的所有的SQL语句的日志。long_query_time 默认为 10 秒，最小为 0， 精度可以到微秒。

# 该参数用来控制慢查询日志是否开启， 可取值： 1 和 0 ， 1 代表开启， 0 代表关闭
slow_query_log=1

# 该参数用来指定慢查询日志的文件名
slow_query_log_file=slow_query.log

# 该选项用来配置查询的时间限制， 超过这个时间将认为值慢查询， 将需要进行日志记录， 默认10s
long_query_time=10


-- 查看慢查询日志是否打开
show variables like 'slow_query_log%';

-- 开启慢查询日志
set global slow_query_log = 1;

-- 查看慢查询超时时间
show variables like 'long_query_time%';

-- 示例

select sleep(20);


-- 日志中显示的内容：
/*
# Time: 2022-06-23T07:44:39.473452Z
# User@Host: root[root] @ localhost [::1]  Id:    51
# Query_time: 20.007167  Lock_time: 0.000000 Rows_sent: 1  Rows_examined: 1
use mysql;
SET timestamp=1655970259;
select sleep(20);
*/