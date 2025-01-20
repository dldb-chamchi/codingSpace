//백준 2003, 수들의 합 2

#include <iostream>

int main (){

    int N, M;
    int nums[10'000];
    std::cin >> N >> M;
    for(int i{0}; i<N; ++i){
        std::cin >> nums[i];
    }
    int ans{0};
    for(int i{0}; i<N; ++i){
        int j{i}; int sum{0};
        if(nums[i] == M){
            ++ans;
            continue;
        }
        while(j<N){
            if(sum + nums[j] == M){
                ++ans;
                break;
            }
            else if(sum + nums[j] > M) break;
            else{
                sum += nums[j];
                ++j;
            }
        }
    }

    std::cout << ans;

    return 0;
}