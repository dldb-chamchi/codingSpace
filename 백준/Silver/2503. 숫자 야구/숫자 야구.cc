#include <iostream>
#include <string>
#include <algorithm>

bool arr[1'000];

int main() {
    int N, strike, ball;
    std::string num;

    std::cin >> N;

    std::fill(arr, arr + 1000, true);

    for (int i{123}; i <= 987; ++i) {
        std::string tmp = std::to_string(i);
        if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) arr[i] = false;
        if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') arr[i] = false;
    }

    for (int i{0}; i < N; ++i) {
        std::cin >> num >> strike >> ball;
        for (int j{123}; j <= 987; ++j) {
            int sCnt{0}, bCnt{0};
            std::string tmp = std::to_string(j);

            if (arr[j]) {
                for (int k{0}; k < 3; ++k) {
                    for (int l{0}; l < 3; ++l) {
                        if (k == l && tmp[k] == num[l]) ++sCnt;
                        if (k != l && tmp[k] == num[l]) ++bCnt;
                    }
                }
                if (sCnt != strike || bCnt != ball) arr[j] = false;
            }
        }
    }

    int cnt{0};
    for (int i{123}; i <= 987; ++i) {
        if (arr[i]) ++cnt;
    }

    std::cout << cnt;

    return 0;
}
