//백준 1946 신입 사원

#include <iostream>
#include <algorithm>

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;
    while(T--){
        int N;
        std::pair<int, int> arr[100'001];
        std::cin >> N;
        for(int i{1}; i<=N; ++i){
            std::cin >> arr[i].first >> arr[i].second;
        }
        
        std::sort(arr+1, arr+N+1);

        int ans{1}; int tmp{arr[1].second};
        for(int i{2}; i<=N; ++i){
            if(tmp >= arr[i].second){
                tmp = arr[i].second;
                ++ans;
            }
        }
        std::cout << ans << '\n';
    }

    return 0;
}