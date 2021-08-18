// **作用：**布尔数据类型代表真或假的值

// bool类型只有两个值：

// true — 真（本质是1）
// false — 假（本质是0）
// bool类型占1个字节大小

// 注意，除了0外其他输入均为1

#include<iostream>
#include<string>  
using namespace std;

int main(){
    
    bool flag = true;
    cout << flag << endl;
    cout << sizeof(flag) << endl;

    return 0;
}