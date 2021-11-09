#include <iostream>
#include <string>

bool rotateString(std::string s, std::string goal) {
        if (s == goal) return true;
        if (s.size() != goal.size()) return false;
        if (s.size() == goal.size()) {
            std::string ss = goal + goal;
            size_t pos = ss.find(s);
            if (pos != std::string::npos) {
                return true;
            }
            ss = s + s;
            pos = ss.find(goal);
            if (pos != std::string::npos) {
                return true;
            }
        }
        return false;
}

int main()
{
    std::string s;
    std::cout << "s = ";
    std::cin >> s;
    std::string goal;
    std::cout << "goal = ";
    std::cin >> goal;
    std::cout << rotateString(s, goal) << std::endl;
}
