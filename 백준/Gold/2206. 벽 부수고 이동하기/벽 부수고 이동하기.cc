//백준 2206, 벽 부수고 이동하기

#include <iostream>
#include <queue>
#include <tuple>

int N, M;
int grid[1005][1005];
int visit[1005][1005][2];
int dist[1005][1005][2];

std::queue<std::tuple<int, int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(){
    q.push({1, 1, 0});
    visit[1][1][0] = 1;
    dist[1][1][0] = 1;

    while(!q.empty()){
        auto [x, y, broken] = q.front(); q.pop();

        if(x == N && y == M) return dist[x][y][broken];
        
        for(int i{0}; i<4; ++i){
            int nx = x+ dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if(grid[nx][ny] == 0 && !visit[nx][ny][broken]){
                visit[nx][ny][broken] = 1;
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }
            else if(grid[nx][ny] == 1 && broken == 0){
                visit[nx][ny][1] = 1;
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}


int main (){

    std::cin >> N >> M;
    
    for(int i{1}; i<=N; ++i){
        std::string row;
        std::cin >> row;
        for(int j{1}; j<=M; ++j){
            grid[i][j] = row[j-1] - '0';
        }
    }

    std::cout << bfs();

    return 0;
}