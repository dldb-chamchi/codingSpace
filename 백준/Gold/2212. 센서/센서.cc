//백준 2212, 센서
#include <iostream>
#include <vector>
#include <algorithm>

int arr[10'000];
std::vector<int> vec;

int main(){

    int N, K;

    std::cin >> N >> K;

    for(int i{0}; i<N; ++i){
        std::cin >> arr[i];
    }

    std::sort(arr, arr+N);

    for(int i{0}; i<N-1; ++i){
        vec.push_back(arr[i+1]-arr[i]);
    }

    std::sort(vec.begin(), vec.end(), std::greater<>());

    int ans{0};
    for(int i{K-1}; i<vec.size(); ++i){
        ans += vec[i];
    }

    std::cout << ans;

    return 0;
}
