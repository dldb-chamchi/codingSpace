//백준 14719, 빗물

#include <iostream>

int arr[501];

int main (){

    int H, W;
    std::cin >> H >> W;

    for(int i{0}; i<W; ++i){
        std::cin >> arr[i];
    }

    int cnt{0};
    for(int i{1}; i<W-1; ++i){
        int l{0}, r{0};
        
        for(int j{0}; j<i; ++j) l = std::max(l, arr[j]);
        for(int j{W-1}; j>i; --j) r = std::max(r, arr[j]);
        
        cnt += std::max(0, std::min(l, r)-arr[i]);
    }
    
    std::cout << cnt;

    return 0;
}