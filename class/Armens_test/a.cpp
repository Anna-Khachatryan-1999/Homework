#include<iostream>
template <typename T>
class A
{
public:
    class B
    {
    };
public:
    B f();
};

template <typename T>
typename A<T>::B A<T>::f() {
    return B{};
}
int main()
{
    return 0;
}


