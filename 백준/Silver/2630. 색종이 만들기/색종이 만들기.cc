//백준 2630, 색종이 만들기

#include <iostream>

int N;
int grid[130][130];

int one{0}; int zero{0};

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
        if(grid[x][y] == 1) ++one;
        else ++zero;
    }
    else{
        int half = n/2;
        recur(half, x, y);
        recur(half, x, y+half);
        recur(half, x+half, y);
        recur(half, x+half, y+half);
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
    std::cout << zero << '\n' << one;

    
    return 0;
}