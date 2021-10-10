// 通过使用引用形参，允许函数改变一个或多个实参的值

#include<iostream>
#include<string>
using namespace std;

void reset(int &i)
{
    i = 0;
}

int main()
{   
    int j = 42;
    cout << "传值引用之前j = " << j << endl;
    reset(j);

    cout << "传值引用之后j = " << j << endl;

    return 0;
}

// 使用引用避免拷贝
// 拷贝大的类类型对象或者容器对象比较低效，甚至有的类类型（包括 IO 类型在内）根本就不支持拷贝操作。
// 当某种类型不支持拷贝操作时，函数只能通过引用形参访问该类型的对象。
// 举个例子，我们准备编写一个函数比较两个 string 对象的长度。
// 因为 string对象可能会非常长，所以应该尽量避免直接拷贝它们，这时使用引用形参是比较明智的选择。
// 又因为比较长度无须改变 string 对象的内容，所以把形参定义成对常量的引用

// 当函数无需改变引用形参的值时，最好将其声明为 常量引用
bool compare(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

// 使用引用形参返回额外信息

// 一个函数只能返回一个值，然而有时函数需要同时返回多个值，
// 引用形参为我们一次返回多个结果提供了有效的途径。
// 举个例子，我们定义一个名为find char的函数，
// 它返回在string对象中某个指定字符第一次出现的位置。
// 同时，我们也希望函数能返回该字符出现的总次数。
// 该如何定义函数使得它能够既返回位置也返回出现次数呢?
// 一种方法是定义一个新的数据类型，让它包含位置和数量两个成员。
// 还有另一种更简单的方法，我们可以给函数传入一个额外的引用实参，令其保存字符出现的次数∶

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
                if (ret == s.size())
                {
                    ret = i;
                    ++occurs;
                }
                
        }
        
    }
    return ret;
    
}

// auto index = find_char(s, "o", ctr);
// 调用完成后，如果 string对象中确实存在o，那么 ctr的值就是o出现的次数，
// index 指向 o第一次出现的位置;
// 否则如果 string 对象中没有o，index 等于s.size（）而ctr等于0。



