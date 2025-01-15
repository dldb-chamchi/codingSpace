//통계학
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <vector>

int arr[500'000];
std::unordered_map<int, int> freq;
int N;

int mostFreq(){
    int max{0};
    std::vector<int> keys;
    for(const auto& [key, value] : freq){
        max = std::max(max, value);
    }

    for(const auto& [key, value] : freq){
        if(value == max) keys.push_back(key);
    }

    std::sort(keys.begin(), keys.end());
    return keys.size() == 1 ? keys[0] : keys[1];
}


int main(){

    std::cin >> N;
    double sum{0};
    for(int i{0}; i<N; ++i){
        std::cin >> arr[i];
        sum += arr[i];
        if(freq.find(arr[i]) != freq.end()) ++freq[arr[i]];
        else freq[arr[i]] = 1;
    }

    std::cout << round(sum / N) + 0.0 << '\n';
    std::sort(arr, arr+N);
    std::cout << arr[N/2] << '\n';
    std::cout << mostFreq() << '\n';
    std::cout << arr[N-1] - arr[0];

    return 0;
}