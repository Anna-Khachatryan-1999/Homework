#include <iostream>
#include <string>

void stringCompression (std::string& str)
{
    int index = 0;
    int count = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == str[index]) {
            if(count == 1) {
                index = i;
            } else {
                str.erase(str.begin() + i);
                --i;
            }
            ++count;
        } else if (count != 1) {
            str[index] = char(count + '0');
            count = 1;
            index = i;
        } else {
            ++index;
        }
    }
    if (count != 1) {
            str[index] = char(count + '0');
    }
}

int main()
{
    std::string str;
    std::cin >> str;
    stringCompression(str);
    std::cout << str << std::endl;
    return 0;
}
