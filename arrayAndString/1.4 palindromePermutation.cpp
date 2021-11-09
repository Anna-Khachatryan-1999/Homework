#include <iostream>
#include <string>

bool palindronePermutation(std::string str)
{
    int arr[256]{0};
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') continue;
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ++arr [str[i] - '0' + 32];
        } else {
            ++arr [str[i] - '0'];
        }
    }
    int count = 0;
    for (int i = 0; i < 256; ++i) {
        if (arr[i] % 2 != 0) {
            ++count;
        }
        if (count > 1) return false;
    }
    return true;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::cout << palindronePermutation(str) << std::endl;
}
