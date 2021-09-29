/*
以缩排形式表示基层和衍生层的关系。这里所谓的衍生，并非继承而是复合

序列式容器：
array(与vector均为连续空间)
vector
    heap  以算法形式呈现(xxx_heap())
        priority_queue
list   双向
slist  单向，非标准
deque  分段连续空间
    stack  与queue均为container adapter
    queue

关联式容器：
rb_tree（红黑树）   非公开
    set
    map
    multiset
    multimap
hashtable          非公开
    hash_set       非标准
    hash_map       非标准 
    hash_multiset  非标准
    hash_multimap  非标准

C++11标准中，slist改名为forward_list
hash_改名为unordered_

*/