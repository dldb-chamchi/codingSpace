# 16958번 텔레포트
# 그래프 이론, 그래프 탐색, 플로이드-워셜

import sys
input = sys.stdin.readline
from itertools import *

INF = 10000
N, T = map(int, input().rstrip().split())
nodes = []
for _ in range(N):
    s, x, y = map(int, input().rstrip().split())
    nodes.append([s, x, y])
graph = [[INF for _ in range(N)] for _ in range(N)]

for i, j in combinations(range(N), 2):
    manhattan_distance = abs(nodes[i][1]-nodes[j][1]) + abs(nodes[i][2]-nodes[j][2])
    graph[i][j] = manhattan_distance
    graph[j][i] = manhattan_distance
    if nodes[i][0] and nodes[j][0] and T < manhattan_distance:
        graph[i][j] = T
        graph[j][i] = T

for k in range(N):
    for i in range(N):
        for j in range(N):
            if graph[i][k] + graph[k][j] < graph[i][j]:
                graph[i][j] = graph[i][k] + graph[k][j]

M = int(input())
for _ in range(M):
    start, end = map(int, input().rstrip().split())
    print(graph[start-1][end-1])