//백준 1080, 행렬
#include <iostream>

int gridA[51][51];
int gridB[51][51];

int main(){

    int N, M;

    std::cin >> N >> M;

    std::string s;
    for(int i{0}; i<N; ++i){
        std::cin >> s;
        for(int j{0}; j<M; ++j){
            gridA[i][j] = s[j]-'0';
        }
    }

    for(int i{0}; i<N; ++i){
        std::cin >> s;
        for(int j{0}; j<M; ++j){
            gridB[i][j] = s[j]-'0';
        }
    }

    int cnt{0};
    for(int i{0}; i<N-2; ++i){
        for(int j{0}; j<M-2; ++j){
            if(gridA[i][j] != gridB[i][j]){
                for(int k{i}; k<=i+2; ++k){
                    for(int l{j}; l<=j+2; ++l){
                        gridA[k][l] ^= 1;
                    }
                }
                ++cnt;
            }
        }
    }

    for(int i{0}; i<N; ++i){
        for(int j{0}; j<M; ++j){
            if(gridA[i][j] != gridB[i][j]){
                std::cout << -1;
                return 0;
            }
        }
    }

    std::cout << cnt;

    return 0;
}