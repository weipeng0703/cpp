class A
{
public:
    void foo()
    {
        printf("1");
    }
    virtual void fun()
    {
        printf("2");
    }
};
class B: public A
{
public:
    void foo()
    {
        printf("3");
    }
    void fun()
    {
        printf("4");
    }
};
int main(void)
{
    A a;
    B b;
    A *p = &a;
    p->foo();
    p->fun();


    p = &b;
    p->foo();
    p->fun();

    A *ptr = (A *)&b;
    ptr->foo();
    ptr->fun();
    return 0;
}

	

