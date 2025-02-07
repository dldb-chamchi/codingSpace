//백준 1806, 부분합

#include <iostream>

int arr[100'000];

int main (){

    int N, S;
    std::cin >> N >> S;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];
    
    int st{0}; int end{0}; int sum{0}; int min = 100'001;
    while(st < N){
        if(sum >= S){
            sum -= arr[st];
            min = std::min(min, end-st);
            ++st;
        }
        else if(end == N){
            sum -= arr[st];
            ++st;
        }
        else{
            sum += arr[end];
            ++end;
        }
    }
    std::cout << (min == 100'001 ? 0 : min);
    return 0;
}