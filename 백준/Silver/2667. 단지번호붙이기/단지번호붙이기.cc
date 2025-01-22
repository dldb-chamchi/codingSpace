//백준 2667, 단지번호붙이기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define x first
#define y second

int N;
int grid[30][30];

std::queue<std::pair<int, int>> Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

std::vector<int> answer;

void bfs(int i, int j){
    int ans{0};
    grid[i][j] = 0;
    Q.push({i, j});
    ++ans;
    while(!Q.empty()){
        auto curr = Q.front(); Q.pop();
        for(int k{0}; k<4; ++k){
            int nx = curr.x + dx[k];
            int ny = curr.y + dy[k];
            if(nx >= N || nx < 0 || ny >= N || ny <0) continue;
            if(grid[nx][ny] != 1) continue;
            grid[nx][ny] = 0;
            Q.push({nx, ny});
            ++ans;
        }
    }
    answer.push_back(ans);
}

int main (){

    std::cin >> N;
    
    for(int i{0}; i<N; ++i){
        std::string s;
        std::cin >> s;
        for(int j{0}; j<N; ++j){
            grid[i][j] = s[j]-'0';
        }
    }
    
    int num{0};
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<N; ++j){
            if(grid[i][j] == 1){
                bfs(i, j);
                ++num;
            }
        }
    }

    std::sort(answer.begin(), answer.end());
    std::cout << num << '\n';
    for(auto n : answer) std::cout << n << '\n';

    return 0;
}