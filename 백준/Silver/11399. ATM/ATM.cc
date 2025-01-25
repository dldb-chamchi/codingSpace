//백준 11399, ATM
#include <iostream>
#include <algorithm>

int arr[1'000];

int main(){

    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> arr[i];
    std::sort(arr, arr+N);

    int sum{0}; int stack{0};
    for(int i{0}; i<N; ++i){
        stack += arr[i];
        sum += stack;
    }
    
    std::cout << sum;

    return 0;
}