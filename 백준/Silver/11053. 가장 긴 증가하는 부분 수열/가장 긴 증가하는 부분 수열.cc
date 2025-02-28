//백준 11053, 가장 긴 증가하는 부분 수열

#include <iostream>
#include <algorithm>

int arr[1001];
int dp[1001];

int main (){

    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    std::fill(dp, dp+N, 1);

    for(int i{0}; i<N; ++i){
        for(int j{0}; j<i; ++j){
            if(arr[j] < arr[i]){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }

    std::cout << *std::max_element(dp, dp+N);

    return 0;
}