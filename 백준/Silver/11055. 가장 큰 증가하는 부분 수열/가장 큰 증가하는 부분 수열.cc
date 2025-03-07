//백준 11055, 가장 큰 증가하는 부분 수열
#include <iostream>
#include <algorithm>

int arr[1'000];
int dp[1'000];

int main(){

    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    std::copy(arr, arr+N, dp);
    
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<i; ++j){
            if(arr[i] > arr[j]) dp[i] = std::max(dp[i], dp[j]+arr[i]);
        }
    }

    std::cout << *std::max_element(dp, dp+N);

    return 0;
}