//백준 2512, 예산

#include <iostream>
#include <algorithm>

int arr[10'001];

int N, M;

bool solve(int mid){
    int sum{0};
    for(int i{0}; i<N; ++i){
        sum += std::min(mid, arr[i]);
    }
    return sum > M;
}

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];
    std::cin >> M;

    std::sort(arr, arr+N);

    int st{0}, end{arr[N-1]};

    while(st <= end){
        auto mid = (st + end)/2;
        if(solve(mid)) end = mid-1;
        else st = mid+1;
    }

    std::cout << end;

    return 0;
}