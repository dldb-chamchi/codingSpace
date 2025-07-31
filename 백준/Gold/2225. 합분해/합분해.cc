//백준 2225, 합분해
#include <iostream>

int dp[205][205]; //dp[N][K] N이 얼마일 때 K개로 만들 수 있는 조합

int main(){

    int N, K;
    std::cin >> N >> K;

    // dp[1][1] = 1; dp[1][2] = 2; dp[1][3] = 3; dp[1][4] = 4;
    // dp[2][1] = 1; dp[2][2] = 3; dp[2][3] = 6;

    for(int i{0}; i<=K; ++i){
        dp[1][i] = i;
    }

    for(int i{2}; i<=N; ++i){
        for(int j{1}; j<=K; ++j){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1'000'000'000;
        }
    }

    std::cout << dp[N][K];

    return 0;
}