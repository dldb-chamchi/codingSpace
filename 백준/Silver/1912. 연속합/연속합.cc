//백준 1912, 연속합

#include <iostream>
#include <algorithm>
int dp[100'001];

int main (){

    int N;
    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> dp[i];

    for(int i{1}; i<N; ++i){
        dp[i] = std::max(dp[i], dp[i]+dp[i-1]);
    }

    std::sort(dp, dp+N);
    std::cout << dp[N-1];

    return 0;
}