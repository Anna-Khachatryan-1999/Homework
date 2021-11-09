#include <iostream>
#include <vector>

template <typename T>
int binary_search (std::vector<T>& nums, int first, int end, T target) {
        if (first > end) return -1;
        int mid  = (first + end) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            return binary_search (nums, first, mid - 1, target);
        } else {
            return binary_search (nums, mid + 1, end, target);
        }
}

template <typename T>
int search(std::vector<T>& nums, T target) {
        return binary_search (nums, 0, nums.size(), target);
}

int main()
{
    int size;
    std::cout << "input size - ";
    std::cin >> size;
    std::vector<int> nums;
    int elem;
    for (int i = 0; i < size; ++i) {
        std::cin >> elem;
        nums.push_back(elem);
    }
    int key;
    std::cout << "input key - ";
    std::cin >> key;
    std::cout << search<int>(nums, key) << std::endl;
    return 0;
}
