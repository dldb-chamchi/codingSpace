//백준 2231, 분해합
#include <iostream>

int main(){

    int N;
    std::cin >> N;
    int n{1};
    while(N >= n){
        int tmp = n;
        int val{0};
        val += tmp;
        while(tmp > 0){
            val += tmp%10;
            tmp /= 10;
        }
        if(val == N){
            std::cout << n;
            return 0;
        }
        else ++n;
    }
    std::cout << 0;

    return 0;
}