// 题目
/*
Linux下怎么得到一个文件的100到200行
*/

// 解答
/*
sed -n '100,200p' inputfile
awk 'NR>=100&&NR<=200{print}' inputfile

head -200 inputfile|tail -100

*/

