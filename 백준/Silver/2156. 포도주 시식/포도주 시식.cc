//백준 2156, 포도주 시식

#include <iostream>
#include <algorithm>

int arr[10'001];
int dp[10'001];

int main (){

    int N;
    std::cin >> N;
    for(int i{1}; i <=N; ++i) std::cin >> arr[i];
    
    //6 10 13 9 8 1

    dp[0] = 0; dp[1] = arr[1]; dp[2] = arr[1] + arr[2];
    for(int i{3}; i<=N; ++i){
        dp[i] = std::max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]);
        dp[i] = std::max(dp[i], dp[i-1]);
    }
    std::cout << dp[N];

    return 0;
}