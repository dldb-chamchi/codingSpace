//백준 28278, 스택 2
#include <iostream>
#include <deque>

std::deque<int> d;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, n;
    std::cin >> N;

    while(N--){
        int num;
        std::cin >> num;

        if(num == 1){
            std::cin >> n; 
            d.push_front(n);
        }
        else if(num == 2){
            std::cin >> n; 
            d.push_back(n);
        }
        else if(num == 3){
            if(d.empty()) std::cout << -1 << '\n';
            else{
                std::cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if(num == 4){
            if(d.empty()) std::cout << -1 << '\n';
            else{
                std::cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if(num == 5) std::cout << d.size() << '\n';
        else if(num == 6) std::cout << d.empty() << '\n';
        else if(num == 7){
            if(d.empty()) std::cout << -1 << '\n';
            else std::cout << d.front() << '\n';
        }
        else{
            if(d.empty()) std::cout << -1 << '\n';
            else std::cout << d.back() << '\n';
        }
    }

    return 0;
}