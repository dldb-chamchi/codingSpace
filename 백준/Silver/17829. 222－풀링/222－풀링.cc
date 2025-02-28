#include <iostream>
#include <algorithm>

int N;
int grid[1024][1024];

int recur(int k, int x, int y) {
    if (k == 2) {
        int arr[4] = {grid[x][y], grid[x][y + 1], grid[x + 1][y], grid[x + 1][y + 1]};
        std::sort(arr, arr + 4);
        return arr[2]; // 두 번째로 큰 값 반환
    }

    int half = k / 2;
    int values[4] = {
        recur(half, x, y),
        recur(half, x, y + half),
        recur(half, x + half, y),
        recur(half, x + half, y + half)
    };

    std::sort(values, values + 4);
    return values[2]; // 상위 4개 값 중 두 번째로 큰 값 반환
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> grid[i][j];
        }
    }

    std::cout << recur(N, 0, 0) << '\n';

    return 0;
}
