//백준 1780, 종이의 개수

#include <iostream>
#include <vector>
#include <queue>

int N;
int grid[3000][3000];
int zero{0}; int one{0}; int minus{0};

bool check(int n, int x, int y){
    int init = grid[x][y];
    for(int i{x}; i<x+n; ++i){
        for(int j{y}; j<y+n; ++j){
            if(grid[i][j] != init) return false;
        }
    }
    return true;
}

void recur(int n, int x, int y){
    if(check(n, x, y)){
        if(grid[x][y] == -1) ++minus;
        else if(grid[x][y] == 0) ++zero;
        else ++one;
    }
    else{
        int half3 = n/3;
        recur(half3, x, y);
        recur(half3, x, y+half3);
        recur(half3, x, y+2*half3);

        recur(half3, x+half3, y);
        recur(half3, x+half3, y+half3);
        recur(half3, x+half3, y+2*half3);

        recur(half3, x+2*half3, y);
        recur(half3, x+2*half3, y+half3);
        recur(half3, x+2*half3, y+2*half3);
        
    }
}

int main(){
    
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        for(int j{0}; j<N; ++j){
            std::cin >> grid[i][j];
        }
    }
    
    recur(N, 0, 0);

    std::cout << minus << '\n' << zero << '\n' << one;
    return 0;
}