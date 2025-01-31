#include <iostream>

int A[500'001];
int tmp[500'001];
int cnt{0};
int N, K;
bool flag = false;

void merge(int p, int q, int r){

	int i = p; int j = q + 1; int t = 1;
	while(i <= q && j <= r){
	
		if(A[i] <= A[j]) tmp[t++] = A[i++];
		else tmp[t++] = A[j++];
	}

	while(i <= q) tmp[t++] = A[i++];
	
	while(j <= r) tmp[t++] = A[j++];
	
	i = p; t = 1;

	while(i <= r){
		A[i++] = tmp[t++];
		++cnt;
		if(cnt == K){			
            std::cout << A[i - 1];
			flag = true;
			return;
		}
	}
}

void merge_sort(int p, int r){

	if(p < r){
		int q = (p+r)/2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main(void){
	std::cin >> N >> K;

	for (int i = 0; i < N; i++) std::cin >> A[i];
	
	merge_sort(0, N-1);

	if(!flag) std::cout << -1;

	return 0;
}