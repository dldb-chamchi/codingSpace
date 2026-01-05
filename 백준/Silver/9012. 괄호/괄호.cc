#include <iostream>
#include <stack>
//using namespace std;

int main() {
	int N;
	std::cin >> N;
	
	while(N--) {
		std::stack<char> stack;
		std::string string;

		std::cin >> string;

		for(int i{0}; i<string.length(); ++i){
			if(!stack.empty() && stack.top() == '(' && string[i] == ')') stack.pop();
			else stack.push(string[i]);
		}

		std::cout << (stack.empty() ? "YES" : "NO") << '\n';
	}

	return 0;
}