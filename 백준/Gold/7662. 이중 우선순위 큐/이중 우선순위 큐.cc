//백준 7662, 이중 우선순위 큐

#include <iostream>
#include <set>

int main (){

    int T, N;
    std::cin >> T;
    while(T--){
        std::multiset<int> set;
        std::cin >> N;
        char a; int b;
        for(int i{0}; i<N; ++i){
            std::cin >> a >> b;
            if(a == 'I'){
                set.insert(b);
            }
            else{
                if(set.empty()) continue;
                else if(b == -1) set.erase(set.begin());
                else set.erase(std::prev(set.end()));
            }
        }
        if(set.empty()) std::cout << "EMPTY" << '\n';
        else std::cout << *std::prev(set.end()) << ' ' << *set.begin() << '\n';
    }

    return 0;
}