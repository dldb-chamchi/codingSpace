//백준 11286, 절댓값 힙

#include <iostream>
#include <queue>
#include <vector>

struct cmp{ // 정렬 기준 바꾸는 함수
    bool operator()(int a, int b){
        if(std::abs(a) == std::abs(b))
            return a > b; // 절대값이 같은 경우 가장 작은 원소로
        return std::abs(a) > std::abs(b); // 절대값이 작은 원소로
    }
};

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, x;
    std::cin >> N;
    std::priority_queue<int, std::vector<int>, cmp> pq;

    while(N--){
        std::cin >> x;
        if(x != 0) pq.push(x);
        else{
            if(pq.empty()) std::cout << 0 << '\n';
            else{
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}