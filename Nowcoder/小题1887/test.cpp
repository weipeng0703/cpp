#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std;

void print(char *s){ 
    if(*s){
        print(++s);
        printf("%c", *s);  
    }
}

int main(){      
    char str[] = "Geneius";
    print (str);

    return 0;
}  
