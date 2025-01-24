//백준 11728, 배열 합치기
#include <iostream>

int arr[2'000'001];
int arr1[1'000'000];
int arr2[1'000'000];

int main(){

    int N, M;

    std::cin >> N >> M;
    
    int idx1{0}; int idx2{0};
    int n;

    for(int i{0}; i<N; ++i){
        std::cin >> arr1[i];
    }

    for(int i{0}; i<M; ++i){
        std::cin >> arr2[i];
    }

    for(int i{0}; i<N+M; ++i){
        if(idx1 == N || idx2 == M){
            n = i;
            break;
        }
        if(arr1[idx1] < arr2[idx2]){
            arr[i] = arr1[idx1];
            ++idx1;
        }
        else{
            arr[i] = arr2[idx2];
            ++idx2;
        }
    }
    if(idx1 == N){
        for(int i{n}; i<N+M; ++i){
            arr[i] = arr2[idx2];
            ++idx2;
        }
    }
    else{
        for(int i{n}; i<N+M; ++i){
            arr[i] = arr1[idx1];
            ++idx1;
        }
    }

    for(int i{0}; i<N+M; ++i){
        std::cout << arr[i] << ' ';
    }
    

    return 0;
}
