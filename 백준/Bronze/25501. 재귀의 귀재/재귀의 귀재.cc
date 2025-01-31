//백준 25501, 재귀의 귀재

#include <iostream>

int recur(std::string_view s, int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 1;
    else return 1 + recur(s, l+1, r-1);
}

bool isPalindrom(std::string_view s, int l, int r){
    if(l >= r) return true;
    else if(s[l] != s[r]) return false;
    else return isPalindrom(s, l+1, r-1);
}

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::string s;
    std::cin >> T;
    
    while(T--){
        std::cin >> s;
        std::cout << isPalindrom(s, 0, s.length()-1) << ' ' << recur(s, 0, s.length()-1) << '\n';    
    }

    return 0;
}