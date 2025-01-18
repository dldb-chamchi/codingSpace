//백준 18111, 마인크래프트

#include <iostream>
#include <climits>

int N, M, B;
int grid[501][501];
int max{0};

int main (){

    std::cin >> N >> M >> B;
    for(int i{0}; i<N; ++i){
        for(int j{0}; j<M; ++j){
            std::cin >> grid[i][j];
        }
    }

    int min{INT_MAX};
    int height{0};
    for(int k{0}; k<=256; ++k){
        int getB{B}; int useB{0};
        for(int i{0}; i<N; ++i){
            for(int j{0}; j<M; ++j){
                if(grid[i][j] > k) getB = getB + (grid[i][j] - k);
                else if(grid[i][j] < k) useB = useB + (k - grid[i][j]);
            }
        }
        int time{0};
        if(useB > getB) continue;
        else{
            time += (getB-B) * 2;
            time += useB;
            if(time <= min){
                min = time;
                height = k;
            }
        }
        
    }
    std::cout << min << ' ' << height;

    return 0;
}