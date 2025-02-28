//백준 11054, 가장 긴 바이토닉 부분 수열

#include <iostream>
#include <algorithm>

int arr[1'000];
int dpP[1'000];
int dpM[1'000];

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    for(int i{0}; i<N; ++i){
        dpP[i] = 1;
        dpM[i] = 1;
    }

    for(int i{0}; i<N; ++i){
        for(int j{0}; j<i; ++j){
            if(arr[j] < arr[i]){
                dpP[i] = std::max(dpP[i], dpP[j]+1);
            }
        }
    }

    for(int i{N-1}; i>=0; --i){
        for(int j{N-1}; j>i; --j){
            if(arr[j] < arr[i]){
                dpM[i] = std::max(dpM[i], dpM[j]+1);
            }
        }
    }

    int max{0};
    for(int i{0}; i<N; ++i){
        max = std::max(max, dpP[i]+dpM[i]-1);
    }

    std::cout << max;

    return 0;
}