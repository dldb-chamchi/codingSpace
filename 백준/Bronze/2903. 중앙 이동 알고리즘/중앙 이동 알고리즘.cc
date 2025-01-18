//백준 2903, 중앙 이동 알고리즘
#include <iostream>

int main(){
    int N;
    int dp[16];
    std::cin >> N;
    dp[1] = 3; dp[2] = 5;
    int pow = 4;
    for(int i{3}; i<=N; ++i){
        dp[i] = dp[i-1] + pow;
        pow *= 2;
    }

    std::cout << dp[N] * dp[N];

    return 0;
}