#include<iostream>
 using namespace std;
 class B
 {
 public:
     B()
     {
         cout << "default constructor" << " ";
     }
     ~B()
     {
         cout << "destructed" << " ";
     }
     B(int i): data(i)
     {
         cout << "constructed by parameter" << data << " ";
     } 
     private: int data;
 }; 
 B Play( B b)
 {
     return b;
 } 
 int main(int argc, char *argv[])
 {
     B temp = Play(5);
     return 0;
 }