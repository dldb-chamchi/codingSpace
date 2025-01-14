//백준 15650, N과 M(2)
#include <iostream>

int N, M;
int visit[10];
int ans[10];

void back(int depth, int start){
    if(depth == M){
        for(int i{0}; i<M; ++i) std::cout << ans[i] << ' ';
        std::cout << '\n';
        return;
    }
    for(int i{start+1}; i<=N; ++i){
        if(visit[i]) continue;
        visit[i] = true;
        ans[depth] = i;
        back(depth+1, i);
        visit[i] = false;
    }
}

int main(){

    std::cin >> N >> M;
    
    back(0, 0);

    return 0;
}