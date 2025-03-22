//백준 1253, 좋다
#include <iostream>
#include <algorithm>

int arr[2'000];

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    std::sort(arr, arr+N);

    int cnt{0};
    for(int i{0}; i<N; ++i){
        int tmp = arr[i];
        int st{0}, end{N-1};
        while(st < end){
            if(st == i){
                ++st;
                continue;
            }
            else if(end == i){
                --end;
                continue;
            }
            if(arr[st] + arr[end] == tmp){
                ++cnt;
                break;
            }
            else if(arr[st]+arr[end] > tmp) --end;
            else ++st;
        }
    }

    std::cout << cnt;

    return 0;
}