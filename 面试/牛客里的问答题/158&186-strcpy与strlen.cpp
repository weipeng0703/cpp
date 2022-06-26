// 题目
/*
strcpy和strlen
*/

// 解答
/*
strcpy是字符串拷贝函数，原型：
char *strcpy(char* dest, const char *src);
从src逐字节拷贝到dest，直到遇到'\0'结束，因为没有指定长度，可能会导致拷贝越界，造成缓冲区溢出漏洞,

其安全版本是strncpy函数。
语法
char *strncpy(char *destinin, char *source, int maxlen);
参数
destinin：表示复制的目标字符数组；
source：表示复制的源字符数组；
maxlen：表示复制的字符串长度。

strlen函数是计算字符串长度的函数，返回从开始到'\0'之间的字符个数。

*/