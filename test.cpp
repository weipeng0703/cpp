/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-27 09:44:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-22 20:37:46
 */
# include<vector> 
# include<algorithm>
# include<unordered_map>
# include<string>
# include<stack>
# include<queue>
# include<iostream>
# include<thread>
#include<windows.h>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

# include<vector> 
# include<algorithm>
# include<unordered_map>
# include<string>
# include<stack>
// # include<priority_queue>
# include<iostream>
# include<thread>
#include<windows.h>
#include <cstdlib>
using namespace std;

pthread_mutex_t mutex_A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_B = PTHREAD_MUTEX_INITIALIZER;

//线程函数 A
void *threadA_proc(void *data) {
    printf("thread A waiting get ResourceA \n");
    pthread_mutex_lock(&mutex_A);
    printf("thread A got ResourceA \n");
    
    Sleep(1);
    
    printf("thread A waiting get ResourceB \n");
    pthread_mutex_lock(&mutex_B);
    printf("thread A got ResourceB \n");

    pthread_mutex_unlock(&mutex_B);
    pthread_mutex_unlock(&mutex_A);
    return (void *)0;
}

//线程函数 B
void *threadB_proc(void *data) {
    printf("thread B waiting get ResourceB \n");
    pthread_mutex_lock(&mutex_B);
    printf("thread B got ResourceB \n");
    
    Sleep(1);
    
    printf("thread B waiting  get ResourceA \n");
    pthread_mutex_lock(&mutex_A);
    printf("thread B got ResourceA \n");
    
    pthread_mutex_unlock(&mutex_A);
    pthread_mutex_unlock(&mutex_B);
    return (void *)0;
}

int main() {
    pthread_t tidA, tidB;
    
    //创建两个线程
    pthread_create(&tidA, NULL, threadA_proc, NULL);
    pthread_create(&tidB, NULL, threadB_proc, NULL);
    
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);
    
    printf("exit\n");
    
    return 0;
}