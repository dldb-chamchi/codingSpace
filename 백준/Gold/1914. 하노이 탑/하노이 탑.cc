//백즌 1914, 하노이 탑

#include <iostream>
#include <cmath>

void recur(int n, int a, int b){
    if(n == 1){
        std::cout << a << ' ' << b << '\n';
        return;
    }
    
    recur(n-1, a, 6-a-b);
    std::cout << a << ' ' << b << '\n';
    recur(n-1, 6-a-b, b);
}

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::string s = std::to_string(pow(2, N));
	
	int x = s.find('.');	
	s = s.substr(0, x);	
	s[s.length() - 1] -= 1;	        
    
    std::cout << s << "\n";
    if(N <= 20) recur(N, 1, 3);
    return 0;
}