//백준 1932, 정수 삼각형

#include <iostream>

int arr[505][505];
int dp[505][505];

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    for(int i{1}; i<=N; ++i){
        for(int j{1}; j<=i; ++j){
            std::cin >> arr[i][j];
        }
    }

    dp[1][1] = arr[1][1];

    for(int i{2}; i<= N; ++i){
        for(int j{1}; j<=i; ++j){
            dp[i][j] = std::max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }
    
    int max{0};
    for(int i{1}; i<=N; ++i){
        max = std::max(dp[N][i], max);
    }
    
    std::cout << max;

    return 0;
}