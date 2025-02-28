#include<iostream>

int main(){
    int N;
    std::cin >> N;
    long long sum{0}; 
    for(int i{1}; i<N; ++i){
        sum += i;
    }
    std::cout << sum << '\n' << 2;
    
    return 0;
}