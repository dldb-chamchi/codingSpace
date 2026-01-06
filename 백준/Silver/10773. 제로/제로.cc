#include <iostream>
#include <deque>

int main() {
	int K, n;
	std::deque<int> stack;

	std::cin >> K;

	while(K--) {
		std::cin >> n;
		if (n == 0) stack.pop_back();
		else stack.push_back(n);
	}

	int sum{0};

	for(auto &num : stack) {
		sum += num;
	}

	std::cout << sum;

	return 0;
}