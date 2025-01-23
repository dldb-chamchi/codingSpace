//백준 10989, 수 정렬하기 3

#include <iostream>
#include <algorithm>

int arr[10'001];

int main(){

    int N;
    std::cin >> N;
    for(int i{0}; i<N; ++i){
        int n;
        std::cin >> n;
        ++arr[n];
    }

    for(int i{1}; i<=10000; ++i){
        for(int j{1}; j<=arr[i]; ++j){
            std::cout << i << '\n';
        }
    }

    return 0;
}