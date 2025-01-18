//백준 2745, 진법 변환
#include <iostream>
#include <unordered_map>
#include <cmath>

std::unordered_map<char, int> map;
int main(){

    for(char c = '0'; c <= '9'; ++c){
        map[c] = c - '0';
    }

    for(char c = 'A'; c <= 'Z'; ++c){
        map[c] = 10 + (c - 'A');
    }

    std::string s;
    int B;
    
    std::cin >> s >> B;
    int num{1};
    for(int i{0}; i<s.size()-1; ++i){
        num *= B;
    }
    
    int ans{0};
    for(int i{0}; i<s.size(); ++i){
        auto it = map.find(s[i]);
        int n = it -> second;
        ans += num*n;
        num/=B;
    }

    std::cout << ans;


    return 0;
}