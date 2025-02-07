//백준 7562, 나이트의 이동

#include <iostream>
#include <queue>

int I;
int startX, startY;
int endX, endY;
int dist[301][301];

int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

void bfs(int i, int j){
    std::queue<std::pair<int, int>> q;
    dist[i][j] = 1;
    q.push({i, j});
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        for(int i{0}; i<8; ++i){
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if(nx >= I || ny >= I || nx < 0 || ny < 0) continue;
            if(dist[nx][ny] > 0) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[curr.first][curr.second] + 1;
        }
    }
}

int main (){

    int T;
    std::cin >> T;

    while(T--){
        std::cin >> I;
        std::cin >> startX >> startY;
        std::cin >> endX >> endY;
        for(int i{0}; i<301; ++i){
            for(int j{0}; j<301; ++j){
                dist[i][j] = 0;
            }
        }
        bfs(startX, startY);
        std::cout << dist[endX][endY]-1 << '\n';
    }

    return 0;
}