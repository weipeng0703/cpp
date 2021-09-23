// 尽可能使用const

// const出现在 * 左边：被指物是常量
// const出现在 * 右边：被指物是指针
// const出现在 * 两边：被指物和指针二者均是常量

// 若被指物是常量，const可以写在类型之前，也可将其写在类型之后，*之前，两种写法意义相同
// void f1(const widget * pw)
// void f2(widget cosnt * pw)


#include<vector>
using namespace std;

vector<int> vec;
const vector<int>::iterator it = vec.begin();

// *it = 10;
// ++it;

vector<int>::const_iterator iter = vec.begin();

// *iter = 10;
// ++iter;

