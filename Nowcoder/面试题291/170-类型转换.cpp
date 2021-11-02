// 题目
/*
类型转换
*/

// 解答
/*
reinterpret_cast：可以用于任意类型的指针之间的转换，对转换的结果不做任何保证
dynamic_cast：这种其实也是不被推荐使用的，更多使用static_cast，dynamic本身只能用于存在虚函数的父子关系的强制类型转换，对于指针，转换失败则返回nullptr，对于引用，转换失败会抛出异常
const_cast：
    对于未定义const版本的成员函数，我们通常需要使用const_cast来去除const引用对象的const，完成函数调用。
    另外一种使用方式，结合static_cast，可以在非const版本的成员函数内添加const，调用完const版本的成员函数后，
    再使用const_cast去除const限定。
static_cast：
    完成基础数据类型；
    同一个继承体系中类型的转换；
    任意类型与空指针类型void* 之间的转换。

*/

