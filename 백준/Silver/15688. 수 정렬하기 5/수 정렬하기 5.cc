//백준 15688, 수 정렬하기 5

#include <iostream>
#include <algorithm>

int plus[1'000'001];
int minus [1'000'001];

int main (){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, n;
    std::cin >> N;
    for(int i{0}; i<N; ++i){
        std::cin >> n;
        if(n < 0) ++minus[std::abs(n)];
        else ++plus[n];
    }

    for(int i{1'000'000}; i>0; --i){
        for(int j{0}; j<minus[i]; ++j){
            std::cout << -i << '\n';
        }
    }

    for(int i{0}; i<1'000'001; ++i){
        for(int j{0}; j<plus[i]; ++j){
            std::cout << i << '\n';
        }
    }


    return 0;
}