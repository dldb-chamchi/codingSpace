//백준 25305, 커트라인
#include <iostream>
#include <algorithm>

int main(){
    int N, k;
    int student[10000];
    std::cin >> N >> k;

    for(int i{0}; i<N; ++i){
        std::cin >> student[i];
    }

    std::sort(student, student+N);

    std::cout << student[N-k];

    return 0;
}