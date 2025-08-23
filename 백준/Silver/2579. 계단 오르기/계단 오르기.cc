#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n;
std::vector<int> score(301, 0);
std::vector<int> d(301, 0);

void dp(){
    d[1] = score[1];
    d[2] = score[1] + score[2];
    d[3] = std::max(score[1]+ score[3], score[2] + score[3]);
    for(int i{4}; i<=n; ++i){
        d[i] = std::max(d[i-2], d[i-3] + score[i-1]) + score[i];
    }
    std::cout << d[n];
}

int main() {
    
    std::cin >> n;
    for(int i{1}; i<=n; ++i){
        std::cin >> score[i];
    }
    dp();
    /*
    for(auto nums : d) std::cout << nums << ' ';
    std::cout << '\n';
    */
    return 0;
}
