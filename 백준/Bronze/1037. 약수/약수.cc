//백준 1037, 약수

#include <iostream>
#include <algorithm>

int divi[51];

int main(){

    int N;
    std::cin >> N;
    
    for(int i{0}; i<N; ++i){
        std::cin >> divi[i];
    }

    std::sort(divi, divi+N);

    std::cout << ((N > 0) ? divi[0] * divi[N-1] : -(divi[0] * divi[N-1]));

    return 0;
}