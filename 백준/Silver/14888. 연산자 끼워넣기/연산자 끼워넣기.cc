//백준 14888, 연산자 끼워넣기

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> ans;
int nums[12];
int op[4];

void back(int depth, int sum){
    if(depth == N){
        ans.push_back(sum);
        return;
    }
    for(int i{0}; i<4; ++i){
        if(i==0 && op[i] > 0){
            --op[i];
            back(depth+1, sum+nums[depth]);
            ++op[i];
        }
        else if(i==1 && op[i] > 0){
            --op[i];
            back(depth+1, sum-nums[depth]);
            ++op[i];
        }
        else if(i==2 && op[i] > 0){
            --op[i];
            back(depth+1, sum*nums[depth]);
            ++op[i];
        }
        else if(i==3 && op[i] > 0){
            --op[i];
            back(depth+1, sum/nums[depth]);
            ++op[i];
        }
    }
}

int main (){

    std::cin >> N;

    for(int i{0}; i<N; ++i) std::cin >> nums[i];
    for(int i{0}; i<4; ++i) std::cin >> op[i];
    back(1, nums[0]);
    std::sort(ans.begin(), ans.end());

    std::cout << ans[ans.size()-1] << '\n' << ans[0];

    return 0;
}