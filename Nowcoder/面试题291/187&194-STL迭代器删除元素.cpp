// 题目
/*
STL迭代器删除不同容器元素的过程
*/

// 解答
/*
1.对于序列容器vector,deque来说，使用erase(iterator)后，后边的每个元素的迭代器都会失效，
但是后边每个元素都会往前移动一个位置，但是erase会返回下一个有效的迭代器；

2.对于关联容器map set来说，使用了erase(iterator)后，当前元素的迭代器失效，但是其结构是红黑树，
删除当前元素不会影响到下一个元素的迭代器，所以在调用erase之前，记录下一个元素的迭代器即可。

3.对于list来说，它使用了不连续分配的内存，并且它的erase方法也会返回下一个有效的iterator，
因此上面两种正确的方法都可以使用。

4.对于unordered_map,在删除时，只会影响被删除元素的迭代器
在插入时，如果发生rehashing,则会导致所有迭代器失效
*/