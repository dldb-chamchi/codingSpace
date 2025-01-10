//백준 1260, DFS와 BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, V;
std::vector<int> graph[1001];
std::queue<int> q;
bool visit1[1001];
bool visit2[1001];

void dfs(int k){
    visit1[k] = true;
    std::cout << k << ' ';
    for(auto c : graph[k]){
        if(visit1[c]) continue;
        dfs(c);
    }
}

void bfs(){
    visit2[V] = true;
    q.push(V);
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        std::cout << curr << ' ';
        for(auto c : graph[curr]){
            if(visit2[c]) continue;
            visit2[c] = true;
            q.push(c);
        }
    }
}

int main(){
    
    std::cin >> N >> M >> V;

    for(int i{0}; i<M; ++i){
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i{1}; i<=N; ++i){
        std::sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    std::cout << '\n';
    bfs();
    
    
    return 0;
}