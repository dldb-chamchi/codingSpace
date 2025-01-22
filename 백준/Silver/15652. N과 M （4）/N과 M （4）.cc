//백준 15652, N과 M(4)

#include <iostream>

int N, M;
int ans[10];

void back(int depth, int start){
    if(depth == M){
        for(int i{0}; i<M; ++i) std::cout << ans[i] << ' ';
        std::cout << '\n';
        return;
    }
    for(int i{start}; i<=N; ++i){
        ans[depth] = i;
        back(depth+1, i);
    }
}

int main (){

    std::cin >> N >> M;
    
    back(0, 1);

    return 0;
}