//백준 15651, N과 M(3)

#include <iostream>

int N, M;
int ans[8];

void back(int depth){
    if(depth == M){
        for(int i{0}; i<M; ++i) std::cout << ans[i] << ' ';
        std::cout << '\n';
        return;
    }
    for(int i{1}; i<=N; ++i){
        ans[depth] = i;
        back(depth+1);
    }
}
int main (){

    std::cin >> N >> M;
    back(0);

    return 0;
}