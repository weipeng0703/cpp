/*
STL提供了一个全局的sort()方法，对于某些单独的容器，其自身也会有一个sort()算法，当需要对某一个容器进行排序时，
最好使用其自身的sort()方法

注意：forwardlist(前向链表)没有push_back()方法，但是有push_front()，只有一端可以存放
	forwardlist也没有size()方法

forwardlist与slist本质为同一种东西——单向链表，但前者为C++11标准中的，而后者为非标准的，隶属于GLUE编译器

deque双向扩充，分段连续，每次扩充是扩充一个buffer(512)

deque涵盖stack（先进后出）跟queue（先进先出），二者只是借用deque这个容器，所以其被称为容器的adaptor

stack与queue均使用push()放元素，pop（）出元素

*/