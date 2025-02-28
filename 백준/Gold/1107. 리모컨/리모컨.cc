#include <iostream>
#include <algorithm>
#include <cmath>

int arr[10];

int main() {
    int N, M;
    std::cin >> N >> M;

    for (int i{0}; i < M; ++i) {
        std::cin >> arr[i];
    }

    int minPress = std::abs(N - 100); // +,- 버튼만 사용할 경우

    for (int i{0}; i <= 1000000; ++i) { // 0부터 1000000까지 탐색
        bool flag = false;
        for (int j{0}; j < M; ++j) {
            int x = i;
            do {
                if (x % 10 == arr[j]) { // 고장난 숫자가 포함되면 건너뛰기
                    flag = true;
                    break;
                }
                x /= 10;
            } while (x != 0);
            if (flag) break;
        }
        if (!flag) {
            std::string s = std::to_string(i);
            minPress = std::min(minPress, (int)s.size() + std::abs(N - i));
        }
    }

    std::cout << minPress << "\n";
    return 0;
}
