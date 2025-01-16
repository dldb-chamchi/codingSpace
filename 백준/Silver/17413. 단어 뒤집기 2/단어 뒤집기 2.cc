//백준 17413, 단어 뒤집기 2
#include <iostream>
#include <stack>

std::stack<char> stack;

int main(){

    std::string s;
    std::getline(std::cin, s);
    
    bool flag = false;
    
    for(int i{0}; i<s.size(); ++i){
        if(s[i] == ' '){
            while(!stack.empty()){
                std::cout << stack.top();
                stack.pop();
            }
            std::cout << ' ';
        }
        else if(s[i] == '<'){
            while(!stack.empty()){
                std::cout << stack.top();
                stack.pop();
            }
            flag = true;
            std::cout << s[i];
        }
        else if(s[i] == '>'){
            flag = false;
            std::cout << s[i];
        }
        else if(flag) std::cout << s[i];
        else stack.push(s[i]);
    }

    while(!stack.empty()){
            std::cout << stack.top();
            stack.pop();
        }
        std::cout << ' ';

    return 0;
}