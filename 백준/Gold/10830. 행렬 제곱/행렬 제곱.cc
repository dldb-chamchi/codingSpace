#include <iostream>
using ll = long long;

int N;
ll B;
ll matrix1[5][5]; // 원 행렬
ll matrix2[5][5]; // 결과 행렬

// 행렬 곱셈 함수
void multiply(const ll A[5][5], const ll B[5][5], ll result[5][5]) {
    ll tmp[5][5] = {0};  // 임시 행렬 (연산 중 직접 변경 방지)

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ll sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += (A[i][k] * B[k][j]) % 1000;
            }
            tmp[i][j] = sum % 1000;  // 1000으로 나눈 나머지 저장
        }
    }

    // 결과 복사
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = tmp[i][j];
        }
    }
}

// 분할 정복을 이용한 행렬 거듭제곱
void recur(ll b) {
    if (b == 1) {
        return;
    }

    recur(b / 2);
    ll tmp[5][5];
    multiply(matrix2, matrix2, tmp);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix2[i][j] = tmp[i][j];
        }
    }

    if (b % 2 != 0) {  // b가 홀수라면 추가 곱셈 수행
        multiply(matrix2, matrix1, tmp);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix2[i][j] = tmp[i][j];
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N >> B;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix1[i][j];
            matrix1[i][j] %= 1000;  // 입력값을 1000으로 나눈 나머지 저장
            matrix2[i][j] = matrix1[i][j];
        }
    }

    recur(B);

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix2[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
