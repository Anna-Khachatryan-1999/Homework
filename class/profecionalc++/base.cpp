#include <iostream>
/*class Something
{
    public:
        Something() { std::cout << "2"; }
        virtual ~Something() { std::cout << "2"; }
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
       // virtual ~Derived() { std::cout << "3"; }
        // ~Something() override { std::cout << "3"; };
         ~Base(){ std::cout << "3"; };
    private:
        Something m_dataMember;
};
*/


class Base
{
public:
   virtual void someMethod() {
        std::cout << "B metod" << std::endl;
   }
protected:
    int m_protectedInt;
private:
    int m_private {0};
};

class Derived : public Base
{
public:
    void someOtherMethod() {
        //m_protectedInt = 6;
        std::cout << m_protectedInt << std::endl;
    }
    void someMethod() override {
        std::cout << "D metod" << std::endl;
    }
};


int main()
{
    /*Base b;
    b.someMethod();
    Derived d;
    d.someMethod();
    Base &b1 (d);
    b1.someMethod();
    Base* base (new Derived{});
    delete base;*/
    Derived myDerived;
    Base& ref { myDerived};
    ref.someMethod();
    // Calls Derived's version of someMethod()
   // myDerived.someOtherMethod();
    //ref.someOtherMethod();          //no-no
    return 0;
}
