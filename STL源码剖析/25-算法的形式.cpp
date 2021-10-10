/*
STL的六大部件：
容器，迭代器，仿函数，适配器，分配器都为class template
只有算法是function template

algorithms看不见containers，对其一无所知，所以它所需的一切信息都必须从iterator是取得；
iterators必须能够回答algorithm的所有提问，才能搭配该algorithm的所有操作
每个算法必须接收两个iterator

*/