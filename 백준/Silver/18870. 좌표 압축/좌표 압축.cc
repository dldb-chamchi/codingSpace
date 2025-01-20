#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    // 정렬 및 중복 제거를 위한 복사본 생성
    std::vector<int> sortedNums(nums);
    std::sort(sortedNums.begin(), sortedNums.end());
    sortedNums.erase(std::unique(sortedNums.begin(), sortedNums.end()), sortedNums.end());

    // 좌표 압축을 위한 매핑 생성
    std::unordered_map<int, int> coordMap;
    for (int i = 0; i < sortedNums.size(); ++i) {
        coordMap[sortedNums[i]] = i;
    }

    // 좌표 압축 결과 출력
    for (int i = 0; i < N; ++i) {
        std::cout << coordMap[nums[i]] << " ";
    }

    return 0;
}
