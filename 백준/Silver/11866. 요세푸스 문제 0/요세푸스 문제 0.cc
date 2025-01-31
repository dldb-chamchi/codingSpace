//백준 11866, 요세푸스 문제 0

#include <iostream>
#include <deque>

std::deque<int> d;

int main (){

    int N, K;
    std::cin >> N >> K;
    for(int i{1}; i<=N; ++i){
        d.push_back(i);
    }
    int turn{1};
    std::cout << "<";
    while(d.size() != 1){
        if(turn == K){
            std::cout << d.front() << ',' << ' ';
            d.pop_front();
            turn = 1;
        }
        else{
            int tmp = d.front();
            d.pop_front();
            d.push_back(tmp);
            ++turn;
        }
    }

    std::cout << d.front() << ">";

    return 0;
}