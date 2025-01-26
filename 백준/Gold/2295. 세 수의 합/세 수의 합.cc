//백준 2295, 세 수의 합

#include <iostream>
#include <vector>
#include <algorithm>

int N;
int arr[1'005];
std::vector<int> two;

int main (){

    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];

    std::sort(arr, arr+N);

    for(int i{0}; i<N; ++i){
        for(int j{i}; j<N; ++j){
            two.push_back(arr[i] + arr[j]);
        }
    }

    std::sort(two.begin(), two.end());

    for(int l{N-1}; l>0; --l){
        for(int k{0}; k<l; ++k){
            if(binary_search(two.begin(), two.end(), arr[l]-arr[k])){
                std::cout << arr[l];
                return 0;
            }
        }
    }

    return 0;
}