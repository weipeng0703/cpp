/*
vector——是一种动态增长的array,他的扩充方式为二倍成长

有三个指针：start与finish指示当前储存的首尾,end_of_storage指向容器的capacity
sizeof(vector) = 上述三个指针的大小 = 3 * sizeof(pointer) = 12
 
 

*/