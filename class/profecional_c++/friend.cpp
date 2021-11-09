#include <iostream>

class B
{
public:
    friend class A;
    friend void fooB();
private:
    int x_B;
};
class A
{
public:
    void fooA() {
        B b;
        b.x_B = 1;
        std::cout << b.x_B << std::endl;
    }
private:
    int x_A;
};

void fooB()
{
    B k;
    k.x_B = 14;
    std::cout << k.x_B << std::endl;
}


int main()
{
    B b;
    fooB();
}
