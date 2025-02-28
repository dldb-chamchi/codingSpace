//백준 2011, 암호코드

#include <iostream>

#define mod 1'000'000

int dp[5001];

int main (){

    std::string s;
    std::cin >> s;

    if(s[0] == '0'){
        std::cout << 0;
        return 0;
    }

    dp[0] = 1; dp[1] = 1;
    for(int i{2}; i<=s.size(); ++i){
        if(s[i-1] != '0') dp[i] = dp[i-1]%mod;
        int tmp = (s[i-2]-'0')*10 + (s[i-1]-'0');
        if(tmp >= 10 && tmp <= 26) dp[i] += dp[i-2]%mod;
    }

    std::cout << dp[s.size()]%mod;

    return 0;
}