#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;
#include <stdio.h>

char * GetWelcome(void){
    char * pcWelcome;
    char * pcNewWelcome;
    pcWelcome = "Welcome to Huawei Test";
    pcNewWelcome = (char *)malloc(strlen(pcWelcome));    //1
    if(NULL == pcNewWelcome){
        return NULL;        //2
    }
    strcpy(pcNewWelcome, pcWelcome);    //3
    return pcNewWelcome;            //4
}