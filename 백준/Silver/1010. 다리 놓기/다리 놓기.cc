//백준 1010, 다리 놓기

#include <iostream>

int main (){

    long long T;
    std::cin >> T;
    while(T--){
        long long N, M;
        std::cin >> N >> M;
        long long ans{1}; long div{1};
        if(M-N >= N){
            for(auto i{M-N+1}; i<=M; ++i){
                ans *= i;
            }
            for(auto i{1}; i<=N; ++i){
                div *= i;
            }
            std::cout << ans/div << '\n';
        }
        else{
            for(auto i{N+1}; i<=M; ++i){
                ans *= i;
            }
            for(auto i{1}; i<=M-N; ++i){
                div *= i;
            }
            std::cout << ans/div << '\n';
        }
    }

    return 0;
}