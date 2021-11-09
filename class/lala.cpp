#include <iostream>

class M
{
public:
    M() {std::cout << "M ctor" << std::endl;}
    ~M() {std::cout << "M dtor" << std::endl;}
};

class A
{
public:
    A() {std::cout << "A ctor" << std::endl;}
    ~A() {std::cout << "A dtor" << std::endl;}
};


class B : public A
{
private:
    M obj;
public:
    B() {std::cout << "B ctor" << std::endl;}
    ~B() {std::cout << "B dtor" << std::endl;}
};

int main()
{
    B obj;
    A* obj3 = new B();
    delete obj3;
}
