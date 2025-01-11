//1931, 회의실 배정

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define end second
#define start first

std::pair<int, int> time[100000]; //end, start
int main(){
    int N;
    std::cin >> N;
    

    for(int i{0}; i<N; ++i)
        std::cin >> time[i].end >> time[i].start;
    

    std::sort(time, time+N);

    int ans{0}; int t{0};
    
    for(int i{0}; i<N; ++i){
        if(t > time[i].end) continue;
        t = time[i].start;
        ++ans;
    }

    std::cout << ans;
    
    return 0;
}
