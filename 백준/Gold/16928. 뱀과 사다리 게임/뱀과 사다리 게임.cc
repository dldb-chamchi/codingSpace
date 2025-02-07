//백준 16928, 뱀과 사다리 게임

#include <iostream>
#include <queue>

int dist[101];
int map[101];

void bfs(){
    std::queue<int> q;
    dist[1] = 1;
    q.push(1);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(int i{1}; i<=6; ++i){
            int nx = curr + i;
            if(nx > 100) continue;
            if(dist[nx] > 0 || dist[map[nx]] > 0) continue;
            if(map[nx] != 0){
                q.push(map[nx]);
                dist[map[nx]] = dist[curr] + 1;
            }
            else{
                q.push(nx);
                dist[nx] = dist[curr] + 1;
            }
        }
    }
}

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M;
    std::cin >> N >> M;
    
    int x, y;
    for(int i{0}; i<N; ++i){
        std::cin >> x >> y;
        map[x] = y;
    }
    
    int u, v;
    for(int i{0}; i<M; ++i){
        std::cin >> u >> v;
        map[u] = v;
    }

    bfs();
    std::cout << dist[100]-1;

    return 0;
}