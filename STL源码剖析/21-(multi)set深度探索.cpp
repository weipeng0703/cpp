/*
二者以红黑树为底层结构，因此有元素自动排序特性，排序的依据就是key
（multi）set的value和key合二为一，value就是key

二者提供遍历操作及iterators，按正常规则（++ite）遍历，就能获得已排序(sorted)状态

不能使用iteraors改变元素值（因为key有其严谨的排列规则）

set元素的key必须独一无二，因此其insert使用的是红黑树的insert_unique()

multiset元素的key可以重复，因此其insert使用的是红黑树的insert_equal()

set的所有操作，都是转呼叫底层红黑树的操作，从这个意义来看，set也可以被称为container adapter
*/