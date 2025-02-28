//백준 10844, 쉬운 계단 수

#include <iostream>
#define mod 1'000'000'000 
using ll = long long;

ll dp[101][10];

int main (){

    int N;
    std::cin >> N;

    
    for(int j{1}; j<10; ++j){
        dp[1][j] = 1;
    }
    

    for(int i{2}; i<=N; ++i){
        for(int j{0}; j<10; ++j){
            if(j == 0) dp[i][j] = dp[i-1][j+1]%mod;
            else if(j == 9) dp[i][j] = dp[i-1][j-1]%mod;
            else{
                dp[i][j] = dp[i-1][j-1]%mod + dp[i-1][j+1]%mod;
            }
        }
    }
    ll sum = 0;
    for(int i{0}; i<10; ++i){
        sum = sum%mod + dp[N][i]%mod;
    }

    std::cout << sum%mod;

    return 0;
}