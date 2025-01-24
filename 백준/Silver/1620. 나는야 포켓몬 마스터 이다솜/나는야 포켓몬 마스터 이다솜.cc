//백준 1620, 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> nameNum;
std::unordered_map<std::string, std::string> numName;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::string s;
    std::cin >> N >> M;

    for(int i{0}; i<N; ++i){
        std::cin >> s;
        nameNum[s] = std::to_string(i+1);
        numName[std::to_string(i+1)] = s;
    }

    for(int i{0}; i<M; ++i){
        std::cin >> s;
        auto it1 = nameNum.find(s);
        auto it2 = numName.find(s);
        if(it1 != nameNum.end()){
            std::cout << it1->second << '\n';
        }
        else if(it2 !=numName.end()){
            std::cout << it2->second << '\n';
        }
    }

    return 0;
}