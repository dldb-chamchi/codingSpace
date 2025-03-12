//백준 5904, Moo 게임

#include <iostream>

int N;

char recur(int n, int k, int len){

    int newLen = len*2 + k+3;

    if(n == 1) return 'm';
    else if(n == 2 || n == 3) return 'o';
    else{
        if(newLen < n) return recur(n, k+1, newLen);
        else if(n > len && n <= len+k+3) return n - len == 1 ? 'm' : 'o';
        else return recur(n-(len+k+3), 1, 3);
    }
}

int main (){

    std::cin >> N;
    std::cout << recur(N, 1, 3);

    return 0;
}