//백준 17298, 오큰수

#include <iostream>
#include <stack>

std::stack<int> s;
int arr[1'000'000];
int print[1'000'000];

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    for(int i{0}; i<N; ++i){
        while(!s.empty() && arr[s.top()] < arr[i]){
            print[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        print[s.top()] = -1;
        s.pop();
    }

    for(int i{0}; i<N; ++i) std::cout << print[i] << ' ';

    return 0;
}