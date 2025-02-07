//백준 9461, 파도반 수열

#include <iostream>

long long dp[101];

int main (){

    int T, N;
    std::cin >> T;
    
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for(int i{4}; i<=101; ++i){
        dp[i] = dp[i-2] + dp[i-3];
    }
    
    while(T--){
        std::cin >> N;
        std::cout << dp[N] << '\n';
    }

    return 0;
}