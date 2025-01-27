//백준 28278, 스택 2
#include <iostream>
#include <stack>

std::stack<int> s;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    while(N--){
        int num;
        std::cin >> num;

        if(num == 1){
            int n;
            std::cin >> n; 
            s.push(n);
        }
        else if(num == 2){
            if(s.empty()) std::cout << -1 << '\n';
            else{
                std::cout << s.top() << '\n';
                s.pop();
            }
        }
        else if(num == 3){
            std::cout << s.size() << '\n';
        }
        else if(num == 4){
            std::cout << s.empty() << '\n';
        }
        else{
            if(s.empty()) std::cout << -1 << '\n';
            else std::cout << s.top() << '\n';
            
        }
    }

    return 0;
}