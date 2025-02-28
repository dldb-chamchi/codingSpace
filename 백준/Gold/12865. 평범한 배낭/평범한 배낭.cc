//백준 12865, 평범한 배낭

#include <iostream>

int w[105];
int v[105];
int dp[105][100'005];

int main (){

    int N, K;
    std::cin >> N >> K;
    for(int i{1}; i<=N; ++i){
        std::cin >> w[i] >> v[i];
    }

    for(int i{1}; i<=N; ++i){
        for(int j{1}; j<=K; ++j){
            if(w[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = std::max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
            }
        }
    }

    std::cout << dp[N][K];

    return 0;
}