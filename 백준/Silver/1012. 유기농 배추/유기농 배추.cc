//백준 1012, 유기농 배추

#include <iostream>
#include <queue>

int grid[51][51];
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j){
    std::queue<std::pair<int, int>> q;
    grid[i][j] = 0;
    q.push({i, j});
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        for(int k{0}; k<4; ++k){
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(grid[nx][ny] != 1) continue;
            
            grid[nx][ny] = 0;
            q.push({nx, ny}); 
        }
    }
}

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, K;
    std::cin >> T;

    while(T--){
        int cnt = 0;
        std::cin >> M >> N >> K;
        for(int i{0}; i<M; ++i){
            for(int j{0}; j<N; ++j){
                grid[i][j] = 0;
            }
        }
        for(int k{0}; k<K; ++k){
            int x, y;
            std::cin >> x >> y;
            grid[x][y] = 1;
        }
        for(int i{0}; i<M; ++i){
            for(int j{0}; j<N; ++j){
                if(grid[i][j] == 1){
                    ++cnt;
                    bfs(i, j);
                }
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}