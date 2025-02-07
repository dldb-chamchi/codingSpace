//백준 11659, 구간 합 구하기 4

#include <iostream>

int arr[100'001];

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M;
    std::cin >> N >> M;
    for(int i{1}; i<=N; ++i){
        std::cin >> arr[i];
        arr[i] = arr[i-1] + arr[i];
    }
    

    while(M--){
        int i, j;
        std::cin >> i >> j;
        std::cout << arr[j] - arr[i-1] << '\n';
    }

    return 0;
}