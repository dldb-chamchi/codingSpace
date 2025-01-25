//백준 11728, 배열 합치기
#include <iostream>

int A[1'000'001];
int B[1'000'001];

int main(){

    int N, M;

    std::cin >> N >> M;
    for(int i{0}; i<N; ++i) std::cin >> A[i];
    
    for(int i{0}; i<M; ++i) std::cin >> B[i];
    
    int Aidx{0}; int Bidx{0};
    for(int i{0}; i<N+M; ++i){
        if(Aidx == N) std::cout << B[Bidx++];
        else if(Bidx == M) std::cout << A[Aidx++];
        else if(A[Aidx] > B[Bidx]) std::cout << B[Bidx++];
        else std::cout << A[Aidx++];
        std::cout << ' ';
    }

    return 0;
}