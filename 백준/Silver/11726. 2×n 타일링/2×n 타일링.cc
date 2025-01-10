#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n;
std::vector<int> d(1001, 0);

void dp(){
    d[1] = 1; d[2] = 2; d[3] = 3;
    for(int i{4}; i<=n; ++i){
        d[i] = d[i-1] + d[i-2];
        d[i] %= 10007;
    }
    std::cout<< d[n]%10007;
}

int main() {

    std::cin >> n;
    dp();

    return 0;
}