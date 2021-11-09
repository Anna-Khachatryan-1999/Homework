#include <iostream>
#include <string>

void URLify(std::string& str)
{
    int length = str.size();
    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            str[i] = '%';
            str.insert(i+1, "20");
            i += 2;
        }
    }
}

int main()
{
    std::string str = "Mr John Smith   ";
    URLify(str);
    std::cout << str << std::endl;
    std::getline(std::cin, str);
    URLify(str);
    std::cout << str << std::endl;

}
