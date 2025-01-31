//백준 2346, 풍선 터뜨리기
#include <iostream>
#include <deque>

std::deque<int> d;
std::deque<int> idx;

int main(){
    int N, n;
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        std::cin >> n;
        d.push_back(n);
        idx.push_back(i+1);
    }

    int turn{d.front()};
    std::cout << idx.front() << ' ';
    d.pop_front();
    idx.pop_front();
    int cnt = turn > 0 ? 1 : -1;

    while(!d.empty()){
        if(turn < 0){
            if(cnt == turn){
                std::cout << idx.back() << ' ';
                turn = d.back();
                d.pop_back();
                idx.pop_back();
                cnt = turn > 0 ? 1 : -1;
            }
            else{
                d.push_front(d.back());
                d.pop_back();
                idx.push_front(idx.back());
                idx.pop_back();
                --cnt;
            }
        }
        else if(turn > 0){
            if(cnt == turn){
                std::cout << idx.front() << ' ';
                turn = d.front();
                d.pop_front();
                idx.pop_front();
                cnt = turn > 0 ? 1 : -1;
            }
            else{
                d.push_back(d.front());
                d.pop_front();
                idx.push_back(idx.front());
                idx.pop_front();
                ++cnt;
            }
        }
    }

    return 0;
}