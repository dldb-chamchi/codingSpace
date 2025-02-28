//백준 16974, 레벨 햄버거

#include <iostream>
using ll = long long;

ll N, X;
ll dp[51]; //버거 길이
ll p[51]; //패티 개수

ll recur(ll n, ll x){
    if(n == 0) return x;

    if(x == 1) return 0;
    else if(x <= 1 + dp[n-1]) return recur(n-1, x-1);
    else if(x == 1 + dp[n-1] + 1) return p[n-1] + 1;
    else if(x <= dp[n-1]*2 + 2) return p[n-1] + 1 + recur(n-1, x-dp[n-1]-2);
    else return p[n];
}

int main (){

    std::cin >> N >> X;

    dp[0] = 1; p[0] = 1;
    
    for(ll i{1}; i<=N; ++i){
        dp[i] = 1 + dp[i-1] + 1 + dp[i-1] + 1;
        p[i] = 2*p[i-1] + 1;
    }

    std::cout << recur(N, X);

    return 0;
}