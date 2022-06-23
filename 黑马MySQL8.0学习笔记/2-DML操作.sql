-- DML操作之数据操作

use mydb1;
rename table stu to student;
-- 1.数据插入
-- 格式1	insert into 表 (列名1,列名2,列名3...) values (值1,值2,值3...)； //向表中插入某些
insert into student(sid,name,gender,age,birth,address,score)
			values(1001,'Tom','男',18,'1996-12-23','北京',83.5),
						(1002,'zhangsan','男',18,'1996-12-23','上海',83.5),
						(1003,'lisi','男',18,'1996-12-23','深圳',83.5);
						
insert into student(sid) values(1004);
insert into student(sid+, name) values(1004, 'zhaoliu');
-- 格式2	insert into 表 values (值1,值2,值3...); //向表中插入所有列 	
insert into student values(1001,'张三','男',18,'1996-12-23','北京',83.5),
													(1001,'lisi','男',18,'1996-12-23','北京',83.5),
													(1001,'王五','男',18,'1996-12-23','北京',83.5);
													
-- 2、数据修改
-- 1.第一种 update 表名 set 字段名=值,字段名=值...;
-- 2.第二种 update 表名 set 字段名=值,字段名=值... where 条件

-- 将所有学生的地址修改为重庆
update student set address = '重庆';

-- 将id为1004的学生的地址修改为北京
update student set address = '北京' where sid = 1001;

-- 讲id为1005的学生的地址修改为北京，成绩修成绩修改为100 
update student set address = '广州',score=100 where sid = 1003;
							
-- 3.数据删除

-- delete from 表名 [where 条件];
-- truncate table 表名 或者 truncate 表名

-- 1.删除sid为1004的学生数据
delete from student where sid = 1004;
-- 2.删除表所有数据
delete from student;

-- 3.清空表数据
truncate table student;
truncate student;

													