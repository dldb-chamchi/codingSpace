//백준 24723, 녹색거탑

#include <iostream>

int main (){
    int N;
    std::cin >> N;
    int ans{1};
    for(int i{1}; i<=N; ++i){
        ans*=2;
    }

    std::cout << ans;


    return 0;
}