//백준 1436, 영화감독 숌
#include <iostream>
#include <string>

int main(){
    int N;
    std::cin >> N;
    int num{666};
    int order{1};
    while(N > order){
        ++num;
        if(std::to_string(num).find("666") != std::string::npos)
            ++order;
    }

    std::cout << num;

    return 0;
}