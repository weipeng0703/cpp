#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;
#include <stdio.h>

class Demo {
public:
    Demo():count(0) {}
      ~Demo() {}
 
      void say(const std::string&msg) {
          fprintf(stderr,"%s\n", msg.c_str());
      }   
   private:
      int count;
};
 
int main(int argc, char **argv) {
    Demo* v = NULL;
    v->say("hello world");

    return 0;
}

