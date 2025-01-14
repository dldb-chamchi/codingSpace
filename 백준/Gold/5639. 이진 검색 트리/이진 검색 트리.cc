//백준 5639, 이진검색트리

#include <iostream>
#include <vector>

std::vector<int> node;

void recur(int start, int end){
    if(start >= end) return;
    int i;
    for(i = start+1; i<end; ++i){
        if(node[start] < node[i]) break;
    }
    recur(start+1, i);
    recur(i, end);
    std::cout << node[start] << '\n';
}


int main(){
    int n;
    while(std::cin >> n){
        node.push_back(n);
    }

    recur(0, node.size());

    return 0;
}