#백준, 13265 색칠하기

import sys
from collections import deque
input = sys.stdin.readline

def bfs(v):
    Q.append(v)
    visited[v] = 1
    color[v] = 1

    while Q:
        node = Q.popleft()
        
        for i in range(len(graph[node])):
            next = graph[node][i]
            if visited[next] == 0:
                visited[next] = 1
                color[next] = 2 if color[node] == 1 else 1
                Q.append(next)
            
            if visited[next] == 1 and color[node] == color[next]:
                return False
    return True

T = int(input())

for _ in range(T):
    N, M = map(int, input().rstrip().split())
    graph = [[] for _ in range(N+1)]
    color = [0 for _ in range(N+1)]
    visited = [0 for _ in range(N+1)]
    
    Q = deque()

    for i in range(M):
        a, b = map(int, input().rstrip().split())
        graph[a].append(b)
        graph[b].append(a)
    
    flag = False

    if not bfs(1):
        flag = True
    
    if not flag:
        for i in range(len(color)):
            if color[i] == 0:
                if not bfs(i):
                    flag = True
                    break
    
    print("possible") if flag == False else print("impossible")