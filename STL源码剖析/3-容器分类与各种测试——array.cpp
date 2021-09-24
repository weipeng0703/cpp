/*
容器的分类：
    序列式（Sequence）
        数组Array:连续空间，前后无法扩充
        vector（类似栈）:起点不可移动，尾部可以自动扩充
        deque（队列）:双向可扩充
        链表List：由双向指针串起
        单向链表forward-list:单向指针串起
    关联式（Associative）:适合快速查找，底层结构为红黑树（高度平衡二分树：树的左右两边会自动调整以达到接近的高度）
        集合(multi)set：key/value不分
        (multi)Map：节点为（key/value）
    不定序（Unordered）：其实本质属于关联式容器，底层为哈希表(separate chaining)
        unordered (multi)set
        unordered (multi)map
*/
//---------------------------------------------------
#include <array>
#include <iostream>
#include <ctime> 
#include <cstdlib> //qsort, bsearch, NULL
using namespace std;
using std::cin;
using std::cout;
using std::string;
#define ASIZE 500000
namespace jj01  
// 创建命名空间jj01，用以跟其他命名空间内的变量进行区分，
// 这样，即使在不同的命名空间内使用相同名称的变量也不会引起歧义
{

long get_a_target_long()
{
    long target=0;

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

string get_a_target_string()
{
long target=0;
char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
  return ( *(long*)a - *(long*)b );
}

int compareStrings(const void* a, const void* b)
{
  if ( *(string*)a > *(string*)b )
     	return 1;
  else if ( *(string*)a < *(string*)b )
     	return -1;  
  else      	
        return 0;  
}


void test_array()
{
	cout << "\ntest_array().......... \n";
     
array<long,ASIZE> c;  	
			
clock_t timeStart = clock();									
    for(long i=0; i< ASIZE; ++i) {
        c[i] = rand(); 
    }
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	//
	cout << "array.size()= " << c.size() << endl;		
	cout << "array.front()= " << c.front() << endl;	
	cout << "array.back()= " << c.back() << endl;	
	cout << "array.data()= " << c.data() << endl;	  // 数组在内存内的首地址
	
long target = get_a_target_long();

	timeStart = clock();
    qsort(c.data(), ASIZE, sizeof(long), compareLongs);
long* pItem = (long*)::bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs); 
	cout << "qsort()+bsearch(), milli-seconds : " << (clock()-timeStart) << endl;	//    
  	if (pItem != NULL)
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
}
}