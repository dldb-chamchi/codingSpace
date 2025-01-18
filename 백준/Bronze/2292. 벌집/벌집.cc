//백준 2292, 벌집
#include <iostream>

int main(){

    int N;
    std::cin >> N;
    int i{1};
    int six{1};
    int layer{1};
    while(N > six){
        six += i*6;
        ++i;
        ++layer;
    }
    std::cout << layer;
    
    return 0;
}