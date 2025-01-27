//백준 18258, 큐 2
#include <iostream>
#include <queue>

std::queue<int> q;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::string s;
    std::cin >> N;
    while(N--){
        std::cin >> s;
        if(s == "push"){
            int num;
            std::cin >> num;
            q.push(num);
        }
        else if(s == "pop"){
            if(q.empty()) std::cout << -1 << '\n';
            else{
                std::cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(s == "size") std::cout << q.size() << '\n';
        else if(s == "empty") std::cout << q.empty() << '\n';
        else if(s == "front"){
            if(q.empty()) std::cout << -1 << '\n';
            else std::cout << q.front() << '\n';
        }
        else{
            if(q.empty()) std::cout << -1 << '\n';
            else std::cout << q.back() << '\n';
        }
    }

    return 0;
}