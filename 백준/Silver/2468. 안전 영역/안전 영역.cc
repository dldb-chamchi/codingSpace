//백준 2468, 안전 영역

#include <iostream>
#include <queue>

int N;
int grid[101][101];
bool tmp[101][101];
std::queue<std::pair<int, int>> q;
int dx[4] = {0, 1, -1 ,0};
int dy[4] = {1, 0, 0, -1};

void bfs(int i, int j){
    tmp[i][j] = 0;
    q.push({i, j});
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        for(int k{0}; k<4; ++k){
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k]; 
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(tmp[nx][ny] != 1) continue;
            tmp[nx][ny] = 0;
            q.push({nx, ny});
        }
    }
}

int main (){

    std::cin >> N;
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<N; ++j){
            std::cin >> grid[i][j];
        }
    }
    int minH = -1; int maxH = 0;
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<N; ++j){
            minH = std::min(minH, grid[i][j]);
            maxH = std::max(maxH, grid[i][j]);
        }
    }
    
    int max = 1;
    for(int h{minH}; h<=maxH; ++h){
        int cnt = 0;
        int hegit = h;
        for(int i{0}; i<N; ++i){
            for(int j{0}; j<N; ++j){
                tmp[i][j] = grid[i][j] > h ? 1 : 0;
            }
        }
        for(int i{0}; i<N; ++i){
            for(int j{0}; j<N; ++j){
                if(tmp[i][j] == 1){
                    ++cnt;
                    bfs(i, j);
                }
            }
        }
        max = std::max(max, cnt);
    }
    std::cout << max;

    return 0;
}