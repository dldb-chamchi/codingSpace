//백준 25192, 인사성 밝은 곰곰이

#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, int> map;

int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::string s;

    int gom{0};
    for(int i{0}; i<N; ++i){
        std::cin >> s;
        if(s == "ENTER"){
            map.clear();
        }
        else{
            if(map.find(s) != map.end()) continue;
            map[s] = 1;
            ++gom;
        }
    }

    std::cout << gom;

    return 0;
}