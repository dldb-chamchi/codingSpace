#include <iostream>
//using namespace std;

int main() {

	int N;
	int cnt{0};

	std::cin >> N;

	while (N >= 0) {
		if (N%5 == 0) {
			cnt += (N/5);
			std::cout << cnt;
			return 0;
		}
		N -= 3;
		++cnt;
	}
	
	std::cout << -1;

	return 0;
}