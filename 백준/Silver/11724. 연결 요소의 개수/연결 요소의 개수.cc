#include <iostream>
#include <vector>
#include <queue>

std::vector<int> graph[1001];
int N, M;
bool visit[1001];
int ans{0};

void dfs(int depth){
    visit[depth] = true;
    for(auto c : graph[depth]){
        if(visit[c]) continue;
        dfs(c);
    }
}

int main(){
    
    std::cin >> N >> M;
    for(int i{1}; i<=M; ++i){
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i{1}; i<=N; ++i){
        if(visit[i]) continue;
        visit[i] = true;
        dfs(i);
        ++ans;
        
    }
    std::cout << ans;
    
    return 0;
}   