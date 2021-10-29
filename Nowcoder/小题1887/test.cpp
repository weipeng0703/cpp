#include <iostream> 
using namespace std;
class A {
    float *p;  int n;
public: 
    A(int s){ n=s;  p=new float[n];}
    ~A() {delete p;} 
    int Getn() const {  return n; }
    // float & operator[](int i) {  return p[i];} 
    float & operator[](int i) {  return *(p + i);} 

    void Print() {
        int i; 
        for(i=0;i< this->Getn();i++) 
            {cout<<p[i];}  
    }
};
int main() {
    A a(5); 
    for (int i=0;i<a.Getn();i++) 
        a[i] = i + 1; 
    a.Print(); 
    return 0;
}