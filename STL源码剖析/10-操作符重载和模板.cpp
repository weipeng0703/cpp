/*
操作符重载：
std::string str = "hello ";
str.operator+=("world");                            // same as str += "world";
operator << (operator << (std::cout, str), '\n');   // same as std::cout << str << "\n";

模板：
类模板(class templates)与函数模板(function templates)、成员模板(member templates)
函数模板可以自动进行实参推导，而类模板不可以，需要明确指明typename T的类型

泛化与特化、偏特化（局部特化）（包括个数或范围上的偏）



*/