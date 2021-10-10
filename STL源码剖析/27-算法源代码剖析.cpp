/*
1.accumulate(累计)
    参数<InputIterator first, InputIterator last, T init, BinaryOperation binary_op>
    最后一个参数可以是标准库内的函数，也可以是用户自定的函数

2.for_each(对区间内的元素做指定的一件事情)
    参数<InputIterator first, InputIterator last, function F>

PS.C++11中for的新形式：
    for(decl:coll){statement}
eg. for(int i:{2,3,4,5,6,7})   // i遍历右边的一堆东西
        {
            cout << i << endl;
        }

3.replace, replace_if, replace_copy

4.count, count_if(std命名空间内的全局函数)
    容器不带成员函数count():array, vector, list, forward_list, deque
    容器带有成员函数count():
    关联式容器：(multi)set, (multi)map, unordered_(multi)set, unordered_(multi)map 尽量使用他们自己的成员函数


5.find, find_if(std命名空间内的全局函数)
    容器不带成员函数find():array, vector, list, forward_list, deque
    容器带有成员函数find():
    关联式容器：(multi)set, (multi)map, unordered_(multi)set, unordered_(multi)map 尽量使用他们自己的成员函数
    
6.sort
    容器带有成员函数sort():list, forward_list
    容器不带成员函数sort():
    关联式容器在构建时已经按序排好：(multi)set, (multi)map, unordered_(multi)set, unordered_(multi)map 尽量使用他们自己的成员函数
    序列式容器：array, vector, deque

关于reverse iterator, rbegin(), rend()

7.binary_search(二分查找，使用对象限定为sorted序列)
lower_bound()与upper_bound()
*/