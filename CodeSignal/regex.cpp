#include <iostream>
#include <string>
#include <regex>

bool isMAC48Address(std::string inputString)
{
   // regex r{"[0-9A-F]{2}(-[0-9A-F]{2}){5}"};
    std::regex r{"(.*)[A-Z0-9](.*)"};
    return std::regex_match(inputString, r);
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << isMAC48Address(s) << std::endl;

}
