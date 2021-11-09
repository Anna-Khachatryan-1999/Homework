#include <iostream>

int main()
{
    int* p = new int;
    *p = 99;
    delete p;
   // p = nullptr;
    *p = 4;
    std::cout << p;
    return 0;
}
