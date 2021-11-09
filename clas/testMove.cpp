#include <iostream>

class A
{
public:
    A() {};
    void print()
    {
        std::cout << x << std::endl;
    }
private:
    int x;
};

int main()
{
A a;
a.print();
A b = A();
a = A();
return 0;
}
