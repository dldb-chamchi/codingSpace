//백준 1193, 분수찾기

#include <iostream>

int main(){

    int x;
    std::cin >> x;
    int i;
    // for(i = 1; i<4000; ++i){
    //     x -= i;
    //     if(x < i) break;
        
    // }

    while(x > i){
        x-=i;
        ++i;
    }
    if(i % 2 == 0) std::cout << x << '/' << i+1-x;
    else std::cout << i+1-x << '/' << x;


    return 0;
}