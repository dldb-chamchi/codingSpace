//백준 2720, 세탁소 사장 동혁
#include <iostream>
#include <cmath>

int change[4];

int main(){

    int T; int N;
    std::cin >> T;
    while(T--){
        int change[4] = {0};
        std::cin >> N;
        if(N >= 25){
            change[0] += N/25;
            N -= (N/25)*25;
        }
        
        if(N >= 10){
            change[1] += N/10;
            N -= (N/10)*10;
        }
        if(N >= 5){
            change[2] += N/5;
            N -= (N/5)*5;
        }
        if(N >= 1){
            change[3] += N/1;
            N -= (N/1)*1;
        }
        for(int i{0}; i<4; ++i){
            std::cout << change[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}