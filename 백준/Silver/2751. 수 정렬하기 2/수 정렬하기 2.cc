//백준 2751, 수 정렬하기 2
#include <iostream>
#include <algorithm>

int arr[1'000'000];

int main(){
    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    std::sort(arr, arr+N);

    for(int i{0}; i<N; ++i) std::cout << arr[i] << '\n';

    return 0;
}