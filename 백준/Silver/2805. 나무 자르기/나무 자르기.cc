//백준 2805, 나무 자르기

#include <iostream>
#include <algorithm>

int N, M;
long long arr[1'000'000];

int solve(long long mid){
    long long ans{0};
    for(int i{0}; i<N; ++i){
        if(arr[i] > mid) ans += arr[i] - mid;
    }
    return ans >= M;
}

int main (){

    std::cin >> N >> M;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    std::sort(arr, arr+N);

    long long st{0}; long long end{arr[N-1]};
    while(st < end){
        long long mid = (st+end+1) / 2;
        if(solve(mid)) st = mid;
        else end = mid-1;
    }

    std::cout << st;

    return 0;
}