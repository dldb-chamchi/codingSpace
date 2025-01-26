//백준 18870, 좌표 압축

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int arr[1'000'000];
int copy[1'000'000];
std::vector<int> sorted;
int N;
std::set<int> set;

void bs(int i){
    int st{0}; int end = sorted.size();
    while(st < end){
        int mid = (st+end) / 2;
        if(sorted[mid] >= arr[i]) end = mid;
        else st = mid +1;  
    }
    std::cout << st << ' ';
}

int main (){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    for(int i{0}; i<N; ++i) std::cin >> arr[i];
    std::copy(arr, arr+N, copy);
    for(int i{0}; i<N; ++i){
        set.insert(copy[i]);
    }

    for(auto n : set){
        sorted.push_back(n);
    }

    std::sort(sorted.begin(), sorted.end());

    for(int i{0}; i<N; ++i){
        bs(i);
    }

    return 0;
}