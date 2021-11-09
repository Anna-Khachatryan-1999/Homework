#include <iostream>
#include <vector>

void zeroMatrix(int** arr, int n, int m)
{
    if (n == 1 ) {
        if (m == 1) return;
        bool b = false;
        for (int j = 0; j < m; ++j) {
            if (arr[0][j] == 0) {
                b = true;
                break;
            }
        }
        if(b) {
            for (int j = 0; j < m; ++j) {
                arr[0][j] = 0;
            }
        }
        return;
    }
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 0) {
                v.push_back(i);
                v.push_back(j);
            }
        }
    }
    int j = 0;
    while (j < v.size()) {
        for (int i = 0; i < n; ++i) {
            arr[i][v[j+1]] = 0;
        }
        for (int i = 0; i < m; ++i) {
            arr[v[j]][i] = 0;
        }
        j += 2;
    }
}

int main()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;
    int m;
    std::cout << "m = ";
    std::cin >> m;
    std::cout << "\n######### matrix #########\n\n";
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }
    }

    zeroMatrix(arr, n, m);
    std::cout << "\n######### zero matrix #########\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
