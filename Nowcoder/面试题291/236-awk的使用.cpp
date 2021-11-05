// 题目
/*
awk的使用
*/

// 解答
/*
1）作用：
样式扫描和处理语言。它允许创建简短的程序，这些程序读取输入文件、为数据排序、处理数据、对输入执行计算以及生成报表，还有无数其他的功能。

2）用法：

awk [-F  field-separator]  'commands'  input-file(s)

4）实例：

1、找到当前文件夹下所有的文件和子文件夹,并显示文件大小

> ls -l | awk '{print $5 "\t" $9}'

读入有'\n'换行符分割的一条记录，然后将记录按指定的域分隔符划分域，填充域。$0则表示所有域,$1表示第一个域,$n表示第n个域。默认域分隔符是"空白键" 或 "[tab]键"。

2、找到当前文件夹下所有的文件和子文件夹，并显示文件大小，并显示排序

> ls -l | awk 'BEGIN {COUNT = -1; print "BEGIN COUNT"}
{COUNT = COUNT + 1; print COUNT"\t"$5"\t"$9}
END {print "END, COUNT = "COUNT}'
先处理BEGIN， 然后进行文本分析，进行第二个{}的操作，分析完进行END操作。

3、找到当前文件夹下所有的子文件夹,并显示排序

> ls -l | awk 'BEGIN {print "BEGIN COUNT"} /4096/{print NR"\t"$5"\t"$9}

END {print "END"}'

* /4096/ 正则匹配式子

* 使用print $NF可以打印出一行中的最后一个字段，使用$(NF-1)则是打印倒数第二个字段，其他以此类推。


*/

