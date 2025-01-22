//백준 11050, 이항 계수 1

#include <iostream>

int main (){

    int N, K;
    std::cin >> N >> K;
    int nFact{1}; int n_kFact{1}; int kFact{1};
    for(int i{1}; i<=N; ++i) nFact *= i;
    for(int i{1}; i<=K; ++i) kFact *= i;
    for(int i{1}; i<=N-K; ++i) n_kFact *= i;
    std::cout << nFact / (kFact*n_kFact);

    return 0;
}