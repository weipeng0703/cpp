// 题目
/*
各种排序算法及时间复杂度
*/

// 解答
/*
1、冒泡排序：
从数组中第一个数开始，依次遍历数组中的每一个数，通过相邻比较交换，每一轮循环下来找出剩余未排序数的中的最大数并“冒泡”至数列的顶端。

稳定性：稳定

平均时间复杂度：O(n ^ 2)

2、插入排序：

从待排序的n个记录中的第二个记录开始，依次与前面的记录比较并寻找插入的位置，每次外循环结束后，将当前的数插入到合适的位置。

稳定性：稳定

平均时间复杂度：O(n ^ 2)

3、希尔排序（缩小增量排序）：

希尔排序法是对相邻指定距离(称为增量)的元素进行比较，并不断把增量缩小至1，完成排序。

希尔排序开始时增量较大，分组较多，每组的记录数目较少，故在各组内采用直接插入排序较快，后来增量di逐渐缩小，分组数减少，各组的记录数增多，但由于已经按di−1分组排序，文件叫接近于有序状态，所以新的一趟排序过程较快。因此希尔 排序在效率上比直接插入排序有较大的改进。

在直接插入排序的基础上，将直接插入排序中的1全部改变成增量d即可，因为希尔排序最后一轮的增量d就为1。

稳定性：不稳定

平均时间复杂度：希尔排序算法的时间复杂度分析比较复杂，实际所需的时间取决于各次排序时增量的个数和增量的取值。时间复杂度在O(n ^ 1.3)到O(n ^ 2)之间。

4、选择排序：

从所有记录中选出最小的一个数据元素与第一个位置的记录交换；然后在剩下的记录当中再找最小的与第二个位置的记录交换，循环到只剩下最后一个数据元素为止。

稳定性：不稳定

平均时间复杂度：O(n ^ 2)

5、快速排序

1）从待排序的n个记录中任意选取一个记录（通常选取第一个记录）为分区标准;

2）把所有小于该排序列的记录移动到左边，把所有大于该排序码的记录移动到右边，中间放所选记录，称之为第一趟排序；

3）然后对前后两个子序列分别重复上述过程，直到所有记录都排好序。

稳定性：不稳定

平均时间复杂度：O(nlogn)

6、堆排序：

堆：

1、完全二叉树或者是近似完全二叉树。

2、大顶堆：父节点不小于子节点键值，小顶堆：父节点不大于子节点键值。左右孩子没有大小的顺序。

堆排序在选择排序的基础上提出的，步骤：

1、建立堆

2、删除堆顶元素，同时交换堆顶元素和最后一个元素，再重新调整堆结构，直至全部删除堆中元素。

稳定性：不稳定

平均时间复杂度：O(nlogn)

7、归并排序：

采用分治思想，现将序列分为一个个子序列，对子序列进行排序合并，直至整个序列有序。

稳定性：稳定

平均时间复杂度：O(nlogn)

8、计数排序：

思想：如果比元素x小的元素个数有n个，则元素x排序后位置为n+1。

步骤：

1）找出待排序的数组中最大的元素；

2）统计数组中每个值为i的元素出现的次数，存入数组C的第i项；

3）对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；

4）反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。

稳定性：稳定

时间复杂度：O(n+k)，k是待排序数的范围。

9、桶排序：

步骤：

1）设置一个定量的数组当作空桶子； 常见的排序算法及其复杂度：

2）寻访序列，并且把记录一个一个放到对应的桶子去；

3）对每个不是空的桶子进行排序。

4）从不是空的桶子里把项目再放回原来的序列中。

时间复杂度：O(n+C) ，C为桶内排序时间。


*/