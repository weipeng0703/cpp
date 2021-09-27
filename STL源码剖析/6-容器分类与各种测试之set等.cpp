/*
(multi)set
(multi)set使用insert()插入数据，插入数据时就已经对其按照特定的顺序进行排序了
set.find()的速度比全局下的.find()快很多
故如果目标需求在于后面的查找速度的话，可以考虑关联式容器，其构造、插入的速度很慢，但是查找速度很快
(multi)set的key = value,vlaue = key

(multi)map<type1, type2>
使用key去寻找value
插入数据时，要使用pair<>()对插入数据
map.insert(pair<tupe1, type2>())
注意：multimap不可以用[]去做insert插入，而map可以

unordered_(multi)set
底层使用HashTable实现
当放入元素大于等于篮子个数的时候，会自动扩充一倍篮子的数量，已经插入的数据会重新打算在自动分配到不同的篮子上
在查找的时候，查找bucket时很快，在每个bucket内查找时是循序查找

unordered_(multi)map


*/