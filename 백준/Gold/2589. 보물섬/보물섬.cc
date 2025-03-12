//백준 2589, 보물섬

#include <iostream>
#include <queue>
#include <cstring>

int N, M;
char grid[51][51];


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int i, int j){
    std::queue<std::pair<int, int>> q;
    int dist[51][51];
    std::memset(dist, -1, sizeof(dist));

    dist[i][j] = 0;
    q.push({i, j});

    int max{0};

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int k{0}; k<4; ++k){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
            if(dist[nx][ny] != -1 || grid[nx][ny] != 'L') continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
            max = std::max(max, dist[nx][ny]);
        }
    }
    return max;
}

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    std::string s;
    for(int i{0}; i<N; ++i){
        std::cin >> s;
        for(int j{0}; j<M; ++j){
            grid[i][j] = s[j];
        }
    }

    int ans{0};
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<M; ++j){
            if(grid[i][j] == 'L'){
               ans = std::max(ans, bfs(i, j)); 
            }
        }
    }

    std::cout << ans;

    return 0;
}