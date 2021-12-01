#include<iostream>
using namespace std;


int count_1(int x){
    int count1 = 0;
    while(x){
        count1++;
        x = x & (x-1);       
    }
    return count1;
}

int count_0(int x){
    int count0 = 0;
    while((x+1)){
        count0++;
        x = x | (x+1);       
    }
    return count0;
}
int main(){
    cout << "count_1(2015)=" << count_1(2015) << endl;
    cout << "count_0(2015)=" << count_0(2015) << endl;
    return 0;
}
