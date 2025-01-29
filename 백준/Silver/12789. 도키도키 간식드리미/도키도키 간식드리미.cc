//백준 12789, 도키도키 간식드리미
#include <iostream>
#include <stack>

int people[1'000];
int N;
std::stack<int> s;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        std::cin >> people[i];
    }

    int turn{1}; int i{0};
    while(i<N){
        if(people[i] != turn){
            if(s.empty() || s.top() != turn){
                s.push(people[i]);
                ++i;
            }
            else{
                s.pop(); 
                ++turn;
            }
        }
        else{
            ++turn;
            ++i;
        }
    }

    if(s.size() <= 1){
        std::cout << "Nice";
        return 0;
    }
    
    int prev = s.top();
    s.pop();

    while(!s.empty()){
        int curr = s.top();
        s.pop();
        if(curr < prev){
            std::cout << "Sad";
            return 0;
        }
    }

    std::cout << "Nice";

    return 0;
}