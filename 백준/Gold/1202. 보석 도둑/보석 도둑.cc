//백준 1202, 보석 도둑

#include <iostream>
#include <set>
#include <algorithm>

std::pair<int, int> pair[300'000];
std::multiset<int> set;

int main (){

    int N, K;
    std::cin >> N >> K;
    for(int i{0}; i<N; ++i){
        std::cin >> pair[i].second >> pair[i].first;
    }
    std::sort(pair, pair+N);

    int k;
    for(int i{0}; i<K; ++i){
        std::cin >> k;
        set.insert(k);
    }

    long long ans = 0;

    for(int i{N-1}; i>=0; --i){
        int m, v;
        std::tie(v, m) = pair[i];
        auto it = set.lower_bound(m);
        if(it == set.end()) continue;
        ans += v;
        set.erase(it);
    }
    std::cout << ans;

    return 0;
}