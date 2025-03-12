//백준 9205, 맥주 마시면서 걸어가기

#include <iostream>
#include <algorithm>
#include <queue>

int x, y, ex, ey;
int T, N;

std::pair<int, int> store[101];

bool bfs(std::pair<int, int>* store){
    std::queue<std::pair<int, int>> q;
    bool visit[101] = {false};
    q.push({x, y});

    while(!q.empty()){
        auto [currX, currY] = q.front(); q.pop();
        if(abs(ex - currX) + abs(ey - currY) <= 1000) return true;
        
        for(int i{0}; i<N; ++i){
            if(visit[i]) continue;
            if(abs(currX - store[i].first) + abs(currY - store[i].second) <= 1000){
                q.push({store[i].first, store[i].second});
                visit[i] = true;
            }
        }
    }
    return false;
}

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> T;

    while(T--){

        std::cin >> N;
        std::cin >> x >> y;

        for(int i{0}; i<N; ++i) std::cin >> store[i].first >> store[i].second;
        std::cin >> ex >> ey;

        if(bfs(store)) std::cout << "happy\n";
        else std::cout << "sad\n";

    }

    return 0;
}