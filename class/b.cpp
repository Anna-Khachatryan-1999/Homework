#include <iostream>

class A
{
    public:
        void f(){}
    protected:
        int x;
};

class B: public A
{
    public:
        void k()
        {
            x = 1;
        }
};
int main()
{
    B b;
    b.f();
}
