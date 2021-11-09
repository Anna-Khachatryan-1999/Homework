#include <iostream>
#include <string>

bool oneAway(std::string str1, std::string str2)
{
    int size1 = str1.size();
    int size2 = str2.size();
    int count = 0;
    if(std::abs(size1 - size2) > 1) return false;
    int max = (size1 > size2) ? size1 : size2;
    for (int i = 0; i < max; ++i) {
        if(str1[i] != str2[i]) {
            if (count != 0) return false;
            if(size1 > size2) {
                str1.erase(str1.begin() + i);
                --i;
            } else if (size1 < size2) {
                str2.erase(str2.begin() + i);
                --i;
            }
            if (str1.size() != str2.size()) return false;
            ++count;
        }
    }
    return true;
}

int main()
{
    std::string str1;
    std::string str2;
    std::cin >> str1;
    std::cin >> str2;
    std::cout << oneAway(str1, str2) << std::endl;
    return 0;
}
