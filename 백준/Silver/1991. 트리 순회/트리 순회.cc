//백준 1991, 트리 순회

#include <iostream>

int n;
char tree[100][3];

void preorder(int idx){
    if(tree[idx][0] ==  '.') return;
    std::cout << tree[idx][0];
    if(tree[idx][1] != '.') preorder(tree[idx][1] - 'A');
    if(tree[idx][2] != '.') preorder(tree[idx][2] - 'A');
}

void inorder(int idx){
    if(tree[idx][0] ==  '.') return;
    if(tree[idx][1] != '.') inorder(tree[idx][1] - 'A');
    std::cout << tree[idx][0];
    if(tree[idx][2] != '.') inorder(tree[idx][2] - 'A');
}

void postorder(int idx){
    if(tree[idx][0] ==  '.') return;
    if(tree[idx][1] != '.') postorder(tree[idx][1] - 'A');
    if(tree[idx][2] != '.') postorder(tree[idx][2] - 'A');
    std::cout << tree[idx][0];
}

int main(){
    
    std::cin >> n;
    
    for(int i{0}; i<n; ++i){
        char parent, left, right;
        std::cin >> parent >> left >> right;
        int idx = parent - 'A';
        tree[idx][0] = parent;
        tree[idx][1] = left;
        tree[idx][2] = right;
        
    }
    preorder(0); std::cout << '\n';
    inorder(0); std::cout << '\n';
    postorder(0);
    
    
    return 0;
}