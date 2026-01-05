#include <iostream>
#include <stack>

std::string s;
int cnt;

int solve(){

	if (s.length() % 2 != 0) return 0;
	std::stack<char> stack;

	for (int i{0}; i<s.length(); ++i) {
		if (!stack.empty() && s[i] == stack.top()) stack.pop();
		else stack.push(s[i]); 
	}

	return stack.empty() ? 1 : 0;

}

int main() {
	
	int N;
	std::cin >> N;

	while(N--){
		
		std::cin >> s;
		cnt += solve();
	}

	std::cout << cnt;

	return 0;
}