//백준 1629, 곱셈

#include <iostream>

long long A, B, C;

long long recur(long long b){
    if(b == 1) return A%C;
    long long pow = recur(b/2)%C;
    if(b % 2 != 0) return ((pow * pow) % C * A) % C;
    else return (pow * pow)%C;
}

int main (){

    std::cin >> A >> B >> C;
    std::cout << recur(B);

    return 0;
}