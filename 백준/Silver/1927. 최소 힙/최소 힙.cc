//백준 1927, 최소 힙

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, x;
    std::cin >> N;
    while(N--){
        std::cin >> x;
        if(x == 0){
            if(pq.empty()) std::cout << 0 << '\n';
            else{
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }

    return 0;
}