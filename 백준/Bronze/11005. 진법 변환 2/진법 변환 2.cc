//백준 11005, 진법 변환 2
#include <iostream>
#include <unordered_map>
#include <deque>

std::unordered_map<int, char> map;
int main(){

    for(int i{0}; i <= 9; ++i)
        map[i] = i + '0';
    

    for(int i{10}; i<=36; ++i)
        map[i] = 'A' + (i-10);
    

    int N, B;
    
    std::cin >> N >> B;
    
    std::deque<char> d;

    while(N >= B){
        int num = N % B;
        auto it = map.find(num);
        d.push_front(it->second);
        N /= B;
    }
    
    auto it = map.find(N);
    d.push_front(it->second);

    for(auto c : d) std::cout << c;
    
    return 0;
}