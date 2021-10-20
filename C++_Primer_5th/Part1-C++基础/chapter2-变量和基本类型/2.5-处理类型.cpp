// 2.5.1 类型别名
    // 1.使用关键字typedef定义类型别名
    typedef double wage;
    typedef wage base, *p;

    // 2.使用别名声明定义类型的别名
    // using SI = Sales_item;      // 将等号左侧的名字规定为等号右侧类型的别名

    // 类型别名跟类型的名字等价

    // 3.指针、常量和类型别名
    typedef char *pstring;
    const pstring cstr = 0;
    const pstring *ps;
    // pstring是类型char*的别名，实际上是指向char的指针，因此const pstring是指向char的常量指针，而不是指向常量字符的指针
    


// 2.5.2 auto类型说明符（C++11新标准）

    // suto让编译器通过初始值来推算变量的类型，因此auto定义的变量必须有初始值

    // 1.复合类型、常量和auto

    // 使用引用其实是使用引用的对象，特别是当引用被用作初始值时，真正参与初始化的其实是引用对象的值。
    // 此时编译器以引用对象的类型作为 auto 的类型∶

    int i = 0, &r = i;
    auto a = r;     // a是一个整数（r是i的别名，i是一个整数）

    // auto一般会忽略顶层const，同时底层const则会保留下来
    const int ci = i,&cr = ci;
    auto b = ci; // b是一个整数（ci的顶层const特性被忽略掉了）
    auto c = cr; // c是一个整数（cr是 ci的别名，ci本身是一个顶层 const）
    auto d = &i; // d是一个整型指针（整数的地址就是指向整数的指针）
    auto e = &ci;// e是一个指向整数常量的指针（对常量对象取地址是一种底层 const）

    // 如果希望推断出的auto类型是一个顶层const，需要明确指出
    const auto f = ci;

    // 还可以将引用的类型设为auto，此时原来的初始化规则仍然适用

    auto &g = ci;
    // auto &h = 42;       // 错误，不能将非常量引用绑定字面值
    const auto &j = 42;     // 正确， 可以为常量引用绑定字面值

    // 练习2.35
    #include <iostream>
    #include<typeinfo>
    
    int main()
    {
        const int i = 42;
        auto j = i;
        const auto &k = i;
        auto *p = &i;
        const auto j2 = i,&k2 = i;
        std::cout << typeid(i).name() << std::endl;
        std::cout << typeid(j).name() << std::endl;
        std::cout << typeid(k).name() << std::endl;
        std::cout << typeid(p).name () << std::endl;
        std::cout << typeid(j2).name() << std::endl;
        std::cout << typeid(k2).name() << std::endl;
        
        return 0;
    }


// 2.5.3 decltype类型指示符（C++11）

    // 1.
    // C++11 新标准引入了第二种类型说明符decltype，它的作用是选择并返回操作数的数据类型。
    // 在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值

    // decltype(f()) sum = x;
    // 编译器并不实际调用函数f，而是使用当调用发生时f的返回值类型作为sum的类型

    // 如果decltype使用的表达式是一个变量，则其返回该变量的类型（包括顶层const和引用在内）
    
    const int ci = 0, &cj= ci;  // x的类型是 const int 
    decltype(ci) x = 0;  // y的类型是 const int&，y绑定到变量x
    decltype(cj) y = x;
    decltype(cj) z;     // 错误∶z是一个引用，必须初始化

    // 引用从来都作为其所指对象的同义词出现，只有用在decltype处是一个例外


    // 2. decltype和引用

    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;      // 正确，加法的结果是int， 因此b是一个（未经初始化的）int
    decltype(*p) c;         // 错误，c是int&, 必须初始化

    // decltype与auto的一个重要区别：decltype的结果类型与表达式形式密切相关

    // decltype 的表达式如果是加上了括号的变量，结果将是引用
    decltype(i) e;      // 正确，e是一个（未经初始化）的int
    decltype((i)) w;    // 错误，w是int&， 必须初始化

    // 切记∶decltype（（variable））（注意是双层括号）的结果永远是引用，
    // 而decltype（variable）结果只有当 variable 本身就是一个引用时才是引用。


// auto 和 decltype 的区别主要有三个方面∶
    // 第一，auto类型说明符用编译器计算变量的初始值来推断其类型，
    // 而decltype 虽然也让编译器分析表达式并得到它的类型，但是不实际计算表达式的值。

    // 第二，编译器推断出来的 auto类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则。
    // 例如，auto 一般会忽略掉顶层const，而把底层const 保留下来。与之相反，decltype会保留变量的顶层 const。
    
    // 第三，与 auto 不同，decltype 的结果类型与表达式形式密切相关，
    // 如果变量名加上了一对括号，则得到的类型与不加括号时会有不同。
    // 如果 decltype 使用的是一个不加括号的变量，则得到的结果就是该变量的类型;
    // 如果给变量加上了一层或多层括号，则编译器将推断得到引用类型。


