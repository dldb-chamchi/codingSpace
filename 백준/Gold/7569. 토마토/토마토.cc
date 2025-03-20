#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

int M, N, H;
int grid[105][105][105];
int dist[105][105][105];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

std::queue<std::tuple<int, int, int>> q;

void bfs() {
    while (!q.empty()) {
        auto [z, x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 6; ++i) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= N || ny >= M || nz >= H || nx < 0 || ny < 0 || nz < 0) continue;
            if (grid[nz][nx][ny] == -1 || dist[nz][nx][ny] >= 0) continue;
            
            grid[nz][nx][ny] = 1;
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
}

int main() {
    std::memset(dist, -1, sizeof(dist));

    std::cin >> M >> N >> H;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                std::cin >> grid[i][j][k];
                if (grid[i][j][k] == 1) {
                    q.push({i, j, k});
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    bfs();  // BFS 수행

    int max_days = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (grid[i][j][k] == 0) {
                    std::cout << -1;
                    return 0;
                }
                max_days = std::max(max_days, dist[i][j][k]);
            }
        }
    }

    std::cout << max_days;
    return 0;
}
