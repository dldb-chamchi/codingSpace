//백준 26069, 붙임성 좋은 총총이
#include <iostream>
#include <vector>
#include <set>

std::set<std::string> set;
std::set<std::string> visit;

int main(){

    int N;
    std::cin >> N;
    std::string a; std::string b;
    int ans{0};
    set.insert("ChongChong");
    for(int i{0}; i<N; ++i){
        std::cin >> a >> b;
        if((visit.find(b) == visit.end()) && (set.find(a) != set.end())){
            set.insert(b);
            visit.insert(b);
        }
        if((visit.find(a) == visit.end()) && (set.find(b) != set.end())){
            set.insert(a);
            visit.insert(a);
        }
        if(a == "ChongChong" && set.find(b) == set.end()){
            set.insert(b);
            visit.insert(b);
        }
        if(b == "ChongChong" && set.find(a) == set.end()){
            set.insert(a);
            visit.insert(a);
        }
    }
    
    std::cout << set.size();

    return 0;
}