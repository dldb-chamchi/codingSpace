//백준 2293, 동전 1
#include <iostream>

int arr[100];
int dp[10'001];

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, K;

    std::cin >> N >> K;

    for(int i{0}; i<N; ++i){
        std::cin >> arr[i];
    }

    dp[0] = 1;
    for(int i{0}; i<N; ++i){
        for(int j{arr[i]}; j<=K; ++j){
            dp[j] += dp[j - arr[i]];
        }
    }

    std::cout << dp[K];

    return 0;
}