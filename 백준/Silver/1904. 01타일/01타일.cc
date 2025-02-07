//백준 1904, 01타일

#include <iostream>

int dp[1'000'001];

int main (){

    int N;
    std::cin >> N;
    dp[1] = 1; dp[2] = 2;
    for(int i{3}; i<=N; ++i){
        dp[i] = dp[i-1]%15746 + dp[i-2]%15746;
    }

    std::cout << dp[N]%15746 << '\n';

    return 0;
}