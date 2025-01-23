//백준 10815, 숫자 카드
#include <iostream>
#include <set>

std::set<int> set;
int card[500'000];
bool ans[500'000];

int main(){

    int N, M;
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        int n;
        std::cin >> n;
        set.insert(n);
    }

    std::cin >> M;

    for(int i{0}; i<M; ++i){
        std::cin >> card[i];
    }

    for(int i{0}; i<M; ++i){
        if(set.find(card[i]) != set.end()) ans[i] = 1;
        else ans[i] = 0;
    }

    for(int i{0}; i<M; ++i){
        std::cout << ans[i] << ' ';
    }

    return 0;
}