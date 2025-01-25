//백준 10816, 숫자 카드 2

#include <iostream>
#include <map>

std::map<int, int> map;

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M;

    std::cin >> N;

    for(int i{0}; i<N; ++i){
        int n;
        std::cin >> n;
        if(map.find(n) != map.end()) ++map[n];
        else map[n] = 1;
    }

    std::cin >> M;

    for(int i{0}; i<M; ++i){
        int m;
        std::cin >> m;
        auto it = map.find(m);
        if(it != map.end()) std::cout << it->second;
        else std::cout << 0;
        std::cout << ' ';
    }

    return 0;
}