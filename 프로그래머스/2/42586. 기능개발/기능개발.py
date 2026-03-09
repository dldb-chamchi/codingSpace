from collections import deque

def solution(progresses, speeds):
    answer = []
    Q = deque(progresses)
    S = deque(speeds)
    
    while Q:
        for s in S:
            p = Q.popleft()
            p += s
            Q.append(p)
        
        cnt = 0
        
        while Q:
            p = Q.popleft()
            if p >= 100:
                cnt += 1
                S.popleft()
            else:
                Q.appendleft(p)
                break
        if cnt >= 1:
            answer.append(cnt)
    return answer