//백준 13305, 주유소

#include <iostream>
#include <climits>

int main (){

    long long N;
    long long len[100'000];
    long long price[100'001];
    std::cin >> N;
    
    for(auto i{0}; i<N-1; ++i){
        std::cin >> len[i];
    }

    for(auto i{0}; i<N; ++i){
        std::cin >> price[i];
    }

    //본인보다 작은 값이 나올때까지 주유*거리
    long long min{LONG_MAX}; long long minIdx{0}; long long sum{0}; 
    for(auto i{0}; i<N-1; ++i){
        if(price[i] < min){
            min = price[i];
            minIdx = i;
            sum += price[i] * len[i];
        }
        else{
            sum += price[minIdx] * len[i];
        }
    }

    std::cout << sum;

    return 0;
}