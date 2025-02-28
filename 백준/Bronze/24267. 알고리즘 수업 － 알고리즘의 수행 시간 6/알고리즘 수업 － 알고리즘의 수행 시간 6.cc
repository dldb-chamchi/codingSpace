//백준 24267, 알고리즘 수업 - 알고리즘의 수행 시간 6

#include <iostream>

int main (){

    long long N;
    std::cin >> N;
    
    long long adder{1}; long long sum{0};
    for(int i{2}; i<=N-1; ++i){
        sum += adder;
        adder += i;
    }

    std::cout << sum << '\n' << 3;

    return 0;
}