//백준 1920, 수 찾기

#include <iostream>
#include <algorithm>

int A[100'000];
int B[100'000];

int N, M;

void binarySearch(int i){
    int start{0}; int end{N-1};
    while(start <= end){
        int mid = (start + end) / 2;
        if(B[i] > A[mid]){
            start = mid+1;
        }
        else if(B[i] < A[mid]){
            end = mid-1;
        }
        else{
            std::cout << 1 << '\n';
            return;
        }
    }
    std::cout << 0 << '\n';
}

int main (){

    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> A[i];
    
    std::cin >> M;
    
    for(int i{0}; i<M; ++i) std::cin >> B[i];

    std::sort(A, A+N);

    for(int i{0}; i<M; ++i){
        binarySearch(i);
    }
    
    return 0;
}