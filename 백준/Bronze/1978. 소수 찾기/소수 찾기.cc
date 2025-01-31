//백준 1978, 소수 찾기
#include <iostream>


int main(){

    int N, n;
    int sum{0};

    std::cin >> N;
    
    for(int i{0}; i<N; ++i){
        std::cin >> n;
        int num{2}; 
        bool flag = n == 1 ? true : false;
        while(n > num){
            if(n%num == 0){
                flag = true;
                break;
            }
            ++num;
        }
        if(!flag) ++sum;
    }

    std::cout << sum;

    return 0;
}