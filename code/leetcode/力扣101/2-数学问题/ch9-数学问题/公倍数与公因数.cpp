// 辗转相除法，可以很方便地求得两个数的最大公因数（greatest common divisor，gcd）；
// 将两个数相乘再除以最大公因数即可得到最小公倍数（least common multiple, lcm）。
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    return b == 0? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    cout << "最大公因数为" << gcd(12, 6) << endl;
    cout << "最小公倍数为" << lcm(12, 6) << endl;

    return 0;
}