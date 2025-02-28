//백준 5430, AC

#include <iostream>
#include <deque>



int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, n;
    std::cin >> T;
    std::string s, nums;
    while(T--){
        std::cin >> s;
        std::cin >> n;
        std::cin >> nums;
        std::string tmp= "";
        std::deque<int> d;
        bool flag = false; bool error = false;
        for(int i{0}; i<nums.length(); ++i){
            if(isdigit(nums[i])) tmp+=nums[i];
            else{
                if(!tmp.empty()){
                    d.push_back(std::stoi(tmp));
                    tmp = "";
                }
            }
        }
        for(int i{0}; i<s.length(); ++i){
            if(s[i] == 'R'){
                if(flag) flag = false;
                else flag = true;
            }
            else{
                if(d.empty()){
                    std::cout << "error";
                    error = true;
                    break;
                }
                else if(flag) d.pop_back();
                else d.pop_front();
            }
        }
        if(d.empty() && !error){
            std::cout << "[]";
        }
        else if(!d.empty()){
            if(flag){
                int len = d.size()-1;
                std::cout << '[' << d.back();
                d.pop_back();
                for(int i{0}; i<len; ++i){
                    std::cout << ',' << d.back();
                    d.pop_back();
                }
                std::cout << ']';
            }
            else{
                int len = d.size()-1;
                std::cout << '[' << d.front();
                d.pop_front();
                for(int i{0}; i<len; ++i){
                    std::cout << ',' << d.front();
                    d.pop_front();
                }
                std::cout << ']';
            }
        }
        std::cout << '\n';
    }

    return 0;
}