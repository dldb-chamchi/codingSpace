//백준 2581, 소수
#include <iostream>

int main(){

    int M, N; int sum{0}; int min{10'001};
    std::cin >> M >> N;
    
    while(M <= N){
        int i{2}; bool flag = M == 1 ? true : false; 
        while(i < M){
            if(M%i == 0){
                flag = true;
                break;
            }
            ++i;
        }
        if(!flag){
            sum+= M;
            min = std::min(min, M);
        }
        ++M;
    }
    if(sum == 0) std::cout << -1;
    else std::cout << sum << '\n' << min;
    
    return 0;
}