//백준 11652, 카드

#include <iostream>
#include <algorithm>

long long arr[100'000];

int main (){

    int N;
    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];
    std::sort(arr, arr+N);
    
    int cnt{1}; int max{0}; long long num;
    for(int i{1}; i<N; ++i){
        if(arr[i-1] == arr[i]) ++cnt;
        else{
            if(cnt > max){
                max = cnt;
                num = arr[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > max) num = arr[N-1];
    std::cout << num;

    return 0;
}