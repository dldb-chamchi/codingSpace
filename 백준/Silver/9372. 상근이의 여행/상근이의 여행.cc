//백준 9372, 상근이의 여행

#include <iostream>

int main (){

    int T, N, M;
    std::cin >> T;
    while(T--){
        std::cin >> N >> M;
        for(int i{0}; i<M; ++i){
            int a, b;
            std::cin >> a >> b;
        }
        std::cout << N-1 << '\n';
    }

    return 0;
}