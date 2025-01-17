//백준 2444, 별 찍기 - 7
#include <iostream>

int main(){
    int N;
    std::cin >> N;
    int j{1};
    for(int i{N-1}; i>=0; --i){
        std::cout << std::string(i, ' ')
                << std::string(j, '*')
                << '\n';
        j+=2;
    }
    j -= 2;
    for(int i{1}; i<N; ++i){
        j -= 2;
        std::cout << std::string(i, ' ')
                << std::string(j, '*')
                << '\n';
        
    }

    return 0;
}