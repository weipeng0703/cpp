#include<iostream>
using namespace std;

int main()
{
    int m = 5;
    if(m++ > 5){        // 先判断m > 5,为false，随后m+=1,m=6
        cout<< m <<endl;
    }
    else{
        cout << --m;      // 此时m=6,--m后，m=5
    }
    
    return 0;
}