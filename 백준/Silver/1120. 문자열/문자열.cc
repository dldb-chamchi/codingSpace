//백준 1120, 문자열

#include <iostream>

int main(){

    //adaabc
    //aababbcde

    std::string a, b;

    std::cin >> a >> b;

    auto lenA = a.length();
    auto lenB = b.length();

    if(lenA == lenB){
        int ans{0};
        for(int i{0}; i<lenA; ++i){
            if(a[i] != b[i]) ++ans;
        }
        std::cout << ans;
    }
    else{
        int min{100}; int idx;
        for(int i{0}; i<=lenB-lenA; ++i){
            int ans{0};
            for(int j{0}; j<lenA; ++j){
                if(a[j] != b[j+i]) ++ans;
            }
            min = std::min(min, ans);
        } 
        std::cout << min;
    }
    
    return 0;
}