//백준 1966, 프린터 큐
#include <iostream>
#include <deque>

int main(){

    int t;
    std::cin >>t;
    while(t--){
        int N, M;
        std::cin >> N >> M;
        std::deque<std::pair<int, int>> note; //중요도, 순서

        for(int i{0}; i<N; ++i){
            int n; std::cin >> n;
            note.push_back({n, i});
        }

        int order{0};
        
        while(!note.empty()){
            bool flag = false;
            for(int i{0}; i<note.size(); ++i){
                if(note.front().first < note[i].first){
                    flag = true;
                    break;
                }
            }
            
            if(flag){
                auto tmp = note.front();
                note.pop_front();
                note.push_back(tmp);
            }
            else{
                ++order;
                if(note.front().second == M){
                    std::cout << order << '\n';
                    break;
                }
                note.pop_front();
            }
        }
    }
    return 0;
}