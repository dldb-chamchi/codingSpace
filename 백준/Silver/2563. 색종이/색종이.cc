//백준 2563, 색종이
#include <iostream>

int main(){
    int grid[100][100] = {0};
    int n;
    std::cin >> n;
    while(n--){
        int x, y;
        std::cin >> x >> y;
        for(int i{y}; i<y+10; ++i){
            for(int j{x}; j<x+10; ++j){
                grid[i][j] = 1;
            }
        }
    }
    int ans{0};
    for(int i{0}; i<100; ++i){
            for(int j{0}; j<100; ++j){
                if(grid[i][j] == 1) ++ ans;
            }
        }

    std::cout << ans;


    return 0;
}