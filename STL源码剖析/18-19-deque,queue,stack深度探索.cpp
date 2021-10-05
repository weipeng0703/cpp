/*
deque是一个分段连续的容器：连续是假象，分段是事实

iterator分为四个部分：cur first last node
cur指向缓冲区内的某一个元素（会移动）
first与last指出每个缓冲区的边界（不会变），node指针回到控制中心（是一个vector，可以动态增长）

当迭代器走到一个缓冲区的边界时，他都有能力跳到下一个缓冲区

deque很“聪明”：
例如如果插入某个元素，计算他应该插入的位置，如果靠近start他会移动其前面的元素，否则他会移动后面的元素
这样能够减少构造、析构函数带来的开销
*/