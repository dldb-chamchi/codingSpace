//백준 2740, 행렬 곱셈

#include <iostream>

int matrix1[101][101];
int matrix2[101][101];

int main (){

    int N, M, K;
    std::cin >> N >> M;
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<M; ++j){
            std::cin >> matrix1[i][j];
        }
    }

    std::cin >> M >> K;
    for(int i{0}; i<M; ++i){
        for(int j{0}; j<K; ++j){
            std::cin >> matrix2[i][j];
        }
    }

    for(int i{0}; i<N; ++i){
        for(int j{0}; j<K; ++j){
            int tmp = 0;
            for(int k{0}; k<M; ++k){
                tmp += matrix1[i][k] * matrix2[k][j];
            }
            std::cout << tmp << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}