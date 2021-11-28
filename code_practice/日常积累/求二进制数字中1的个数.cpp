#include<iostream>
using namespace std;


int count_1(int x){
    int count = 0;
    while(x){
        count++;
        x = x &(x-1);
    }
    return count;
}
int main(){
    cout << "count_1(2015)=" << count_1(2015)<<endl;
}