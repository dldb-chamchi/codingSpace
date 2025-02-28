//백준 9935, 문자열 폭발

#include <iostream>

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s, boom; std::string tmp = "";
    std::cin >> s;
    std::cin >> boom;
    
    for(int i{0}; i<s.size(); ++i){
        tmp.push_back(s[i]);
        if(tmp.length() >= boom.length()){
            bool flag = true;
            for(int j{0}; j<boom.length(); ++j){
                if(tmp[tmp.length()-j-1] != boom[boom.length()-j-1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                tmp.erase(tmp.end()-boom.length(), tmp.end());
            }
        }
    }

    if(tmp.empty()) std::cout << "FRULA";
    else std::cout << tmp;

    return 0;
}