//백준 2869, 달팽이는 올라가고 싶다
#include <iostream>

int main(){
    int A, B, V;
    
    std::cin >> A >> B >> V;

    int goal = V - A;
    int time = A - B;
    int ans{0};
    if(goal % time != 0) ++ans;
    ans += goal / time;
    std:: cout << ans+1;

    return 0;
}