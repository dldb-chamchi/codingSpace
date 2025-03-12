//백준 1850, 최대공약수

#include <iostream>

int main (){

    unsigned long long a, b;
    std::cin >> a >> b;

    if(a < b) std::swap(a, b);

    while(b != 0){
        auto c = a % b;
        a = b;
        b = c;
    }

    for(auto i{0}; i<a; ++i){
        std::cout << 1;
    }

    return 0;
}