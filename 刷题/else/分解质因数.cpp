#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

void prim(int m, int n)   // 分解质因数
 {
     if (m >= n)
     {
         while (m % n) 
            n++;
         m /= n;
         prim(m, n);
         cout << n << endl;
     }
 }

int main(){
    prim(24, 2);
    return 0;
}

/*

*/