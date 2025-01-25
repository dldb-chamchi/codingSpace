//백준, 11478 서로 다른 부분 문자열의 개수

#include <iostream>
#include <set>

std::set<std::string> set;

int main (){

    std::string s;
    std::cin >> s;
    for(int i{1}; i<=s.size(); ++i){ //길이까지 진행해야지 끝까지 나옴
        for(int j{0}; j<=s.size()-i; ++j){
            set.insert(s.substr(j, i));
        }
    }

    std::cout << set.size();
    
    return 0;
}