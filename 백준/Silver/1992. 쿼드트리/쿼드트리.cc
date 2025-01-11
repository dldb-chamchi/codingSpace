//백준 1992, 쿼드트리

#include <iostream>

int N;
int grid[100][100];

std::string ans;

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
        if(grid[x][y] == 1) ans.push_back('1');
        else ans.push_back('0');
    }
    else{
        int half = n/2;
        ans.push_back('(');
        recur(half, x, y);
        recur(half, x, y+half);
        recur(half, x+half, y);
        recur(half, x+half, y+half);
        ans.push_back(')');
    }
}

int main(){
    
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        std::string row;
            std::cin >> row;
        for(int j{0}; j<N; ++j){
            grid[i][j] = row[j]-'0';
        }
    }

    recur(N, 0, 0);
    std::cout << ans;


    return 0;
}