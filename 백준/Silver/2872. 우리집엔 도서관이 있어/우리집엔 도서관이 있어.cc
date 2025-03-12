#include <iostream>

int arr[300'000];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    int target = N;
    int cnt = 0;

    // 뒤에서부터 연속된 숫자 개수 세기
    for (int i = N - 1; i >= 0; --i) {
        if (arr[i] == target) {
            --target;
            ++cnt;
        }
    }

    std::cout << N - cnt;
    return 0;
}
