#include <iostream>

void rotateMatrix(int** arr, int n)
{
    for(int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - 1 - i; ++j) {
            int k = arr[i][j];
            arr[i][j] = arr[n-1-j][i];
            arr[n-1-j][i] = arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j] = arr[j][n-1-i];
            arr[j][n-1-i] = k;
        }
    }
}

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "\n######### matrix #########\n\n";
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[i][j];
        }
    }

    rotateMatrix(arr, n);
    std::cout << "\n######### rotate matrix #########\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
