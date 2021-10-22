#include<iostream>
#include<assert.h>
#include<cstring>
using namespace std;

char* strcpy(char *dst,const char *src)   //[1]
{
    assert(dst != NULL && src != NULL);    //[2]
 
    char *ret = dst;  //[3]
 
    while ((*dst++ = *src++) !='\0'); //[4]
 
    return ret;
}

/*
1.防止源字符串src被修改，源字符串参数用const修饰
2.检查指针的有效性与防空
    （1）若检查指针的有效性时使用assert(!dst && !src);
    char *转换为bool即是类型隐式转换，这种功能虽然灵活，但更多的是导致出错概率增大和维护成本升高。
    
    （2）检查指针的有效性时使用assert(dst != 0 && src != 0);
    直接使用常量（如本例中的0）会减少程序的可维护性。
    而使用NULL代替0，如果出现拼写错误，编译器就会检查出来。
3.因为目标指针在复制的过程中移动，所以使用另一个辅助指针ret记录目标指针原来的首位置
4.将原指针src的值挨个赋值给目的指针dst，直到遇到'\0'

*/

/*
但是对于上面的代码：
char s[10]="hello";

strcpy(s, s+1); //应返回ello，

strcpy(s+1, s); //应返回hhello，但实际会报错，因为dst与src重叠了，把'\0'覆盖了
所谓重叠，就是src未处理的部分已经被dst给覆盖了，只有一种情况：src<=dst<=src+strlen(src)

C函数memcpy自带内存重叠检测功能，下面是memcpy的实现及完整正确的strcpy()
*/

// 扩展——假如考虑dst和src内存重叠的情况，strcpy该怎么实现

char* my_memcpy(char* dst, const char* src, int cnt)
{
    assert(dst != NULL && src != NULL);
 
    char* ret = dst; 
 
    if (dst >= src && dst <= src+cnt-1) //内存重叠的情况，从高地址开始复制
    {
        dst = dst+cnt-1;
        src = src+cnt-1;
        while (cnt--)
            *dst-- = *src--;
    }
    else    //正常情况，从低地址开始复制
    {
        while (cnt--)
            *dst++ = *src++;
    }
    
    return ret;
}

char* strcpy(char* dst,const char* src)
{
    assert(dst != NULL && src != NULL);
 
    char* ret = dst;
 
    my_memcpy(dst, src, strlen(src)+1);
 
    return ret;
}