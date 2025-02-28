//백준 11653, 소인수분해

#include <iostream>

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;
    int limit = N;
    int i{2};
    while(N>1){
        while(i<=limit){
            if(N%i == 0){
                std::cout << i << '\n';
                N/= i;
            }
            else{
                ++i;
            }
        }
    }

    return 0;
}