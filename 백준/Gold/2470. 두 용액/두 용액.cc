//백준 2470, 두 용액

#include <iostream>
#include <climits>
#include <algorithm>

int value[100'001];

int main (){
    
    int N;
    std::cin >> N;

    for(int i{0}; i<N; ++i){
        std::cin >> value[i];
    }

    std::sort(value, value+N);

    int i{0}; int j{N-1};
    int one{0}; int two{0};
    int min{INT_MAX};

    while(i < j){
        if(abs(value[i] + value[j]) < min){
            one = value[i];
            two = value[j];
            min = abs(value[i] + value[j]);
        }
        if(value[i]+value[j] == 0) break;
        if(value[i]+value[j] > 0) --j;
        else if(value[i] + value[j] < 0) ++i;
    }

    std::cout << one << ' ' << two;

    return 0;
}