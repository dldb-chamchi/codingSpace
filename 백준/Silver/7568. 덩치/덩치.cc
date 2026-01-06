//백준 7568 덩치

#include <iostream>

int main (){
    int N;
    std::cin >> N;
    std::pair<int, int> ans[51];
    int rank[51];
    for(int i{0}; i<N; ++i) rank[i] = 1;

    for(int i{0}; i<N; ++i){
        int h, w;
        std::cin >> h >> w;
        ans[i].first = h;
        ans[i].second = w;
    }

    for(int i{0}; i<N; ++i){
        for(int j{0}; j<N; ++j){
            if(j == i) continue;
            if(ans[i].second > ans[j].second && ans[i].first > ans[j].first) ++rank[j];
        }
    }

    for(int i{0}; i<N; ++i){
        std::cout << rank[i] << ' ';
    }


    return 0;
}