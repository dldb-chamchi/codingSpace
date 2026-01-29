#include <iostream>
#include <vector>


//규칙성
int T, N;
std::vector<int> di(100, 0);
std::vector<int> dj(100, 0);
std::vector<int> nums(2, 0);

void dp(){
    di[0] = 1; dj[0] = 0;
    di[1] = 0; dj[1] = 1;
    for(int i{2}; i<=N; ++i){
        di[i] = di[i-1] + di[i-2];
        dj[i] = dj[i-1]  +dj[i-2];
    }
    std::cout << di[N] << ' ' << dj[N] << '\n'; 
    
}


int main(){

    std::cin >> T;
    for(int t{0}; t<T; ++t){
        std::cin >> N;
        dp();
    }



    return 0;
}