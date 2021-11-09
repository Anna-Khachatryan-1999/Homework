#include <iostream>
#include "header.h"

#define CALL_WITH_MAX(a, b, c) f((a) > (b) ? (a) : (b))

int f(int a) {
    return a*10;
}

class Text
{
public:
    Text (std::string str) : text{str} {};
    const char& operator[](std::size_t position) const
    {
        std::cout << __LINE__ << std::endl;
        return text[position];
    }
    char& operator[](std::size_t position)
    {
        std::cout << __LINE__ << std::endl;
       return text[position];
    }
private:
    std::string text;
};

int main()
{
    Text t("hello");
    std::cout << t[0] << std::endl;
    const Text t1("hello");
    std::cout << t1[0] << std::endl;
    return 0;
}
