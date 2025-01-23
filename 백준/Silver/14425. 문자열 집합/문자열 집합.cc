//백준 14425, 문자열 집합
#include <iostream>
#include <set>

std::set<std::string> set;

int main(){

    int N, M;
    std::cin >> N >> M;

    std::string n, m;

    int ans{0};

    for(int i{0}; i<N; ++i){
        std::cin >> n;
        set.insert(n);
    }

    for(int i{0}; i<M; ++i){
        std::cin >> m;
        if(set.find(m) == set.end()) continue;
        ++ans;
    }

    std::cout << ans;

    return 0;
}
