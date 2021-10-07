/*
关联式容器可以看作一个小型的数据库——给定一个key去寻找value
底层支撑为红黑树或哈希表（散列表）

红黑树是高度平衡的二叉搜索树，他的排列有利于search和insert，并保持平衡

他提供遍历操作及iterators：按正常规则(++ite)遍历，就能获得已排序(sorted)状态

不应该使用红黑树的iterators来改变元素的值（元素有严谨的排列规则），编程层面并未阻绝此事

红黑树为set和map服务，map允许元素的data被改变，只有元素的key不可以改变

红黑树提供两种insert操作：insert_unique()与insert_equal()
前者表示节点的key一定要在整个tree中独一无二，否则安插失败；后者表示节点的key可以重复

红黑只以3笔资料表现他自己：node_count(4), header(指针 4), key_compare(1, 可以调整为4 )     9->12
*/