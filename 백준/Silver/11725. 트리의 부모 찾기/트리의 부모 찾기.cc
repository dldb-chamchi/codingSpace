//백준 11725, 트리의 부모 찾기

#include <iostream>
#include <vector>

std::vector<int> graph[100'001];
int visit[100'001];
int parents[100'001];

void dfs(int k){
    visit[k] = true;
    for(auto g : graph[k]){
        if(visit[g]) continue;
        visit[g] = true;
        parents[g] = k; 
        dfs(g);
    }
}

int main (){

    int N;
    std::cin >> N;

    for(int i{1}; i<N; ++i){
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    for(int i{2}; i<=N; ++i) std::cout << parents[i] << '\n';

    return 0;
}