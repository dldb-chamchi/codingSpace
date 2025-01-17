//백준 2941, 크로아티아 알파벳
#include <iostream>

int main(){
    std::string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    std::string s;
    std::cin >> s;

    for(int i{0}; i<8; ++i){
        while(true){
            int idx = s.find(alpha[i]);
            if(idx == std::string::npos) break;
            s.replace(idx, alpha[i].size(), "#");
        }
    }

    std::cout << s.size();

    return 0;
}