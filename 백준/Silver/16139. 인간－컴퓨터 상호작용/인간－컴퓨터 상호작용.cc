//백준 16139, 인간-컴퓨터 상호작용

#include <iostream>

int freq[200'001][26];

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s;
    int N;

    std::cin >> s;

    for(int i{0}; i<s.length(); ++i){
        for(int j{0}; j<26; ++j){
            freq[i+1][j] = freq[i][j];
        }
        ++freq[i+1][s[i]-'a'];
    }

    char alpha; int l, r;

    std::cin >> N;

    while(N--){
        std::cin >> alpha >> l >> r;
        std::cout << freq[r+1][alpha-'a'] - freq[l][alpha-'a'] << '\n';
    }

    return 0;
}