//백준 2217, 로프

#include <iostream>
#include <algorithm>

int rope[100'001];

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> rope[i];

    std::sort(rope, rope+N);

    int k{1}, max{0};
    for(int i{N-1}; i>=0; --i){
        max = std::max(max, rope[i]*k);
        ++k;
    }

    std::cout << max;

    return 0;
}