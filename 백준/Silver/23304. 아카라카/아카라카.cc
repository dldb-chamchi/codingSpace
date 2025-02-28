//백준 23304, 아카라카

#include <iostream>

std::string s;

bool recur(int st, int end, int k){
    if(k==1) return true;

    for(int i{st}; i<k/2; ++i){ //st포함 end 미포함
        if(s[i]!=s[end-i-1]) return false;
    }

    if(s.length()%2 !=0){
        return recur(0, end/2, k/2) && recur(end/2+1, end, k/2);
    }

    else{
        return recur(0, end/2, k/2) && recur(end/2, end, k/2);
    }

}

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> s;
    
    if(recur(0, s.length(), s.length())) std::cout << "AKARAKA";
    else std::cout << "IPSELENTI";
    

    return 0;
}