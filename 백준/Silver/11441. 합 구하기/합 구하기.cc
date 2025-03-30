//백준 11441, 합 구하기
#include <iostream>

int arr[100'005];

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    int N, M;
    std::cin >> N;
    for(int i{1}; i<=N; ++i){
        std::cin >> arr[i];
    }

    std::cin >> M;

    for(int i{1}; i<N; ++i){
        arr[i+1] += arr[i];
    }

    int i, j;
    for(int k{0}; k<M; ++k){
        std::cin >> i >> j;
        std::cout << arr[j] - arr[i-1] << '\n';
    }



    return 0;
}