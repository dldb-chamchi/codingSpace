//백준 1018, 체스판 다시 칠하기

#include <iostream>
#include <algorithm>

int M, N;
char grid[51][51];

int checkB(int i, int j){
    int change{0};
    for(int x{i}; x<i+8; ++x){
        for(int y{j}; y<j+8; ++y){
            if(x%2 != 0 && y%2 != 0 && grid[x][y] != 'B'){
                ++change;
            }
            else if(x%2 != 0 && y%2 == 0 && grid[x][y] != 'W'){
                ++change;
            }
            else if(x%2 == 0 && y%2 == 0 && grid[x][y] != 'B'){
                ++change;
            }
            else if(x%2 == 0 && y%2 != 0 && grid[x][y] != 'W'){
                ++change;
            }
        }
    }
    return change;
}

int checkW(int i, int j){
    int change{0};
    for(int x{i}; x<i+8; ++x){
        for(int y{j}; y<j+8; ++y){
            if(x%2 != 0 && y%2 != 0 && grid[x][y] != 'W'){
                ++change;
            }
            else if(x%2 != 0 && y%2 == 0 && grid[x][y] != 'B'){
                ++change;
            }
            else if(x%2 == 0 && y%2 == 0 && grid[x][y] != 'W'){
                ++change;
            }
            else if(x%2 == 0 && y%2 != 0 && grid[x][y] != 'B'){
                ++change;
            }
        }
    }
    return change;
}

int main (){

    std::cin >> N >> M;
    for(int i{1}; i<=N; ++i){
        std::string row;
        std::cin >> row;
        for(int j{1}; j<=M; ++j){
            grid[i][j] = row[j-1];
        }
    }

    int min{99999};
    for(int i{1}; i<=N-8+1; ++i){
        for(int j{1}; j<=M-8+1; ++j){
            min = std::min(checkB(i, j), min);
            min = std::min(checkW(i, j), min);
        }
    }

    std::cout << min;

    return 0;
}