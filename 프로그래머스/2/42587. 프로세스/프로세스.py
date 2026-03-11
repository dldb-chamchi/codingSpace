from collections import deque
import heapq

def solution(priorities, location):
    answer = 0
    
    Q = deque()
    idx = 0
    for n in priorities:
        Q.append((n, idx))
        idx += 1
    
    pq = []
    
    for n in priorities:
        heapq.heappush(pq, -n)
    
    while Q:
        p, i = Q.popleft()
        if p == -pq[0]:
            answer += 1
            if i == location:
                return answer
            heapq.heappop(pq)
        else:
            Q.append((p, i))
        