// 题目  编写一个函数，作用是把一个char组成的字符串循环右移n个。比如原来是“abcdefghi”如果n=2，移位后应该是“hiabcdefg” 函数头是这样的：
//pStr是指向以'\0'结尾的字符串的指针
//steps是要求移动的n

/*
void LoopMove ( char * pStr, int steps ) 
{ 
 //请填充... 
} 
*/


// 解答
/*
#include<string.h>
#define MAX_LENGTH 555555
using namespace std;

void LoopMove ( char * pStr, int steps ) 
{ 
    if(strlen(pstr) == 0 || steps < 0)
        {
            return;
        }
    int t = steps % strlen(pstr);
    char temp[128];

    memcpy(temp, pstr + strlen(pstr) - t, t);    // 先将原字符串后面的部分移到temp
    memcpy(temp + t, pstr, strlen(pstr) - t);    // 将字符串前面的部分移动到temp里,这样temp里就是完整的顺序颠倒后的pstr了
    memecpy(pstr, temp, strlen(pstr));

}
*/

// 知识点
/*
memcpy()函数功能:将源地址内指定长度的内容拷贝到目的地址
即memcpy(目的地址, 源地址, 字节数)
*/