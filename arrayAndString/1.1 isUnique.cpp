#include <iostream>
#include <string>


bool isUnique(std::string str)
{
    int arr[256]{0};
    for(int i = 0; i < str.size(); ++i) {
        if (arr[(str[i] - '0')] != 0) {
            return false;
        }
        ++arr[str[i] - '0'];
    }
    return true;
}
int main()
{
    std::string str;
    std::cin >> str;
    if(isUnique(str)){
        std::cout << true << std::endl;
    } else {
        std::cout << false << std::endl;
    }
    return 0;
}
