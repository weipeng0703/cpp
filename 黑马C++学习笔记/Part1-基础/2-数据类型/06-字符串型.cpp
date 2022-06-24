// 作用：用于表示一串字符

// 1.C风格字符串： char 变量名[] = "字符串值"
// 注意：C风格的字符串要用双引号括起来

// 2.C++风格字符串： string 变量名 = "字符串值"
// 注意：C++风格字符串，需要加入头文件  #include<string>  

#include<iostream>
#include<string>  // C++风格字符串，需要加入头文件
using namespace std;

int main(){
    
    // 1.C语言风格

    char ch[] = "hello world";
    cout << ch <<endl;

    // 2.C++风格

    string str = "hello world";
    cout << str << endl; 

    return 0;
}