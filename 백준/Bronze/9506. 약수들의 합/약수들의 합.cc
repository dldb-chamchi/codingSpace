//백준 9506, 약수들의 합
#include <iostream>
#include <vector>

std::vector<int> vec;

int main(){

    int n;
    while(true){
        std::cin >> n;
        if(n == -1) break;
        int i{1}; int sum{0};
        while(n > i){
            if(n%i == 0){
                sum += i;
                vec.push_back(i);
            }
            ++i;
        }
        if(sum == n){
            std::cout << n << " = ";
            std::cout << vec[0];
            for(int i{1}; i<vec.size(); ++i){
                std::cout << " + " << vec[i];
            }
            std::cout << '\n';
        }
        else std::cout << n << " is NOT perfect.\n";
        vec.clear();
    }

    return 0;
}