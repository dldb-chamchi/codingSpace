#백준 8625, BABBA

K = int(input())

'''
1 0
0 1
1 2
2 3
3 5
5 8

BABBABAB
BABBABABBABBA

'''

A = [1, 0, 1]
B = [0, 1, 1]

for i in range(3, K+1):
    A.append(B[i-1])
    B.append(A[i-1] + B[i-1])

print(A[K], B[K])
