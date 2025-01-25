//백준 1269, 대칭 차집합

#include <iostream>
#include <set>

std::set<int> A;
std::set<int> B;

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    int n, m;
    std::cin >> N >> M;
    for(int i{0}; i<N; ++i){
        std::cin >> n;
        A.insert(n);
    }

    for(int i{0}; i<M; ++i){
        std::cin >> m;
        B.insert(m);
    }

    int ans{0};
    for(auto n : A){
        if(B.find(n) == B.end()) ++ans; 
    }

    for(auto n : B){
        if(A.find(n) == A.end()) ++ans; 
    }

    std::cout << ans << '\n';

    return 0;
}