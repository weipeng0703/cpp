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
#include <sample.cpp>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime> 
#include <algorithm> 	//sort()
using namespace std;
using std::cin;
using std::cout;
using std::string;

namespace jj02
{
void test_vector(long& value)
{
	cout << "\ntest_vector().......... \n";
     
vector<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {       						// try catch 防止异常，通过abort退出程序  
    		snprintf(buf, 10, "%d", rand());
        	c.push_back(string(buf));     // vector 扩充空间时以当前空间作两倍扩展   		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			     //曾經最高 i=58389486 then std::bad_alloc
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "vector.max_size()= " << c.max_size() << endl;	//1073747823
	cout << "vector.size()= " << c.size() << endl;		
	cout << "vector.front()= " << c.front() << endl;	
	cout << "vector.back()= " << c.back() << endl;	
	cout << "vector.data()= " << c.data() << endl;
	cout << "vector.capacity()= " << c.capacity() << endl << endl;		

																				
string target = get_a_target_string();
    {
	timeStart = clock();
auto pItem = ::find(c.begin(), c.end(), target);   // find()传回的是一个iterator,使用auto自动确定其类型
	// 标准库的查找算法为循序渐进顺序查找
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;  
	 
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl << endl;
    }

	{
	timeStart = clock();
	
    sort(c.begin(), c.end());
	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl; 
	
	timeStart = clock();	    
	// bsearch为二分查找，按理说 速度比find()快很多
string* pItem = (string*)::bsearch(&target, (c.data()), 
                                   c.size(), sizeof(string), compareStrings); 
	cout << "bsearch(), milli-seconds : " << (clock()-timeStart) << endl; 
	   
  	if (pItem != NULL)
    	cout << "found, " << *pItem << endl << endl;
  	else
    	cout << "not found! " << endl << endl;	
	}
	
	c.clear();
	test_moveable(vector<MyString>(),vector<MyStrNoMove>(), value);	
}	
}
