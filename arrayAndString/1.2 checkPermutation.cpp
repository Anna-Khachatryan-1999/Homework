#include <iostream>
#include <string>
#include <unordered_map>

bool checkPermutation(std::string str1, std::string str2) {
    if (str1.size() != str2.size()) return false;
    std::unordered_map<char, int> map1;
    std::unordered_map<char, int> map2;
    for(int i = 0; i < str1.size(); ++i) {
            ++map1[str1[i]];
    }
    for(int i = 0; i < str2.size(); ++i) {
            ++map2[str2[i]];
    }
   for( const auto& n : map1 ) {
        if(map2[n.first] != n.second) return false;
    }    return true;
}
int main()
{
    std::string str1;
    std::string str2;
    std::cin >> str1;
    std::cin >> str2;
    std::cout << checkPermutation(str1, str2) << std::endl;
    return 0;
}
