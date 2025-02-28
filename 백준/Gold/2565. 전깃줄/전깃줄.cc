//백준 2565, 전깃줄

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> vec;
int dp[501];

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    for(int i{0}; i<N; ++i){
        int a, b;
        std::cin >> a >> b;
        vec.push_back({a, b});
    }

    std::sort(vec.begin(), vec.end());

    for(int i{0}; i<N; ++i){
        dp[i] = 1;
        for(int j{0}; j<i; ++j){
            if(vec[i].second > vec[j].second){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }

    std::cout << N - *std::max_element(dp, dp+N);

    return 0;
}