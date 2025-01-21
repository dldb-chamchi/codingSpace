//바이러스

#include <iostream>
#include <vector>

std::vector<int> graph[101];
int visit[101];

void dfs(int i){
    if(visit[i]) return; //조기 종료 
    visit[i] = 1;
    for(auto n : graph[i]){
        if(visit[n]) continue;
        dfs(n);
    }
}

int main (){
    int N, M; //컴퓨터 수, 간선 수
    std::cin >> N >> M;
    for(int i{0}; i<M; ++i){
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    int sum{0};
    for(int i{1}; i<=N; ++i){
        sum += visit[i];
    }

    std::cout << sum-1;

    return 0;
}