//백준 2559, 수열

#include <iostream>
#include <algorithm>

int main (){

    int N, K;
    int nums[100'001];
    std::cin >> N >> K;

    for(int i{0}; i<N; ++i){
        std::cin >> nums[i];
    }

    //초기값
    int sum{0}; int max{0};
    for(int i{0}; i<K; ++i){
        sum += nums[i];
    }
    max = sum;

    for(int i{1}; i<=N-K; ++i){
        sum -= nums[i-1];
        sum += nums[i-1+K];
        max = std::max(max, sum);
    }

    std::cout << max;

    return 0;
}