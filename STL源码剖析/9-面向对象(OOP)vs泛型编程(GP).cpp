/*
OOP(Objecte-Oriented Programming)面向对象将datas与methods关联在一起
例如：数据存取与sort()均存在于class内

GP(Generic Programming)泛型编程是将datas与methods分开
例如vector与deque容器中都可以存放数据，但是存在一个全局的sort()存在于<algorithm>中，二者通过Iterator联系在一起
Algorithm通过Iterators确定操作范围并取用container中的元素
例如 methods内的小于 min 方法，它不需要管container的类型，如果container中的元素为石头class，则他类内通过
operator< 重载定义自己的小于方法;
*/






