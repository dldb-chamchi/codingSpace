//백준 10610, 30
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> num;

int main(){

    std::string s;
    std::cin >> s;

    for(int i{0}; i<s.size(); ++i){
        num.push_back(s[i] - '0');
    }

    std::sort(num.rbegin(), num.rend());

    int sum{0};
    for(int i{0}; i<num.size(); ++i){
        sum += num[i];
    }

    if(sum % 3 != 0) std::cout << -1;
    else if(num[num.size()-1] != 0) std::cout << -1;
    else{
        for(auto c : num) std::cout << c;
    }
    
    return 0;
}