//백준 11047, 동전 0

#include <iostream>
#include <vector>
#include <queue>

int main(){
    
    int N, K;
    std::cin >> N >> K;
    int v[N];

    for(int i{0}; i<N; ++i) std::cin >> v[i];

    int k = K;
    int cnt{0};
    
    for(int i{N-1}; i>=0; --i){
        if(k == 0) break;
        if(k / v[i] == 0) continue;
        cnt += k/v[i];
        k = k - v[i] * (k/v[i]);
    }

    std::cout << cnt;
    return 0;
}