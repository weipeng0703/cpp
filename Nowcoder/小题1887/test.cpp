#include<stdio.h>
using namespace std;

void func(int *p)
{
    static int num = 4;
    p = &num;
    (*p)--;
}

void func1(int **p)
{
    static int num = 4;
    *p = &num;
    (**p)--;
}
int main()
{
    int i = 5;
    int *p = &i;

    func(p);
    printf("%d\n",*p);

    func1(&p);
    printf("%d",*p);
    return 0;
}