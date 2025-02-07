//백준 12852, 1로 만들기 2

#include <iostream>

int dp[1'000'001];
int pre[1'000'001];

int main (){
    int N;
    std::cin >> N;

    for(int i{2}; i<=N; ++i){
        dp[i] = dp[i-1] + 1;
        pre[i] = i-1;
        
        if(i%2 == 0 && dp[i] > dp[i/2] +1){
            dp[i] = dp[i/2] + 1;
            pre[i] = i/2;
        }
        
        if(i%3==0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            pre[i] = i/3;
        }
    }

    std::cout << dp[N] << '\n';

    int curr = N;
    while(true){
        std::cout << curr << ' ';
        if(curr == 1) break;
        curr = pre[curr];     
    }
    

    return 0;
}