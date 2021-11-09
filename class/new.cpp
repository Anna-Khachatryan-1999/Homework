#include <iostream>

class Person
{
public:
    /*Person operator+(const Person& p)
    {
        Person p1;
        std::cout << "sovorakan" << std::endl;
        return p1;
    }*/
    friend Person operator+(const Person& p1, const Person& p2);
private:
    int x;
};
Person operator+(const Person& p1, const Person& p2)
{
        Person p3;
        std::cout << "global" << std::endl;
        return p3;
}
/*class Student : public Person
{
public:
    void foo() {
        std::cout << "Student foo" << std::endl;
    }
private:
    int y;
};*/
int main()
{
    Person p1;
    Person p2;
    Person p3 = p1 + p2;
return 0;
}
