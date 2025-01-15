//백준 2167, 2차원 배열의 합

#include <iostream>

int main(){

    int N, M;
    std::cin >> N >> M;
    int grid[305][305] = {0};

    for(int i{1}; i<=N; ++i){
        for(int j{1}; j<=M; ++j){
            std::cin >> grid[i][j];
        }
    }
    
    int T; std::cin >> T;
    while(T--){
        int i, j, x, y;
        int ans{0};
        std::cin >> i >> j >> x >> y;
        for(int col{i}; col<=x; ++col){
            for(int row{j}; row<=y; ++row){
                ans += grid[col][row];
            }
        }
        std::cout << ans << '\n';
    }
    
    return 0;
}