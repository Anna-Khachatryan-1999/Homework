#include <iostream>

/*class Base
{
public:
    virtual void setF(int t) {
        bla = t;
    }
private:
    int bla;
};

class Derived
{
public:
    void set(int c) {
        int t {foo (c)};
        setF(t);
    }
private:
    static int foo(int x) {
        x = 4;
    }
};
*/
class Something
{
public:
    Something() { std::cout << "2"; }
     ~Something() { std::cout << "2"; }
};
class Base
{
public:
    Base() { std::cout << "1"; }
    virtual ~Base() { std::cout << "1"; }
};
class Derived : public Base
{
public:
    Derived() { std::cout << "3"; }
     ~Derived() { std::cout << "3"; }
private:
    Something m_dataMember;
};

int main()
{
    Base* ptr = new Derived{};
    delete ptr;
    return 0;
}
