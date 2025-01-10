//1026, 보물

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main(){
    int N;
    std::cin >> N;
    int a[N];
    int b[N];
    for(int i{0}; i<N; ++i) std::cin >> a[i];
    for(int i{0}; i<N; ++i) std::cin >> b[i];

    std::sort(a, a+N);
    std::sort(b, b+N);
    int s{0};
    for(int i{1}; i<=N; ++i)
        s += a[i-1] * b[N-i];
    
    std::cout << s;
    return 0;
}