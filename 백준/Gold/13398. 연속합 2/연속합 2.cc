//백준 13398, 연속합 2

#include <iostream>

int arr[100'005];
int dp[100'005][2];

int main (){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;

    std::cin >> N;

    for(int i{0}; i<N; ++i){
        std::cin >> arr[i];
    }
    dp[0][0] = arr[0]; //0은 안지움
    dp[0][1] = arr[0];

    int max = arr[0];
    
    for(int i{1}; i<N; ++i){
        dp[i][0] = std::max(arr[i], arr[i]+dp[i-1][0]);
        dp[i][1] = std::max(dp[i-1][0], arr[i]+dp[i-1][1]);
        max = std::max(max, std::max(dp[i][0], dp[i][1]));
    }

    std::cout << max;



    return 0;
}