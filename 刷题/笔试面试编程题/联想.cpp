/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-28 18:57:51
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-28 18:58:09
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 09:17:15
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-28 18:57:43
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<memory>
#include <time.h>
#include<unordered_map>
#include<queue>
using namespace std;

// 1-笔试
/*
小A和小B都是搬砖人，因为各自的身体素质不同，所以他们为自己制定了不同的小目标。
小A可以一次搬a1块砖，但是每搬一次就要休息b1分钟，他的目标是一天搬c1块砖;
同样的，小B可以一次搬a2块砖，但是每搬一次就要休息b2分钟，他的目标是一天搬c2块砖。

每个人情况不同，只要完成自己的目标就好，已知某天小A和小B同时开始搬砖，请问他们谁先完成自己的目标？
如果是小A则输出‘A’，如果是小B则输出‘B’，如果两个人同时完成，则输出‘A&B’。

输入描述
第一行是一个整数T，表示数据组数（1≤T≤100）
接下来T行，每行有六个正整数a1,b1,c1,a2,b2,c2,含义如题所示。(a1,b1,c1,a2,b2,c2<=10^9)

输出描述
输出包含T行，每行一个字符串如题所示。

样例输入
2
7 9 19 9 1 89
7 9 95 4 5 9
样例输出
B
B
*/
# include<iostream>

int main() {

    int T = 0;
    long long a1, b1, c1;
    long long a2, b2, c2;
    long long time1, time2;
    long long cost1, cost2;
    // 输入数据组
    std::cin >> T;
    while (T > 0) {
        T--;
        // 输入一组数据
        std:: cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        
        cost1 = c1 / a1 * b1;
        cost2 = c2 / a2 * b2;
        if (cost1 < cost2) {
            std::cout << "A" << std:: endl;
        } else if (cost1 > cost2) {
            std::cout << "B" << std:: endl;
        } else {
            std::cout << "A&B" << std:: endl;
        }
    }
    return 0;
}






# include<bits/stdc++.h>
char s[100005];     // 输入
int cnt_b[100005];  // 左起蓝色数量
int cnt_r[100005];  // 左起红色数量
int main() {

    int n;
    std::cin >> n;
    std::cin >> (s + 1);
    cnt_b[0] = 0;
    cnt_r[0] = 0;
    for (int i = 1; i <= n; i++) {
        cnt_b[i] = cnt_b[i - 1];
        cnt_r[i] = cnt_r[i - 1];
        if (s[i] == 'b') cnt_b[i]++;
        else cnt_r[i]++;
    }
    int ans = min(cnt_r[n], cnt_b[n]);  // 全是同一个色
    for (int i = 2; i <= n - 1; i++) {
        int temp1 = cnt_r[i - 1] + cnt_b[n] - cnt_b[i];
        int temp2 = cnt_b[i - 1] + cnt_r[n] - cnt_r[i];
        ans = min(ans, min(temp1, temp2));
    }
    std::cout << ans << std::endl;
    return 0;
}


