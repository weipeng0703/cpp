// **关键字：**cin

// 语法： cin >> 变量

#include<iostream>
#include<string>  
using namespace std;

int main(){
    
    // 1.整型
    
    int a = 0;
    cout << "请给整型变量赋值" << endl;
    cin >> a ;
    cout << "此时a=" << a << endl;

    // 2.浮点型

    float b = 3.14f;
    cout << "请给浮点型变量赋值" << endl;
    cin >> b;
    cout << "此时b=" << b << endl;

    // 3.字符型

    char c = 'a';
    cout << "请给字符型变量赋值" << endl;
    cin >> c;
    cout << "此时c=" << c << endl;

    // 4.字符串型

    string d = "cwp";
    cout << "请给字符串型变量赋值" << endl;
    cin >> d;
    cout << "此时d=" << d << endl;

    // 5.布尔型

    bool f = true;
    cout << "请给bool型变量赋值" << endl;
    cin >> f;      // 此时输入的应该是数字
    cout << "此时f=" << f << endl;

    system("pause");
    return 0;
}