//백준 20920, 영단어 암기는 괴로워

#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

int N, M;
std::set<std::string> set;
std::map<std::string, int> map;
std::vector<std::string> vec;

//a가 B보다 앞에 올때 true
bool solve(std::string a, std::string b){
    auto cntA = map.find(a)->second; 
    auto cntB = map.find(b)->second;
    if(cntA != cntB){
        return cntA > cntB;
    }
    else if(a.length() != b.length()){
        return a.length() > b.length();
    }
    else{
        return a < b;
    }

}

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    
    for(int i{0}; i<N; ++i){
        std::string s;
        std::cin >> s;
        if(s.length() < M) continue;
        if(map.find(s) != map.end()) ++map[s];
        else map[s] = 1;
        set.insert(s);
    }

    for(auto n : set) vec.push_back(n);

    std::sort(vec.begin(), vec.end(), solve);
    for(auto n : vec) std::cout << n << '\n';

    return 0;
}