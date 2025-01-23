//백준 7785, 회사에 있는 사람
#include <iostream>
#include <map>

std::map<std::string, bool> map;

int main(){

    int N;
    std::cin >> N;
    std::string name, state;
    for(int i{0}; i<N; ++i){
        std::cin >> name >> state;
        if(map.find(name) != map.end()){
            if(state == "enter") map[name] = 1;
            else map[name] = 0;
        }
        else{
            if(state == "enter") map[name] = 1;
            else map[name] = 0; 
        }
    }
    
    for(auto it{map.rbegin()}; it != map.rend(); ++it){
        if(it->second == 1) std::cout << it->first << '\n';
    }

    return 0;
}