#include <iostream>
#include "stack.h"

int main()
{
    Stack<int> s;
    s.push(12);
    s.push(13);
    s.push(1);
    s.push(15);
    s.push(1123);
    std::cout << s.size() << std::endl;
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    return 0;
}
