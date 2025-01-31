//백준 14889, 스타트와 링크

#include <iostream>
#include <vector>
#include <climits>

int N;
int grid[21][21];
int visit[21];
std::vector<int> start;
std::vector<int> link;
int min{INT_MAX};

void solve(int k, int st){
    if(k == N/2){
        int sum{0};
        for(int i{0}; i<N; ++i){
            if(visit[i]) start.push_back(i);
            else link.push_back(i);
        }
        for(int i{0}; i<N/2; ++i){
            for(int j{i+1}; j<N/2; ++j){
                sum += grid[start[i]][start[j]] + grid[start[j]][start[i]];
                sum -= grid[link[i]][link[j]] + grid[link[j]][link[i]];
            }
        }
        min = std::min(min, std::abs(sum));
        start.clear();
        link.clear();
        return;
    }

    for(int i{st}; i<N; ++i){
        if(visit[i]) continue;
        visit[i] = true;
        solve(k+1, i+1);
        visit[i] = false;
    }
}

int main (){

    std::cin >> N;
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<N; ++j){
            std::cin >> grid[i][j];
        }
    }
    solve(0, 0);
    std::cout << min;

    return 0;
}