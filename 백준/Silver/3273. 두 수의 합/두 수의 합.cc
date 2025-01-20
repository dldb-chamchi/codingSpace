//백준 3273, 두 수의 합

#include <iostream>
#include <algorithm>

//정렬, 앞 + 뒤 
//1. 원하는 값보다 작다 -> 앞 땡기기
//2. 원하는 값보다 크가 -> 뒤 땡기기
//3. 같다. ++ ans -> 앞 뒤 땡기기

int nums[100'000];

int main (){

    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        std::cin >> nums[i];
    }

    int x;
    std::cin >> x;

    std::sort(nums, nums+N);
    int i{0}; int j{N-1}; int ans{0};
    while(i<j){
        if(nums[i] + nums[j] == x){
            ++ans;
            ++i; --j;
        }
        else if(nums[i] + nums[j] > x) --j;
        else if(nums[i] + nums[j] < x) ++i;
    }

    std::cout << ans;

    return 0;
}