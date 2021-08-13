// **作用：**字符型变量用于显示——单个字符

// 语法：char ch = 'a';

// 注意1：在显示字符型变量时，用 单引号 将字符括起来，不要用双引号

// 注意2：单引号内只能有  一个字符 ，不可以是字符串

// C和C++中字符型变量只占用1个字节。
// 字符型变量并不是把字符本身放到内存中存储，而是将对应的 ASCII编码 放入到存储单元


#include<iostream>
using namespace std;

int main(){
    
    // 1.创建方式
    char ch1 = 'a';
    cout << ch1 << endl;
    cout << sizeof(ch1) << endl;
   
    // 2.所占内存大小
    cout << sizeof(char) << endl;

    // 3.常见错误
    // char ch2 = "b";         //要用单引号
    // char ch3 = 'abasdasd';  //单引号内只能用一个字符
    // cout  << ch3 <<endl;

    // 4.字符型变量对应ASCII编码
    // a - 97
    // A - 65

    char ch2 = 'b';
    cout << ch2 << endl;
    cout << int(ch2) << endl;      //b对应的ASCII编码

    return 0;
}