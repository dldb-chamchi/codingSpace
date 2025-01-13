//백준 12919, A와 B 2

#include <iostream>
#include <algorithm>

std::string s, t;
bool flag = false;

void recur(std::string ans){
    if(ans == s){
        flag = true;
        return;
    }
    if(s.size() >= ans.size()) return;
    if(ans.back() == 'A'){
        recur(ans.substr(0, ans.size()-1));
    }
    if(ans.front() == 'B'){
        auto tmp = ans.substr(1);
        std::reverse(tmp.begin(), tmp.end());
        recur(tmp);
    }
}

int main(){

    std::cin >> s;
    std::cin >> t;
    recur(t);
    std::cout << (flag ? 1 : 0);
    return 0;
}