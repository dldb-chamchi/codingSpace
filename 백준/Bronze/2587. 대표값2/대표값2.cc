//백준 2587, 대표값2
#include <iostream>
#include <algorithm>

int main(){

    int nums[5];
    int sum{0};
    for(int i{0}; i<5; ++i){
        std::cin >> nums[i];
        sum += nums[i];
    }

    std::sort(nums, nums+5);
    std::cout << sum/5 << '\n' << nums[2]; 

    return 0;
}