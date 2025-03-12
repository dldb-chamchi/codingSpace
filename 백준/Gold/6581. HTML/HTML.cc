#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string s;
    int sum = 0;

    while (std::getline(std::cin, s)) {
        std::istringstream iss(s);
        std::string word;

        while (iss >> word) {
            if (word == "<br>") {
                std::cout << '\n';
                sum = 0;  // 줄바꿈 후 sum 초기화
            } 
            else if (word == "<hr>") {
                if (sum > 0) std::cout << '\n';  // 현재 줄에 내용이 있다면 개행
                std::cout << "--------------------------------------------------------------------------------\n";
                sum = 0;  // 줄바꿈 후 sum 초기화
            } 
            else {
                if (sum + word.size() + (sum > 0 ? 1 : 0) > 80) {  // 공백 고려하여 80자 초과 확인
                    std::cout << '\n';
                    sum = 0;
                }
                if (sum > 0) std::cout << ' ';  // 줄의 시작이 아니라면 공백 추가
                std::cout << word;
                sum += word.size() + (sum > 0 ? 1 : 0);  // 단어 길이 + 공백 고려
            }
        }
    }

    return 0;
}
