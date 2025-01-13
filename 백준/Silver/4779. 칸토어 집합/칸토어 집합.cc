
#include <iostream>
#include <cmath>

int n;
char line[560000];

void solve(int n, int start, int end){
    if(n == 0) return;
    int len = (end-start+1) / 3;
    for(int i{start + len}; i<start+2*len; ++i) line[i] = ' ';
    solve(n-1, start, start+len-1);
    solve(n-1, start+2*len, end);
}

int main(){
    while(std::cin >> n){
        int size = pow(3, n);
        for(int i{0}; i<size; ++i) line[i] = '-';
        solve(n, 0, size-1);
        for(int i{0}; i<size; ++i) std::cout << line[i];
        std::cout << '\n';
    }

    

    return 0;
}