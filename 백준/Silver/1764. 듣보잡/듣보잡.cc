//백준 1764, 듣보잡

#include <iostream>
#include <map>

std::map<std::string, int> map;

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::string s;
    std::cin >> N >> M;

    for(int i{0}; i<N; ++i){
        std::cin >> s;
        map[s] = 1;
    }

    for(int i{0}; i<M; ++i){
        std::cin >> s;
        if(map.find(s) != map.end()) ++map[s];
    }
    int ans{0};
    for(auto pair : map){
        if(pair.second > 1){
            ++ans;
        }
    }

    std::cout << ans << '\n';

    for(auto pair : map){
        if(pair.second > 1){
            std::cout << pair.first << '\n';
        }
    }

    return 0;
}