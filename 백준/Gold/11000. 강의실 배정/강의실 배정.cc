//백준 11000, 강의실 배정
#include <iostream>
#include <queue>
#include <algorithm>

std::pair<int, int> arr[200'000];
std::priority_queue<int, std::vector<int>, std::greater<>> q;

int main(){
    int N, st, en;
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        std::cin >> arr[i].first >> arr[i].second;
    }

    std::sort(arr, arr+N);

   q.push(arr[0].second);
    for(int i{1}; i<N; ++i){
        if(q.top() <= arr[i].first) q.pop();
        q.push(arr[i].second);
    }

    std::cout << q.size();

    return 0;
}