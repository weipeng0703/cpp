/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
    输入: "A man, a plan, a canal: Panama"
    输出: true
    解释："amanaplanacanalpanama" 是回文串
示例 2:
    输入: "race a car"
    输出: false
    解释："raceacar" 不是回文串
*/
#include<string>
using namespace std;

// 1.使用reverse方法比较原字符串与颠倒字符串比较
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch : s)
        // isalnum() 函数用来检测一个字符是否是字母或者十进制数字。
        // 如果仅仅检测一个字符是否是字母，可以使用 isalpha() 函数；
        // 如果仅仅检测一个字符是否是十进制数字，可以使用 isdigit() 函数。
        // 如果一个字符被 isalpha() 或者 isdigit() 检测后返回“真”，那么它被 isalnum() 检测后也一定会返回“真”。
        // 标准 ASCII 编码共包含了 128 个字符，不同的字符属于不同的分类   
            if (isalnum(ch))
            {
                // tolower()函数是把字符串都转化为小写字母
                // touppre()函数是把字符串都转化为大写字母
                sgood += tolower(ch);
            }
        // c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素
        // c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
        string good_rev(sgood.rbegin(), sgood.rend());
        return sgood == good_rev;
        
    }
};

// 2.双指针法
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char ch : s)
        {
            if (isalnum(ch))
            {
                str += tolower(ch);
            }
        }

        int left = 0, right = str.size() - 1;
        while (left != right)
        {
            if (str[left] != str[right])
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;  
    }
};

// 3.