//백준 1244, 스위치 켜고 끄기

#include <iostream>

int main (){
    int s, p;
    bool sw[101] = {0};

    std::cin >> s;
    for(int i{1}; i<=s; ++i) std::cin >> sw[i];
    std::cin >> p;
    while(p--){
        int se, num;
        std::cin >> se >> num;
        if(se == 1){
            for(int i{1}; i<=s; ++i){
                if(i % num == 0) sw[i] = !sw[i];
            }
        }
        else{
            sw[num] = !sw[num];
            for(int i{1}; sw[num+i] == sw[num-i]; ++i){
                if(num+i > s || num-i < 1) break;
                sw[num+i] = !sw[num+i];
                sw[num-i] = !sw[num-i];
            }
        }
    }

    for(int i{1}; i<=s; ++i){
        std::cout << sw[i] << ' ';
        if(i%20 == 0) std::cout << '\n';
    }

    return 0;
}