#include <iostream>
#include <string>
//using namespace std;

bool numPool[1'001];

void generate() {
	for(int i{123}; i<=987; ++i){
		std::string num = std::to_string(i);
		if(num[0] == '0' || num[1] == '0' || num[2] == '0') numPool[i] = false;
		else if(num[0] == num[1] || num[1] == num[2] || num[0] == num[2]) numPool[i] = false;
		else numPool[i] = true;
	}
}

void check(std::string_view n, int st, int ba) {
	for(int i{123}; i<=987; ++i) {
		std::string num = std::to_string(i);
		int s{0}, b{0};
		if (numPool[i]) {
			for(int j{0}; j<3; ++j) {
				for(int k{0}; k<3; ++k) {
					if(j == k && n[j] == num[k]) ++s;
					else if(j != k && n[j] == num[k]) ++b;
				}
			}
			if (st != s || ba != b) numPool[i] = false; 
		}
	}
}

int main() {
	
	int N, num, strike, ball;
	std::cin >> N;

	generate();

	while(N--) {
		std::cin >> num >> strike >> ball;
		check(std::to_string(num), strike, ball);
	}
	
	int cnt{0};
	for(int i{123}; i<=987; ++i) {
		if (numPool[i]) ++cnt;
	}

	std::cout << cnt;

	return 0;
}