//백준 24416, 알고리즘 수업 - 피보나치 수 1

#include <iostream>

int dp[40];

int fib(int n){
    if(n == 1 || n == 2) return 1;
    else return fib(n-1) + fib(n-2);
}

int fibo(int n){
    int sum{0};
    dp[1] = dp[2] = 1;
    for(int i{3}; i<=n; ++i) dp[i] = dp[i-1] + dp[i-2];
    return n-3+1;
}

int main (){

    int N;
    std::cin >> N;
    std::cout << fib(N) << ' ';
    std::cout << fibo(N);

    return 0;
}