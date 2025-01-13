//백준 9934, 완전 이진 트리  

#include <iostream>
#include <vector>

std::vector<std::vector<int>> level;

int k;
int tree[1050];
void recur(int start, int end, int depth){
    if(start > end) return;
    int mid = (start + end) / 2;
    
    level[depth].push_back(tree[mid]);
    
    recur(start, mid-1, depth+1);
    recur(mid+1, end, depth+1);
    
}

int main(){
    std::cin >> k;
    int size = (1<<k)-1;
    for(int i{0}; i<size; ++i){
        std::cin >> tree[i];
    }
    level.resize(k); //resize 해야함
    
    recur(0, size-1, 0);
    
    for(int i{0}; i<k; ++i){
        for(auto l : level[i]){
            std::cout << l << ' ';
        }
        std::cout << '\n';
    }
    
    
    
    return 0;
}