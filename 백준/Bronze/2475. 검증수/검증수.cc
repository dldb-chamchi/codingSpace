//백준 2475, 검증수
#include <iostream>

int arr[5];

int main(){

    int n; int sum{0};
    for(int i{0}; i<5; ++i){
        std::cin >> n;
        sum += n*n;
    }

    std::cout << sum % 10;

    return 0;
}