//백준 2798, 블랙잭
#include <iostream>
#include <climits>

int card[101];
int main(){

    int N, M;

    std::cin >> N >> M;

    for(int i{0}; i<N; ++i){
        std::cin >> card[i];
    }
    int min{INT_MAX}; 
    for(int i{0}; i<N-2; ++i){
        for(int j{i+1}; j<N-1; ++j){
            for(int k{j+1}; k<N; ++k){
                int val = card[i] + card[j] + card[k];
                if(val <= M) min = std::min(min, M-val);
            }
        }
    }

    std::cout << M-min;

    return 0;
}
