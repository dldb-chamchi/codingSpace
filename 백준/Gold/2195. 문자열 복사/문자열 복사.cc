//백준 2195, 문자열 복사

#include <iostream>
#include <vector>

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s, p;

    std::cin >> s >> p;

    int cnt{0};

    for(int i{0}; i<p.length();){
        int max{0};
        for(int j{0}; j<s.length(); ++j){
            int tmp{0};
            while(p[i+tmp] == s[j+tmp]){
                ++tmp;
            }
            max = std::max(max, tmp);
        }
        i += max;
        ++cnt;
    }
    
    std::cout << cnt;

    return 0;
}