//백준 11722, 가장 긴 감소하는 부분 수열

#include <iostream>
#include <algorithm>

int arr[1'000];
int dp[1'000];

int main (){

    int N;
    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    for(int i{0}; i<N; ++i){
        for(int j{0}; j<i; ++j){
            if(arr[j] > arr[i]){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }

    std::cout << *std::max_element(dp, dp+N)+1;

    return 0;
}