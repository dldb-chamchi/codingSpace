//백준 1654, 랜선 자르기

#include <iostream>

long long arr[10'000];
int K, N;

bool solve(long long mid){
    int ans{0};
    for(int i{0}; i<K; ++i){
        ans += arr[i] / mid;
    }
    return ans >= N;
}

int main (){

    std::cin >> K >> N;
    for(auto i{0}; i<K; ++i){
        std::cin >> arr[i];
    }

    long long st{1}; long long end = (1LL << 31)-1;
    while(st < end){
        auto mid = (st+end+1) / 2;
        if(solve(mid)) st = mid; 
        else end = mid -1;
    }

    std::cout << st;

    return 0;
}